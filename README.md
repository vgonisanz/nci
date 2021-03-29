# NCI Project

## Usage

### Install dependencies

You will need to install CMake and Conan, using Ubuntu:

```bash
sudo apt install cmake build-essential lcov
sudo apt install doxygen plantuml
pip install conan gprof2dot cpplint
```

Using Fedora:

```bash
sudo dnf install make automake gcc gcc-c++ kernel-devel lcov
sudo dnf install doxygen plantuml
pip install conan gprof2dot cpplint
```

### Compile the library

You can configure the project, build, run the test, and run the basic executable with the following targets:

```bash
make env-create
make test
make run
```

- To compile your changes once the environment is created just `make build`
- To debug the library edit the `.conan/profiles/default` setting `build_type=Debug`.
- You can use your own profile using `CONAN_DEV_PROFILE=profile make build`.

### Testing

All tests are in `tests` folder, to run the tests `make test`.

### Samples

Execute any sample at `build/bin` path manually.

### Documentation

You can check the nci wiki to know more about it.
You can generate doxygen code reference using `make docs`

## Author

- vgoni <vgonisanz@gmail.com>
