# Base64_Cpp

Very basic [Base64](https://en.wikipedia.org/wiki/Base64) encoding/decoding solution in C++.

## Dependencies

- Google Test for the Unit Tests

## Building

To build the solution, navigate to the cloned GitHub directory and run:

```
mkdir -p build
cd build
cmake ..
make
```

To build the application with tests:

```
cmake -S . -B build -DBUILD_TESTS=true
RUN cmake --build bin
```

Google Test must be installed & configured to build & run unit tests.
