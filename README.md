# Soccer

Soccer is a 19th generation password expander for offline file encryption,
developed by a cryptography-focused engineer with 16 years of experience and
about 10 months of concentrated work on this design.

The proposal is that Soccer is many thousands of times stronger than AES for
its intended offline password-encryption role, because each password attempt
is deliberately expensive and expands into a large encryption state. That
said, Soccer is not battle tested. It should be studied, attacked, benchmarked,
and reviewed before anyone treats it like established cryptographic
infrastructure.

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/image.png)

## `secure.test.encrypted` challenge

The repository includes `secure.test.encrypted` as a public crack challenge. Whoever
cracks it first gets their choice:

**Disclaimer:** The challenge does not go live until 2027. I am giving myself
time to find and fix any remaining bugs or oversights; however, the challenge
is unlikely to change at this point.

- Choice A: $10,000 USD
- Choice B: $5,000 and their name tattooed on my right forearm (up to 15 small
  characters or 5 large characters)

The challenge file uses this nonce:

```cpp
98765432123456789
```

The ack word is provided so password attempts can fail early when the
password is wrong:

```cpp
0xFB47B0AB
```

This challenge expires at the end of the year 2029, in the EST time zone.

This challenge was generated with my network card unplugged. I generated the challenge, moved it onto an external hard-drive, then factory reset my Mac. Both OS instances used FileVault. So, there should be no public timeline of the encryption event.

## Encrypt and decrypt one block

This example encrypts the string `Hello, Soccer!` inside one zero-padded L3
block, prints the first 64 encrypted bytes, then decrypts the block and prints
the recovered string.

### 1.) Seed

```cpp
#include "Soccer.hpp"

#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

const std::uint64_t aNonce = 0xF00DFACECAFEBEEFULL;
const std::string aPassword = "readme-password";

std::vector<std::uint8_t> aPasswordBytes(aPassword.begin(), aPassword.end());
std::vector<std::uint8_t> aOriginal(SOCCER_BLOCK_SIZE, 0U);

const std::string aMessage = "Hello, Soccer!";
std::memcpy(aOriginal.data(), aMessage.data(), aMessage.size());

// Encrypt generates the aAckWord. You need this to decrypt.
std::uint32_t aAckWord = 0U;
if (!Soccer::AttemptSeed_Encrypt(aPasswordBytes.data(),
                                 aPasswordBytes.size(),
                                 aNonce,
                                 &aAckWord)) {
    std::printf("Failed to seed encryption\n");
    return false;
}
```

### 2.) Encrypt

```cpp
// Encrypt in 1MB sized blocks.
std::vector<std::uint8_t> aEncrypted(SOCCER_BLOCK_SIZE, 0U);
if (!Soccer::EncryptBlock(aOriginal.data(), aEncrypted.data())) {
    std::printf("Failed to encrypt block\n");
    return false;
}

// Print the encrypted data.
std::printf("Encrypted first 64 bytes:\n");
for (std::size_t aIndex = 0U; aIndex < 64U; aIndex += 1U) {
    std::printf("%02X%s",
                aEncrypted[aIndex],
                ((aIndex + 1U) % 16U == 0U) ? "\n" : " ");
}
```

### 3.) Decrypt

```cpp
std::vector<std::uint8_t> aUnencrypted(SOCCER_BLOCK_SIZE, 0U);
if (!Soccer::AttemptSeed_Decrypt(aPasswordBytes.data(),
                                 aPasswordBytes.size(),
                                 aNonce,
                                 aAckWord)) {
    std::printf("Failed to seed decryption\n");
    return false;
}

if (!Soccer::DecryptBlock(aEncrypted.data(), aUnencrypted.data())) {
    std::printf("Failed to decrypt block\n");
    return false;
}

// Print the decrypted data.
const std::string aRecovered(reinterpret_cast<const char *>(aUnencrypted.data()),
                             aMessage.size());
std::printf("Unencrypted: %s\n", aRecovered.c_str());
```

When encrypting, store the nonce and the ack word with the ciphertext.
The same nonce is required for decryption, and the ack word lets Soccer stop
early when the password is wrong. This matters because seeding is deliberately
expensive and can take about 40 seconds.

## Example of Soccer process:

### L3

```text
Apply key 100100111000010100011011001101100001001010011100 at size L3.
Rotate by 628478 every bit matching mask 10100100 wrapping @ block size L3.
Apply key 010101010101000101101111001010110101101001010100 at size L3.
Rotate by 878516 every bit matching mask 00101100 wrapping @ block size L3.
```

### L2

```text
Apply key 111111100011111010111001001001011001000111110100 at size L2.
Rotate by 332374 every bit matching mask 00110011 wrapping @ block size L2.
Apply key 101101001011100100110110011000011001110001001010 at size L2.
Rotate by 489449 every bit matching mask 00111000 wrapping @ block size L2.
```

### L1

```text
Apply key 110011011011010101101101000110000010100001100010 at size L1.
Rotate by 72731 every bit matching mask 00100101 wrapping @ block size L1.
Apply key 101001010110010011001001010001011011001111001110 at size L1.
Rotate by 245208 every bit matching mask 11000001 wrapping @ block size L1.
```

### Final L3

```text
Apply key 000001011001011000101000110110111001000101101011 at size L3 (final).
Rotate by 717233 every bit matching mask 01000110 wrapping @ block size L3 (final).
Apply key 001001110010111011011101111001001010101110011011 at size L3 (final).
Rotate by 1007156 every bit matching mask 01010010 wrapping @ block size L3 (final).
```

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/KDFA.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/KDFB.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/SEED_1.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/SEED_2.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/TWIST_1.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/TWIST_2.png)

## Static library builds

The portable build is driven by CMake and exports a static library target named
`soccer`. The installed library is still `libsoccer`.

To build the release folders available on the current machine:

```
./build.sh
```

This script writes:

```
release/libsoccer-Mac
release/libsoccer-Linux
release/libsoccer-Win64
```

The Mac build runs on macOS. The Linux and Win64 builds require either those
native platforms or matching cross-toolchains. For custom cross-toolchains, set
`SOCCER_LINUX_TOOLCHAIN_FILE` or `SOCCER_WIN64_TOOLCHAIN_FILE`.

To fail unless all three targets are actually built:

```
./build.sh --require-all
```

Public headers are installed to:

```
include/soccer
```

`Soccer.hpp` is the public header. The expander and encrypter implementation
headers are private build details.

Build on macOS or Linux:

```
cmake -S . -B build/cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build/cmake --config Release
cmake --install build/cmake --prefix dist/libsoccer
```

Build a universal macOS library:

```
cmake -S . -B build/cmake-macos-universal -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"
cmake --build build/cmake-macos-universal --config Release
cmake --install build/cmake-macos-universal --prefix dist/libsoccer
```

Build on Windows with MSVC x64:

```
cmake -S . -B build/cmake-msvc-x64 -G "Visual Studio 17 2022" -A x64
cmake --build build/cmake-msvc-x64 --config Release
cmake --install build/cmake-msvc-x64 --config Release --prefix dist/libsoccer
```

By default the Windows build uses the MSVC DLL runtime (`/MD`). To build a
static runtime (`/MT`) variant:

```
cmake -S . -B build/cmake-msvc-x64-mt -G "Visual Studio 17 2022" -A x64 -DSOCCER_MSVC_STATIC_RUNTIME=ON
cmake --build build/cmake-msvc-x64-mt --config Release
cmake --install build/cmake-msvc-x64-mt --config Release --prefix dist/libsoccer
```

Typical output library names:

```
macOS:   libsoccer.a
Linux:   libsoccer.a
Windows: soccer.lib
```

Build one library per operating system, architecture, and compiler/runtime
combination you want to support. For Windows, start with x64 MSVC unless you
specifically need ARM64 Windows, 32-bit Windows, or MinGW.

```
Nonce avalanche original vs bit 24: 49.956024% (4190615 / 8388608 bits)
Nonce avalanche original vs bit 25: 49.994051% (4193805 / 8388608 bits)
Nonce avalanche original vs bit 26: 50.000226% (4194323 / 8388608 bits)
Nonce avalanche original vs bit 27: 49.993443% (4193754 / 8388608 bits)
Nonce avalanche original vs bit 28: 49.984026% (4192964 / 8388608 bits)
Nonce avalanche original vs bit 29: 49.992621% (4193685 / 8388608 bits)
Nonce avalanche original vs bit 30: 49.994504% (4193843 / 8388608 bits)
Nonce avalanche original vs bit 31: 50.023854% (4196305 / 8388608 bits)
Nonce avalanche bit 24 vs bit 25: 49.988365% (4193328 / 8388608 bits)
Nonce avalanche bit 24 vs bit 26: 50.036812% (4197392 / 8388608 bits)
Nonce avalanche bit 24 vs bit 27: 49.996841% (4194039 / 8388608 bits)
Nonce avalanche bit 24 vs bit 28: 49.997580% (4194101 / 8388608 bits)
Nonce avalanche bit 24 vs bit 29: 49.998164% (4194150 / 8388608 bits)
Nonce avalanche bit 24 vs bit 30: 50.011921% (4195304 / 8388608 bits)
Nonce avalanche bit 24 vs bit 31: 49.994373% (4193832 / 8388608 bits)
Nonce avalanche bit 25 vs bit 26: 50.001049% (4194392 / 8388608 bits)
Nonce avalanche bit 25 vs bit 27: 49.995697% (4193943 / 8388608 bits)
Nonce avalanche bit 25 vs bit 28: 50.006139% (4194819 / 8388608 bits)
Nonce avalanche bit 25 vs bit 29: 50.012255% (4195332 / 8388608 bits)
Nonce avalanche bit 25 vs bit 30: 50.016069% (4195652 / 8388608 bits)
Nonce avalanche bit 25 vs bit 31: 49.998832% (4194206 / 8388608 bits)
Nonce avalanche bit 26 vs bit 27: 49.996340% (4193997 / 8388608 bits)
Nonce avalanche bit 26 vs bit 28: 49.982321% (4192821 / 8388608 bits)
Nonce avalanche bit 26 vs bit 29: 49.996591% (4194018 / 8388608 bits)
Nonce avalanche bit 26 vs bit 30: 49.982834% (4192864 / 8388608 bits)
Nonce avalanche bit 26 vs bit 31: 50.017691% (4195788 / 8388608 bits)
Nonce avalanche bit 27 vs bit 28: 49.994922% (4193878 / 8388608 bits)
Nonce avalanche bit 27 vs bit 29: 49.973309% (4192065 / 8388608 bits)
Nonce avalanche bit 27 vs bit 30: 50.007665% (4194947 / 8388608 bits)
Nonce avalanche bit 27 vs bit 31: 49.993837% (4193787 / 8388608 bits)
Nonce avalanche bit 28 vs bit 29: 50.013006% (4195395 / 8388608 bits)
Nonce avalanche bit 28 vs bit 30: 49.995482% (4193925 / 8388608 bits)
Nonce avalanche bit 28 vs bit 31: 50.002015% (4194473 / 8388608 bits)
Nonce avalanche bit 29 vs bit 30: 49.998808% (4194204 / 8388608 bits)
Nonce avalanche bit 29 vs bit 31: 50.014591% (4195528 / 8388608 bits)
Nonce avalanche bit 30 vs bit 31: 50.028539% (4196698 / 8388608 bits)
```

```
Password avalanche original A vs bit 0: 49.983025% (4192880 / 8388608 bits)
Password avalanche original A vs bit 1: 50.006831% (4194877 / 8388608 bits)
Password avalanche original A vs bit 2: 49.962914% (4191193 / 8388608 bits)
Password avalanche original A vs bit 3: 50.013781% (4195460 / 8388608 bits)
Password avalanche original A vs bit 4: 49.997497% (4194094 / 8388608 bits)
Password avalanche original A vs bit 5: 49.989164% (4193395 / 8388608 bits)
Password avalanche original A vs bit 6: 50.022852% (4196221 / 8388608 bits)
Password avalanche original A vs bit 7: 50.021303% (4196091 / 8388608 bits)
Password avalanche bit 0 vs bit 1: 49.962556% (4191163 / 8388608 bits)
Password avalanche bit 0 vs bit 2: 50.019085% (4195905 / 8388608 bits)
Password avalanche bit 0 vs bit 3: 49.990082% (4193472 / 8388608 bits)
Password avalanche bit 0 vs bit 4: 50.009441% (4195096 / 8388608 bits)
Password avalanche bit 0 vs bit 5: 50.013101% (4195403 / 8388608 bits)
Password avalanche bit 0 vs bit 6: 50.002563% (4194519 / 8388608 bits)
Password avalanche bit 0 vs bit 7: 50.001061% (4194393 / 8388608 bits)
Password avalanche bit 1 vs bit 2: 50.002217% (4194490 / 8388608 bits)
Password avalanche bit 1 vs bit 3: 49.987686% (4193271 / 8388608 bits)
Password avalanche bit 1 vs bit 4: 49.984634% (4193015 / 8388608 bits)
Password avalanche bit 1 vs bit 5: 49.983525% (4192922 / 8388608 bits)
Password avalanche bit 1 vs bit 6: 50.002789% (4194538 / 8388608 bits)
Password avalanche bit 1 vs bit 7: 50.008035% (4194978 / 8388608 bits)
Password avalanche bit 2 vs bit 3: 50.014412% (4195513 / 8388608 bits)
Password avalanche bit 2 vs bit 4: 50.002420% (4194507 / 8388608 bits)
Password avalanche bit 2 vs bit 5: 50.015664% (4195618 / 8388608 bits)
Password avalanche bit 2 vs bit 6: 50.005460% (4194762 / 8388608 bits)
Password avalanche bit 2 vs bit 7: 49.998927% (4194214 / 8388608 bits)
Password avalanche bit 3 vs bit 4: 49.988246% (4193318 / 8388608 bits)
Password avalanche bit 3 vs bit 5: 49.999177% (4194235 / 8388608 bits)
Password avalanche bit 3 vs bit 6: 49.973667% (4192095 / 8388608 bits)
Password avalanche bit 3 vs bit 7: 50.019515% (4195941 / 8388608 bits)
Password avalanche bit 4 vs bit 5: 49.999273% (4194243 / 8388608 bits)
Password avalanche bit 4 vs bit 6: 49.990404% (4193499 / 8388608 bits)
Password avalanche bit 4 vs bit 7: 49.977243% (4192395 / 8388608 bits)
Password avalanche bit 5 vs bit 6: 49.972177% (4191970 / 8388608 bits)
Password avalanche bit 5 vs bit 7: 49.976540% (4192336 / 8388608 bits)
Password avalanche bit 6 vs bit 7: 50.004935% (4194718 / 8388608 bits)
```

## License

Soccer is available under the
[PolyForm Noncommercial License 1.0.0](LICENSE.md). You may use, study, modify,
and redistribute the software for noncommercial purposes. Commercial use,
including selling the software or derivatives, is not permitted under this
license.

## How the ARX loop recipes are farmed

Soccer's generated ARX loops are assembled from three independently saved
structural pieces:

```text
head + heart + tail = loop recipe
```

- The **head** assigns one of the eleven wanderers A-K to initialize each of
  the eleven orbiters A-K.
- The **heart** is the ordered eleven-round ARX dance between those orbiters.
- The **tail** selects two orbiters to feed back into each wanderer update.

These assets contain structure, not keys or secret data. Farming them is a
search for well-connected and varied information-flow plans. It is not a
cryptographic proof, and it deliberately does not grade ciphertext bit
balance, empirical avalanche, constants, rotations, salts, or nonce values.
Those belong to other parts of the construction and to separate testing.

### The structural model

For scoring, every starting wanderer and every fresh context input is given a
symbolic dependency marker. When two values interact, their marker sets are
joined. This lets the farmer follow where information *could* travel without
pretending to predict the numerical output of the real ARX arithmetic.

A simplified journey through one loop is:

```text
wanderers
    -> head assignments and context injection
    -> orbiters
    -> eleven ordered heart rounds
    -> two tail-selected orbiters per wanderer
    -> updated wanderers, ingress, and carry
    -> next iteration
```

The simulation runs this complete route twice. Consequently, the principal
tail score is not just a property of an isolated graph: it follows each
wanderer's influence into the orbiters, through the ordered ARX heart, back
through the tail, and into the updated wanderers.

### Heart farming

Each heart has eleven ordered triplets:

```text
{ lead, source, feedback }
```

One triplet represents the structural roles in a real ARX statement group:

```cpp
lead = lead + source;
feedback = feedback ^ lead;
feedback = rotate_and_finalize(feedback);
```

The real generated statements also contain constants and other inputs. The
heart records only which abstract role leads, supplies the source, and receives
feedback in each ordered round.

#### From six skeletons to 180 hearts

The earlier generator used six fixed eleven-round skeletons. Concrete orbiter
names could be permuted around those skeletons, producing many-looking loops,
but a global rename does not create a new information-flow topology. Under the
later canonical definition, globally swapping roles such as A and D leaves the
same heart.

The 180-heart system revisited that foundation. It did not make 30 renamed
versions of each old skeleton. Instead, it searched a much larger canonical
space and treated role-renamed copies as one candidate. The old six were the
prototype that established the eleven-round, three-role heart; the new 180 are
independently selected structural replacements that give the recipe system 180
different canonical ordered-heart structures.

Every candidate uses each role A-K exactly once in each of the `lead`, `source`,
and `feedback` columns. The roles within a row also obey the accepted cyclic
gap families `{2, 4, 5}` or `{3, 3, 5}`, which keep the three participants from
clustering together. The saved search evaluated 2,667,804 canonical candidates,
257,350 passed the immediate structural filters, and the strongest 180 were
kept.

#### Heart eligibility and metrics

The following measurements were considered. Hard failures were removed before
ranking; the remaining metrics were compared in the order shown.

| Metric | Preference | Plain-language meaning |
| --- | :---: | --- |
| Eligibility | Required | A candidate that fails any immediate graph rule cannot outrank an eligible candidate. |
| Distinct directed edges | Higher | Rewards using more different one-way relationships instead of repeating the same interaction. The eleven triplets can supply at most 22. |
| Reciprocal edges | Lower | Avoids immediately reusing the same relationship in both directions. |
| Strong connectivity | Required | Starting from any role, information must have a directed route to every other role. |
| Articulation points | Zero required | Removing one role must not split the undirected flow graph. This rejects single-role bottlenecks. |
| Bridges | Zero required | Removing one relationship must not split the undirected graph. This rejects single-edge bottlenecks. |
| Floor balance | Higher | Takes the weaker of two worst cases: the least-informed destination and the least-travelled source. It prevents excellent flow in one direction from hiding weak flow in the other. |
| Floor total | Higher | Adds those incoming and outgoing floors after their balance has been protected. |
| Journey balance | Higher | Takes the weaker of the incoming and outgoing journey scores, which reward early and sustained influence during the ordered rounds. |
| Journey total | Higher | Adds the incoming and outgoing journey scores after their balance has been protected. |
| Influence-curve area | Higher | Adds the dependency reach after every round, rewarding flow that spreads early rather than arriving only at the end. |
| Final influence total | Higher | Counts the total dependency reach present after all eleven rounds. |
| Directed diameter | Lower | Measures the worst shortest route between two roles. A diameter of four means every role can reach every other in at most four directed steps. |

Heart sorting is **lexicographic**, not a weighted sum. The first metric that
differs decides the comparison. Thus a later excellent score cannot compensate
for an earlier structural weakness. When all score fields tie, the canonical
heart bytes provide a deterministic final ordering.

### Head farming

A head is a permutation of A-K. For example, `A<-K` means that orbiter A is
initialized from wanderer K. Because every wanderer appears exactly once, a
head redistributes roles without duplicating or omitting one.

There are `11! = 39,916,800` possible heads. A deterministic preselection keeps
the identity mapping, takes an approximately 1/32 hash sample of the complete
space, and processes that sample in hash order. Whenever a head is retained,
candidates within four changed assignments are forbidden. This produces 19,800
heads with a minimum pairwise distance of five. The retained set is then
compared exactly against itself.

| Metric | Preference | Plain-language meaning |
| --- | :---: | --- |
| Valid permutation | Required | Every orbiter receives one wanderer and every wanderer is used exactly once. |
| Worst distance | Higher | The number of assignments changed between a head and its closest neighbor in the retained collection. It protects against near-duplicates. |
| Average distance | Higher | The average number of changed assignments between this head and every other retained head. It rewards broad collection-wide variety. |
| Permutation rank | Lower tie-break | A stable lexicographic ID from `0` through `11! - 1`; it is an identifier, not a strength score. |

Head ordering is also lexicographic: maximize the nearest-neighbor distance,
then maximize average distance, then use the permutation rank only to break an
exact tie.

#### Why the head is journey-agnostic

The head farmer intentionally does not declare that one role permutation has a
better journey through one particular heart. A head only decides who plays each
starting role. Scoring it against a favored heart at this stage would overfit
an otherwise reusable permutation and would partly reward labels rather than
structure.

Instead, heads are selected for validity and mutual distance. They are sorted
by diversity and dealt round-robin so each of the 180 hearts receives 110 heads,
one from every consecutive 180-head quality band. The complete journey is then
evaluated later, when the tail farmer sees the exact heart and head together.

### Tail farming

The tail completes the loop. For each wanderer A-K it chooses two orbiters whose
post-heart values are mixed into that wanderer's update. Each of the two tail
columns is a permutation, so every orbiter appears once in each column.

Tail generation is conditional: a candidate is generated and scored for one
specific heart/head pair. It must pass these immediate rules:

- the two selected orbiters for a wanderer must be different;
- an unordered orbiter pair cannot be repeated elsewhere in the tail;
- the pair cannot be equal or directly adjacent in the heart's temporal flow;
- the combined head/tail transition graph must be strongly connected.

#### Tail measurements

The farmer records the following measurements. The `Use` column distinguishes
active sort keys from diagnostics retained for analysis.

| Metric | Use | Plain-language meaning |
| --- | --- | --- |
| First minimum wanderer influence | Exploration 1, Safe 1 | After one complete journey, counts the distinct sources reaching the least-informed wanderer. This is the primary worst-case flow floor. |
| First minimum input coverage | Diagnostic | Finds the least-travelled input and counts how many wanderers it reached after the first journey. |
| Second minimum wanderer influence | Diagnostic | Repeats the least-informed-wanderer check after a second complete journey. |
| Second minimum input coverage | Diagnostic | Repeats the least-travelled-input check after the second journey. |
| Minimum pair union | Exploration 2, Safe 2 | For the weakest tail pair, counts the distinct dependencies supplied by its two orbiters together. |
| Minimum heart separation | Hard floor and diagnostic | Measures the closest temporal relationship used by any tail pair. Equal or directly related pairs are rejected. |
| Total heart separation | Exploration 5 | Adds the separation of all eleven tail pairs, favoring pairings drawn from different parts of the heart's dance. |
| Minimum pair balance | Diagnostic | Checks whether the weakest pair contributes both shared history and information unique to each side. |
| Minimum complement | Diagnostic | Measures how different the two dependency sets are in the least-different pair. |
| Dominated-pair count | Diagnostic | Counts pairs where one side adds no dependency absent from the other. Lower is better. |
| Flow area | Diagnostic | Adds influence after each assignment, heart round, and update. Higher means information spreads earlier and remains broad. |
| Arrival total | Diagnostic | Adds the first-arrival times of every tracked source at every wanderer. Lower means faster overall delivery. |
| Maximum arrival skew | Diagnostic | Measures the largest timing imbalance for one source reaching different wanderers. Lower means fewer laggards. |
| Directed diameter | Exploration 3, Safe 5 | The worst shortest route through the head/tail transition graph. Lower means fewer long directional bottlenecks. |
| Pair components | Exploration 4, Safe 3 | Counts disconnected islands in the undirected graph made by the eleven tail pairs. One is preferred. |
| Minimum subset expansion | Safe 4 | Finds the most isolated small group of roles and measures how many edges escape it. Higher means no small cluster is easy to cut off. |
| Total subset expansion | Safe 6 | Adds expansion across all tested small subsets, measuring graph-wide outward connectivity. |
| Spectral gap | Diagnostic | Estimates the graph's overall mixing rate. A larger gap generally indicates faster, more even circulation and fewer soft bottlenecks. |

The dependency measurements above track structural reachability, not
independent bit paths. Spectral gap is calculated during the Safe phase but is
currently diagnostic; it is not one of the six active Safe sort keys.

#### The three tail phases

Tail selection is deliberately split so cheap broad exploration happens before
the expensive graph checks.

1. **Exploration** generates a large candidate population independently for
   every fixed heart/head pair. Valid candidates are sorted lexicographically
   by first minimum wanderer influence, minimum pair union, lower directed
   diameter, fewer pair components, and total heart separation. Only the
   strongest pool is saved. Subset expansion and spectral gap are not computed
   here, so zero in an Exploration-only log means "not measured," not a zero-
   quality graph.
2. **Safe** reloads those pools, calculates exact subset expansion and the
   spectral diagnostic, and sorts lexicographically by first minimum wanderer
   influence, minimum pair union, fewer pair components, minimum subset
   expansion, lower directed diameter, and total subset expansion. A smaller
   pool is saved for every heart/head pair.
3. **Final** chooses one tail from each Safe pool while considering all tails
   already chosen. It first maximizes the candidate's distance from its nearest
   selected tail, then its total distance from the selected collection, and
   finally its Safe flow rank. Tail distance is the number of different entries
   across the two eleven-item orbiter-selection columns. This turns 19,800 local
   choices into one globally varied tail asset.

As in heart and head farming, these are ordered comparisons rather than a
single composite number. An earlier floor takes priority over a later
refinement. This prevents a very strong average from hiding one conspicuously
weak route.

### Recipe assembly and distribution

Each completed recipe contains one fixed heart, one of that heart's 110 heads,
and the tail farmed specifically for that pair:

```text
180 hearts x 110 head/tail choices = 19,800 recipes
19,800 recipes / 33 expanders = 600 recipes per expander
```

The assembler first shuffles the 110 recipes inside every heart bucket, then
shuffles the order of the 180 buckets. It processes one bucket at a time and
deals that bucket's recipes round-robin across the 33 expanders. This preserves
the heart grouping during the deal while distributing the complete collection
evenly. The current code generator consumes 584 recipes per expander and leaves
16 available as spares.

The saved assets are validated when loaded: heart columns must remain
permutations, heads must be one-to-one, tails must obey their pair and
connectivity rules, recipes must be structurally valid, and the final recipe
files must contain the expected unique record count.

This farming process is best understood as structural risk reduction. It
removes obvious bottlenecks, rejects disconnected or repetitive plans, and
selects a broad family of well-braided flows. It does not establish the security
of the complete cipher by itself; that still requires cryptanalysis, empirical
testing, and independent review.
