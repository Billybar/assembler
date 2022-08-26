#ifndef MACRO_PARSER_H
#define MACRO_PARSER_H

#include "text_manager.h"

#include <string.h>

#define LINE_LEN 82

/**
 * @brief parse all macros in giving file
 * @param char *file_name
 */
void macro_parser(char *file_name);

/**
 * @brief append macro name and data to macro DB
 * @param char *line
 * @param FILE **src_code
 */
void append_DB_macro(char *line, FILE **src_code);

/**
 * @brief copy macro data to a giving pointer
 * @param char *line src
 * @param char **data dest
 */
void copy_data(char *line, char **data);

#endif /* MACRO_PARSER_H */