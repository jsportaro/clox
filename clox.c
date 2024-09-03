#include <common.h>
#include <chunk.h>
#include <debug.h>

int main(int argc, const char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);

    disassembleChunk(&chunk, "TEST CHUNK");
    freeChunk(&chunk);

    return 0;
}