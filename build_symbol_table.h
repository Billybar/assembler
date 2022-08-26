#ifndef BUILD_SYMBOL_TABLE_H
#define BUILD_SYMBOL_TABLE_H

#include "text_manager.h"

#include <string.h>

#define LINE_LEN 82

/**
 * @brief build symbol table and validate source file
 * @param char *file name
 * @param FILE **pointer to source file
 * @return void
 */
void build_symbol_table(char *, int *);

/*         -------    COUNT_DC_WORDS    -------         */
/**
 * @brief if valid count directive params else error
 * @param char *line_str
 * @param char *directive
 * @param int *DC
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void count_directive_words(char *, char *, int *, int *, int);

/**
 * @brief if valid count amount of params else error
 * @param char *line_str
 * @param int *DC
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void count_data_param(char *, int *, int *, int);

/**
 * @brief if valid count string length else error
 * @param char *line_str
 * @param int *DC
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void count_string_param(char *, int *, int *, int);

/**
 * @brief if valid count struct param words length else error
 * @param char *line_str
 * @param int *DC
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void count_struct_param(char *, int *, int *, int);

/*         -------    EXTERN & ENTRY PARAMS    -------         */
/**
 * @brief if valid insert extern param to symbol table  else error
 * @param char *line
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void insert_extern_param(char *, int *, int);

/**
 * @brief if param not symbol throgh error
 * @param char *line
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void valid_entry_param(char *, int *, int);

/*         -------    COUNT_OPERANDS_WORDS    -------         */
/**
 * @brief if instruction + operand combination valid count IC words else error
 * @param char *line
 * @param char *instruction
 * @param int *IC
 * @param int *error_flag
 * @param int LC - line counter in source file
 */
void count_operands_words(char *, char *, int *, int *, int);

/**
 * @brief if operands valid return amount of word needed
 * for giving operand
 * @param char *operand
 * @param int *register_flag
 * @return if operand valid return num of words, else -1
 */
int num_of_operand_words(char *, int *);

#endif /* BUILD_SYMBOL_TABLE_H */