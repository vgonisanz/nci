from conans import ConanFile, CMake, tools


class ConanRecipe(ConanFile):
    name = "nci"
    version = "0.1.0"
    license = "GNU LESSER GENERAL PUBLIC LICENSE"
    author = "vgonisanz@gmail.com"
    url = "https://github.com/vgonisanz/nci"
    description =   "NCI is a lightweight library to create UI on the terminal in a fast way to provide "
                    "a better experience using complex commands and consuming the outputs creating "
                    "text-based user interfaces and a easy way to interact with any binary. In the "
                    "following sections you can learn more about the different widgets and its "
                    "behavior. Each section have a full description of each type of widget and "
                    "the requirements used to desing and develop them."
    topics = ("ncurses", "terminal", "gui")
    settings = "arch", "build_type", "compiler", "os"
    options = {
        "shared": [True, False],
    }
    default_options = {
        "shared": True,
    }
    generators = "cmake"
    exports_sources = "sources/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="sources")
        cmake.build()
        if tools.get_env("CONAN_RUN_TESTS", default=False):
            cmake.test(args=['--', 'ARGS=-T Test'])

    def package(self):
        self.copy("*.h", dst="include", src="sources/nci/include")
        self.copy("*nci.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False, excludes=["*gmock*", "*gtest*"])
        self.copy("*", dst="bin", src="bin", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["nci"]

