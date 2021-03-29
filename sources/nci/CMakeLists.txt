file(GLOB NCI_HEADERS
    "include/*.h"
    "include/*.hpp"
)
file(GLOB NCI_SRC
    "src/*.c"
    "src/*.cpp"
)

add_library(nci ${NCI_HEADERS} ${NCI_SRC})
target_include_directories(nci PUBLIC include)