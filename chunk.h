#ifndef byte_chunk_h
#define byte_chunk_h

// module to define our code representation

#include "common.h"
#include "value.h"

// In our bytecode format, each instruction has a one-byte operation code
// (universally shortened to opcode). That number controls what kind of
// instruction we’re dealing with—add, subtract, look up variable, etc. We
// define those here:

typedef enum
{
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

// Bytecode is a series of instructions. Eventually, we’ll store some other data
// along with the instructions, so let’s go ahead and create a struct to hold it
// all.

typedef struct
{
    int        count;
    int        capacity;
    uint8_t*   code;
    int*       lines;
    ValueArray constants;
} Chunk;

// Function to initialize a new chunk
void initChunk( Chunk* chunk );

//
void freeChunk( Chunk* chunk );

//
void writeChunk( Chunk* chunk, uint8_t byte, int line );
int  addConstant( Chunk* chunk, Value value );

#endif
