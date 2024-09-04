#include <common.h>
#include <chunk.h>
#include <debug.h>
#include <vm.h>

int main(int argc, const char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_NEGATE, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "TEST CHUNK");

    printf("== Running interpreter ==\n\n");

    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);

    printf("\n\n== End                 ==\n");

    return 0;
}