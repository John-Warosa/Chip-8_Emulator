#include "instructions.h"
#include "defines.h"

#define NNN(x) (x & 0x0fff)
#define NN(x) (x & 0x00ff) 
#define N(x) (x & 0x000f)
#define REG1(x) ((x & 0x0f00) >> 8);
#define REG2(x) ((x & 0x00f0) >> 4);


// Clear video buffer
static void OP_00E0(bool pixels[][]) {
    for (int x = 0; x < 64; ++i) {
        for (int y = 0; y < 32; ++j) {
            pixels[x][y] = 0;
        }
    }
}


// Return from subroutine
static void OP_00EE(u8 *SP, u16 *PC, u16 stack[]) {
    --(*SP);
    *PC = stack[*SP];
}


// Jump to address NNN
static void OP_1NNN(u16 *PC, u16 opcode) {
    *PC = NNN(opcode);
}


// Call subroutine
static void OP_2NNN(u8 *SP, u16 *PC, u16 opcode, u16 stack[]) {
    stack[*SP] = *PC;
    ++(*SP);
    *PC = NNN(opcode);
}


// Skip instruction if Vx == NN
static void OP_3XNN(u16 *PC, u16 opcode, u8 registers[]) {
    unsigned index = REG1(opcode);

    if (registers[index] == NN(opcode)) {
        *PC += 2;
    }
}


// SKip instruction if VX != NN
static void OP_4XNN(u16 *PC, u16 opcode, u8 registers[]) {
    unsigned index = REG1(opcode);

    if (registers[index] != NN(opcode)) {
        *PC += 2;
    }
}


// Skip instruction if Vx == Vy
static void OP_5XY0(u16 *PC, u16 opcode, u8 registers[]) {
    unsigned xIndex = REG1(opcode);
    unsigned yIndex = REG2(opcode);

    if (registers[xIndex] == registers[yIndex]) {
        *PC += 2;
    }
}


// Set Vx to NN
static void OP_6XNN(u16 opcode, u8 registers[]) {
    unsigned index = REG1(opcode);
    registers[index] = NN(opcode);
}


// Add NN to Vx
static void OP_7XNN(u16 opcode, u8 registers[]) {
    unsigned index = REG1(opcode);
    registers[index] += NN(opcode);
}


// Set Vx to Vy
static void OP_8XY0(u16 opcode, u8 registers[]) {
    unsigned xIndex = REG1(opcode);
    unsigned yIndex = REG2(opcode);
    registers[xIndex] = registers[yIndex];
}
