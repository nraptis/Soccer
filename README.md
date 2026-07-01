# Soccer
This is the 19th generation 'password expander' for offline file encryption.</br></br>

This is still being studied, but it contains the final structure of the key expander. There are two conflicting philosophies about the importance of side channels, side channel handling, and online versus offline scope. However, it's probably fine. U need the pwrd to crackit.</br></br>

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/image.png)</br></br>

```
#include "TwistExpander_Soccer.hpp"
#include "TwistFarmSalt.hpp"
```

</br>

```
TwistExpander_Soccer aSoccer;

std::uint8_t aTinyPassword[2];
aTinyPassword[0] = 'a';
aTinyPassword[1] = 'Z';

const int aBlockCount = 32;

TwistWorkSpace aWorkSpace;
TwistFarmSalt aFarmSalt;
std::uint64_t aNonce = 17;
std::uint8_t aDest[S_BLOCK * aBlockCount];

aSoccer.Seed(&aWorkSpace,
             &aFarmSalt,
             aNonce,
             aTinyPassword, // password
             2, // password length
             aDest);
```

</br>

```
for (int aBlockIndex=1; aBlockIndex<aBlockCount; aBlockIndex++) {
    aSoccer.TwistBlock(&aWorkSpace,
                       aNonce,
                       &aDest[(aBlockIndex - 1) * S_BLOCK], // source
                       aBlockIndex,
                       aBlockCount,
                       &aDest[(aBlockIndex) * S_BLOCK]); // dest
}
```

</br>

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/diagram_KDFA.png)</br></br>

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/diagram_KDFB.png)</br></br>

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/diagram_SEED_1.png)</br></br>

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/diagram_SEED_2.png)</br></br>

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/diagram_TWIST.png)</br></br>
