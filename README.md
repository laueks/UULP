# UULP

This repository is the exercise's simple solution to the book _Understanding Unix/Linux Programming_. This project structure is inspired by https://www.ipb.uni-bonn.de/teaching/modern-cpp/.

## Project structure

https://www.ipb.uni-bonn.de/teaching/modern-cpp/.

```
UULP
├── bin
├── build
├── CMakeLists.txt
├── lib
├── README.md
├── src
│   ├── CMakeLists.txt
│   └── UULP
│       ├── CMakeLists.txt
│       ├── cp
│       │   ├── cp.cpp
│       │   ├── cp.h
│       │   └── main.cpp
│       ├── UULP.cpp
│       ├── UULP.h
│       └── who
│           ├── main.cpp
│           ├── who.cpp
│           └── who.h
└── tests
    ├── CMakeLists.txt
    └── test_uulp.cpp
```

## Running UULP

To run UULP you need to go into UULP directory and do these steps:

```shell
cd UULP
mkdir build && cd build
cmake ..
make
ctest -VV
```
