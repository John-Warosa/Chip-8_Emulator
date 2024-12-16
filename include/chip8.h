#ifndef CHIP8_H
#define CHIP8_H

#include "defines.h"


struct Chip8 {
    // Registers
    u8 registers[16];
    u16 index;

    // Memory
    u8 memory[0xfff+1];
    u16 stack[16];

    // Pointers
    u16 PC;
    u8 SP;

    // Timers
    u8 sound;
    u8 delay;

    // Input
    bool keyboard[16];

    // Display
    bool pixels[64][32];

    u16 opcode;
};


struct Chip8 *Chip8_init();

#endif //CHIP8_H
