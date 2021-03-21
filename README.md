# NCI Project

## Usage

### Install dependencies

You will need to install CMake and Conan, using Ubuntu:

```bash
sudo apt install cmake build-essential
pip install conan gprof2dot
```

Using Fedora:

```bash
sudo dnf install make automake gcc gcc-c++ kernel-devel
pip install conan gprof2dot
```

### Compile the library

You can configure the project, build, run the test, and run the basic executable with the following targets:

```bash
make env-create
make test
make run
```

To compile your changes once the environment is created just `make`

lcov graphviz libncursesw5-dev doxygen plantuml


```

### Compiling

* At the root folder:

```
mkdir build && cd build
cmake ..
make -j4
make install
```

For a **want it all** version:

```
cmake   -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_COVERAGE=ON \
        -DBUILD_DOC=ON \
        -DBUILD_PROFILING=ON \
        -DBUILD_SAMPLES=ON \
        -DBUILD_TESTS=ON \
        ..
```

## Options

### Testing

All test are located at `tests` folder. You can execute each test located at `bin` directory. All of them have `test_` as prefix and are executed as a common executable.

If you want to execute all just use `make test`.

Note: To invoke ctest manually run:

```
ctest -C Release -V
```

### Coverage

To run binary with coverage setup use `BUILD_COVERAGE=ON` option. Execute `make all && make test && make coverage`

### Profiling

To run binary with profiling setup use `BUILD_PROFILING=ON` option.
This will generate a `gmon.out` file. This file can be read using `gprof`.

### Documentation

To generate documentation from source files comments using Doxygen, set up `BUILD_DOC=ON` option. Execute `make doc`

## Author

* vgoni <vgonisanz@gmail.com>
