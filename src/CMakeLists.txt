#add_compile_options (-pthread -Wall -pedantic -Werror)

set (COMMON_SOURCE 
    libclox.c
    clox_memory.c
    chunk.c
    compiler.c
    debug.c
    object.c 
    scanner.c
    table.c
    value.c
    vm.c
)

add_library(runtime ${COMMON_SOURCE})
target_include_directories(
    runtime
    PUBLIC 
    "include"
)

add_executable (clox main.c)
target_link_libraries (clox PRIVATE runtime)
