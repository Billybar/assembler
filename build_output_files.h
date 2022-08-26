#ifndef BUILD_OUTPUT_FILES_H
#define BUILD_OUTPUT_FILES_H

#include "encoding.h"

#include <string.h>

#define LINE_LEN 82

/**
 * @brief build output files
 * @param char *file name
 * @param char DC
 * @return void
 */
void build_output_files(char *, int);

/**
 * @brief build ent file
 * @param char *file name
 * @param char *symbol
 */
void build_ent_file(char *, char *);

/**
 * @brief build ent file
 * @param char *symbol
 * @param char *file_name
 * @param int IC
 */
void build_ext_file(char *, char *, int);

/**
 * @brief build ob file
 * @param char *file_name
 * @param int DC
 * @param int IC
 */
void build_ob_file(char *file_name, int, int);

/**
 * @brief convert to base 32
 * @param char *dest
 * @param unsigned int num
 */
void dec_to_base32(char *dest, unsigned int num);

/**
 * @brief encoding directive params
 * update error flp if needed
 * @param char *line_str
 * @param char *instruction
 * @param char *filename
 * @param int *error_flag
 * @param int *DC Directive Counter
 * @param int LC - line counter in source file
 */
void encode_directive(char *, char *, char *, int *, int *, int);

/**
 * @brief encoding instruction
 * update error flp if needed
 * @param char *line_str
 * @param char *instruction
 * @param char *filename
 * @param int *error_flag
 * @param int *IC Instruction Counter
 * @param int LC - line counter in source file
 */
void encode_instruction(char *, char *, char *, int *, int *, int);

#endif /* BUILD_OUTPUT_FILES_H */