# Template for googleTesting C++ projects

## NOTE: This branch requires the googletest repo to be cloned to /usr/lib. This avoids having to pull all dependencies into /build and allows for reusability

### Steps involved

+ Install cmake with:

```
sudo apt install cmake
```

+ Clone googletest to root:

```
~$ git clone git@github.com:google/googletest.git
```

+ Build with CMake:

```
~$ cd googletest-main
~/googletest-main$ sudo cmake CMakeLists.txt
~/googletest-main$ sudo make
```

+ Copy libs to /usr/...

```
~/googletest-main$ cd lib
~/googletest-main/lib$ sudo cp * /usr/lib
~/googletest-main/lib$ cd ..
~/googletest-main$ cd googlemock/include
~/googletest-main/googlemock/include$ sudo cp -r gmock /usr/local/include
~/googletest-main/googlemock/include$ cd ~/googletest-main/googletest/include
~/googletest-main/googlemock/include$ sudo cp -r gtest /usr/local/include

```