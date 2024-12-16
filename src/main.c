#include "chip8.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    struct Chip8 *chip = Chip8_init();

    printf("%lu", sizeof(*chip));
    free(chip);

    return 0;
}
