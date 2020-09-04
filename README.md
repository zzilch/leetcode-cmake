# LeetCode CMake

A CMake project template for LeetCode.

**Featrues**
- CMake project
- Local playground
- Unit test and benchmark
- Cross platform

## File Structure
```
LeetCodeCMake
├── CMakeLists.txt           # Project wide setup
├── src
│   ├── CMakeLists.txt       # Target collection
│   ├── include
│   │   ├── CMakeLists.txt   # Library collection
│   │   ├── catch.h          # Catch2 header file
│   │   └── leetcode.h       # Leetcode header file
│   └── L0001                # Problem 1
│       ├── L0001.h          #   Solution file
│       ├── L0001.cpp        #   Playground main
│       └── TestL0001.cpp    #   Test main
├── cmake                    # CMake modules
│   ├── Catch.cmake          
│   └── CatchAddTests.cmake 
└── build                    # Build directory
```

## Usage

To run the example project, you need a complier with C++17 support.

### 1. Clone & Build
Build and test the project in command line.
```bash
$ cmake -B build
$ cmake --build build --target TestL0001 L0001
$ cd build 

$ ctest -R L0001 # run tests in problem L0001
Test project D:/code/learn_cmake/build
    Start 1: L0001
1/1 Test #1: L0001 ............................   Passed    0.02 sec

100% tests passed, 0 tests failed out of 1

$ ./src/Debug/TestL0001 # run all tests and benchmark in problem L001
-------------------------------------------------------------------------------
L0001_Benchmark
-------------------------------------------------------------------------------
/src/L0001/TestL0001.cpp(32)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Brute Force                                    100             1    190.132 ms 
                                        706.525 us    585.886 us    874.196 us 
                                        718.779 us    563.925 us    971.882 us

Hash Map                                       100             1    20.7629 ms 
                                        187.329 us    170.959 us    206.033 us 
                                        88.9449 us    75.6476 us    107.436 us

Hash Map2                                      100             1    860.129 ms 
                                        9.20266 ms    9.10087 ms     9.3058 ms 
                                        523.041 us    467.378 us    615.805 us


===============================================================================
All tests passed (9 assertions in 2 test cases)

$ ./src/L0001/L0001 # run playground L0001
[2, 7, 11, 15] 
9
[0, 1]
```

You can also open this directory using VSCode with CMake Tools extension, or open this directory using VS2019+ to run the target more easily. 


### 2. Add new problems

- Problem directory: `src/LXXX`
- Problem header: `src/LXXX.h`, include `leetcode.h`
- [Optional] Playground source: `src/LXXX.cpp`, include `LXXX.h`
- [Optional] Test source: `src/TestLXXX.cpp`, include `LXXX.h` and `catch.h`
- Rebuild

Read `TestL0001.cpp` and `TestL0002.cpp` to learn hwo to write basic catch test cases. Refer to catch [tutorial](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md) and [benchmark](https://github.com/catchorg/Catch2/blob/master/docs/benchmarks.md) for more complicated usage.

## Leetcode Header
Some widely used leetcode structs and functions are inlucded in `src/include/leetcode.h`

- ListNode/TreeNode
- trimLeftTrailingSpaces/trimRightTrailingSpaces
- stringToInteger/stringToString/boolToString
- stringToIntegerVector/integerVectorToString
- stringToListNode/listNodeToString
- stringToTreeNode

Used STL: `iostream`/`sstream`/`cstdlib`/`cassert`/`string`/`vector`/`queue`

## Compromises
Some compromises for convenience but not best practices:

1. Use `file(GLOB ...)` to collect targets: CMake is not
automatically re-run when removing or adding files. Even though the `CONFIGURE_DEPENDS` flag can fix it, there is still a cost to perform the check on every rebuild.

2. Use `#define CATCH_CONFIG_MAIN` in every test file, which will repeated compiling the `catch.hpp` for each test. However, we just want a runnable test for each problem, so we don't need a super test program. Avoid building all targets at once.

3. Implement all methods in `LXXXX.hpp` to keep the project simple.

## Q&A
1. How to debug the playground with vscode?

    Install the `vscode-cmake-tools` extension and configure the `launch.json` according to https://vector-of-bool.github.io/docs/vscode-cmake-tools/debugging.html.   
    This is an example for gdb. You can create a default template `launch.json` on your platform and make sure that `program`, `externalConsole` and `enviroment` are set correctly.

2. How to change the C++ standard?

    Change the line `set(CMAKE_CXX_STANDARD 20)` in the top level `CMakeLists.txt`.

## Acknowledge
- [CMake](https://github.com/Kitware/CMake)
- [Catch2](https://github.com/catchorg/Catch2)
- [LeetCode](https://leetcode.com/)