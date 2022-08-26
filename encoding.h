#ifndef ENCODING_H
#define ENCODING_H

#include "text_manager.h"

#include <ctype.h>
#include <string.h>

#define MEMORY_LENGHT 300

#define SECOND_BIT 2
#define FOURTH_BIT 4
#define SIXTH_BIT 6

/* ----------------------- DIRECTIVE PARAMS ----------------------- */
/**
 * @brief encode data param, in DC posiotion and increce DC + 1
 * @param char *data direcrive param
 * @param int *DC - data array counter
 */
void encode_data_directive_param(char *, int *);

/**
 * @brief encode string param, encode char one by one
 * @param char *string direcrive parameter
 * @param int *DC - data array counter
 */
void encode_string_directive_param(char *, int *);

/**
 * @brief encode struct param, encode number then string
 * @param char *struct direcrive param
 * @param int *DC - data array counter
 */
void encode_struct_directive_param(char *, int *);

/* ----------------------- INSTRUCTION WORD ----------------------- */
/**
 * @brief encode instruction opcode and operands address methods;
 * ARE ALWAYS 00
 * @param int instruction_opcode
 * @param char *source_operand
 * @param char *target_operand
 * @param int *IC - instruction array counter
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void encode_first_word(int, char *, char *, int *IC, int *, int);

/**
 * @brief validate and get operands address methods then place them
 * in needed bit postion
 * @param char *operand
 * @param int bit_position
 * @param int *error_flag
 * @param int LC - line counter in source file
 * @return address method number after shifting to needed bit pos, -1 on fail
 */
int get_address_method(char *, int, int *, int);

/* ----------------------- INSTRUCTION OPERANDS ----------------------- */
/**
 * @brief encode giving operand/
 * check operand type and encode
 * @param char *operand
 * @param char *operand_type
 * @param int *register_flag
 * @param int *IC - instruction array counter
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void encode_operand(char *, char *, int *, int *, int *, int);

/**
 * @brief encode giving number starting in 3rd posotion bit
 * @param int number
 * @param int *IC - instruction array counter
 */
void encode_number(int, int *);

/**
 * @brief encode giving VALID symbol starting in 3rd posotion bit
 * @param char *symbol
 * @param int *IC - instruction array counter
 */
void encode_symbol_address(char *, int *);

/**
 * @brief encode giving operand/
 * check operand type and encode
 * @param int register_number
 * @param char *operand_type "source" OR "target"
 * @param int *is_source_reg flag
 * @param int *IC - instruction array counter
 */
void encode_register(int, char *, int *, int *);

/* ----------------------- GET MEMNORY ----------------------- */
/**
 * @brief copy memory to giving pointers
 * @param int *IC_mem
 * @param int *DC_memd
 */
void get_encoded_memory(int *, int *);

#endif /* ENCODING_H */