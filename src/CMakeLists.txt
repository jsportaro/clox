add_compile_options (-pthread -Wall -pedantic -Werror)

set (COMMON_SOURCE cloxlib.c)

add_library(cloxlib ${COMMON_SOURCE})
target_include_directories(cloxlib PUBLIC include)

add_executable (clox main.c)
target_link_libraries (clox PRIVATE cloxlib)
