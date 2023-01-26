#ifndef __CLOX_CHUNK_H__
#define __CLOX_CHUNK_H__

#include <common.h>
#include <value.h>

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

typedef struct {
  uint8_t *code;
  int *lines;
  int count;
  int capacity;

  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);

#endif
