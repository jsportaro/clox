#ifndef __CLOX_DEBUG_H__
#define __CLOX_DEBUG_H__

#include <chunk.h>

void disassembleChunk(Chunk *chunk, const char* name);
int disassembleInstruction(Chunk *chunk, int offset);

#endif
