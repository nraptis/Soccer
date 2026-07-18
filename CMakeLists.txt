cmake_minimum_required(VERSION 3.23)

project(Soccer
    VERSION 1.0.0
    LANGUAGES CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(SOCCER_MSVC_STATIC_RUNTIME "Build with the MSVC static runtime (/MT) instead of the DLL runtime (/MD)." OFF)

set(SOCCER_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/Scramble")
set(SOCCER_COMPOSER_ROOT "${SOCCER_SOURCE_ROOT}/Composer")
set(SOCCER_ENCRYPTER_ROOT "${SOCCER_SOURCE_ROOT}/Encrypter")
set(SOCCER_EXPANDER_ROOT "${SOCCER_SOURCE_ROOT}/Expander")

set(SOCCER_PUBLIC_HEADERS
    "${SOCCER_SOURCE_ROOT}/Public/Soccer.hpp"
)

file(GLOB SOCCER_CORE_SOURCES CONFIGURE_DEPENDS
    "${SOCCER_EXPANDER_ROOT}/Core/*.cpp"
)

file(GLOB SOCCER_FAMILY_SOURCES CONFIGURE_DEPENDS
    "${SOCCER_EXPANDER_ROOT}/Family/*.cpp"
)

set(SOCCER_LIBRARY_SOURCES
    "${SOCCER_COMPOSER_ROOT}/Soccer.cpp"
    "${SOCCER_ENCRYPTER_ROOT}/EncryptionLayer.cpp"
    "${SOCCER_ENCRYPTER_ROOT}/LayeredCrypt.cpp"
    ${SOCCER_CORE_SOURCES}
    ${SOCCER_FAMILY_SOURCES}
    ${SOCCER_PUBLIC_HEADERS}
)

add_library(soccer STATIC
    ${SOCCER_LIBRARY_SOURCES}
)

add_library(Soccer::soccer ALIAS soccer)

target_compile_features(soccer PUBLIC cxx_std_20)

set_target_properties(soccer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS YES
    OUTPUT_NAME soccer
    PUBLIC_HEADER "${SOCCER_PUBLIC_HEADERS}"
)

target_include_directories(soccer
    PUBLIC
        "$<BUILD_INTERFACE:${SOCCER_SOURCE_ROOT}/Public>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/soccer>"
    PRIVATE
        "${SOCCER_COMPOSER_ROOT}"
        "${SOCCER_EXPANDER_ROOT}/Core"
        "${SOCCER_EXPANDER_ROOT}/Family"
        "${SOCCER_ENCRYPTER_ROOT}"
        "${SOCCER_ENCRYPTER_ROOT}/Ciphers/Mix"
        "${SOCCER_ENCRYPTER_ROOT}/Ciphers/Move"
)

if(MSVC)
    target_compile_options(soccer PRIVATE /W3)
    if(SOCCER_MSVC_STATIC_RUNTIME)
        set_property(TARGET soccer PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        )
    else()
        set_property(TARGET soccer PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
        )
    endif()
else()
    target_compile_options(soccer PRIVATE -Wall -Wextra)
endif()

install(TARGETS soccer
    EXPORT SoccerTargets
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/soccer"
)

install(EXPORT SoccerTargets
    FILE SoccerTargets.cmake
    NAMESPACE Soccer::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/soccer"
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/SoccerConfigVersion.cmake"
    VERSION "${PROJECT_VERSION}"
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SoccerConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/SoccerConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/soccer"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/SoccerConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SoccerConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/soccer"
)

install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/licenses/soccer"
    COMPONENT License
)
