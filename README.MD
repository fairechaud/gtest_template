# Template for googleTesting C++ projects

## NOTE: 

manually create build folder, it was not included for dependency pulling issues

+ Install cmake with:

```
sudo apt install cmake
```

+ Check the CMakeLists.txt file for the logic behind pulling repo for googletest, i.e. :

```
include(FetchContent)
FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/google/googletest
            GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)
```