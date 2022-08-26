#include "DB_instruction.h"

/* READ ONLY */
struct instruction instructions[NUM_OF_INSTRUCTIONS] =
    {
        {"mov", 0, 2},
        {"cmp", 1, 2},
        {"add", 2, 2},
        {"sub", 3, 2},
        {"not", 4, 1},
        {"clr", 5, 1},
        {"lea", 6, 2},
        {"inc", 7, 1},
        {"dec", 8, 1},
        {"jmp", 9, 1},
        {"bne", 10, 1},
        {"get", 11, 1},
        {"prn", 12, 1},
        {"jsr", 13, 1},
        {"rts", 14, 0},
        {"hlt", 15, 0}};

int get_num_of_operands(int opcode)
{
    int i = 0;
    for (; i < NUM_OF_INSTRUCTIONS; i++)
        if (instructions[i].opcode == opcode)
            return instructions[i].num_of_operands;
    return INVALID;
}

int get_opcode(char *instruction)
{
    int i = 0;
    for (; i < NUM_OF_INSTRUCTIONS; i++)
        if (strcmp(instructions[i].name, instruction) == 0)
            return instructions[i].opcode;
    return INVALID; /* not instruction */
}
