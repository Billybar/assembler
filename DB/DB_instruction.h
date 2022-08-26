#ifndef DB_instruction_H
#define DB_instruction_H

#include <string.h> /*strcmp*/

#define NUM_OF_INSTRUCTIONS 16
#define INVALID -1

struct instruction
{
    char name[4];
    int opcode;
    int num_of_operands;
};

/**
 * @brief get instruction amount of operands reciving
 * @param int instruction_opcode
 * @return num of operand on succsess, -1 if INVALID opcode number
 */
int get_num_of_operands(int);

/**
 * @brief get instruction opcode
 * @param char *instruction_name
 * @return opcode number, -1 if INVALID instruction name
 */
int get_opcode(char *);

#endif /* DB_instruction_H */