scaffold_cmake_catch2
=====================

Simple C++ project template with a library, an executable and tests
using CMake and Catch2.

Build
-----

Building from outside of the project directory.

Configure:

`cmake -S ./scaffold_cmake_catch2 -B ./build_dir`

Configure without tests:

`cmake -S ./scaffold_cmake_catch2 -B ./build_dir -DBUILD_TESTING=OFF`

Build:

`cmake --build ./build_dir -- -j16`

Run tests
---------

`cmake --build ./build_dir --target test`

Licensing
=========

Creative Commons Zero v1.0 Universal.

Catch2 itself is under Boost Software License 1.0.
