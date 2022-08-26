#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

#include "./DB/DB_instruction.h"
#include "./DB/DB_symbol.h"
#include "./DB/DB_macro.h"

#include <ctype.h>
#include <string.h>

#define SPACE ' '
#define TAB '\t'
#define COMMA ','
#define DOT '.'

#define INVALID -1

#define FIRST_FIELD 1
#define SECOND_FIELD 2

/* addressing method*/
#define IMMEDIATE_ADDR 0
#define DIRECT_ADDR 1
#define STRUCT_ACCESS_ADDR 2
#define DIRECT_REG_ADDR 3

/* insrtuction opcode*/
#define MOV 0
#define CMP 1
#define ADD 2
#define SUB 3
#define NOT 4
#define CLR 5
#define LEA 6
#define INC 7
#define DEC 8
#define JMP 9
#define BNE 10
#define GET 11
#define PRN 12
#define JSR 13
#define RTS 14
#define HLT 15

/* -----------------------  ----------------------- */
/**
 * @brief check if giving string is instruction
 * @param char *field a token from source file
 * @return instruction opcode on sucsses, -1 if not instruction
 */
int is_instruction(char *);

/**
 * @brief check if giving string is register
 * @param char *field a token from source file
 * @return register num on sucsses, -1 if not register
 */
int is_register(char *);

/**
 * @brief check if giving string is a printable chars
 * @param char *field a token from source file
 * @return string length (include "") on sucsses, 0 if not
 */
int is_string(char *);

/**
 * @brief check if giving string are digits only
 * NOTICE: if number out of range [-512,511] then fasle
 * @param char *field a token from source file
 * @return number on sucsses, 0 if not
 */
int is_number(char *);

/* ----------------------- IS MACRO ----------------------- */
/**
 * @brief check if giving string is macro fefinition
 * @param char *first_field of line
 * @return 1 on succsses, 0 if not
 */
int is_macro_definition(char *);

/**
 * @brief check if giving string is endmacro definition
 * @param char *first_field of line
 * @return 1 on succsses, 0 if not
 */
int is_endmacro(char *);

/**
 * @brief check if giving field is macro var
 * @param struct Macro **macro_ptr
 * @param char *first_field of line
 * @return 1 on succsses, 0 if not
 */
int is_macro_exist(struct Macro **, char *);

/* ----------------------- IS SYMBOL ----------------------- */
/**
 * @brief check if giving string is a symbol definition
 * @param char *field a token from source file
 * @param char *symbol destnation pointer. holds symbol on succses, else null
 * @return 1 on sucsses, 0 if not
 */
int is_symbol_definition(char *, char *);

/**
 * @brief check if giving symbol defined
 * @param char *symbol_name
 * @return 1 on sucsses, 0 if not
 */
int is_symbol_exist(char *symbol);

/**
 * @brief check if giving symbol_name is external
 * NOTICE: if symbol_name not exsit then function
 * will stop and return 0
 * @param char *symbol
 * @return 1 on sucsses, 0 if not
 */
int is_symbol_extern(char *symbol);

/**
 * @brief check if giving string is a symbol valid
 * @param char *field a token from source file
 * @return 1 on sucsses, 0 if not
 */
int is_symbol_valid(char *);

/* ----------------------- IS DIRECTIVE ----------------------- */

/**
 * @brief check if giving string is of directive type
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_directive(char *field);

/**
 * @brief check if giving string is a data or string or struct directive
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_data_string_struct_directive(char *field);

/**
 * @brief check if giving string is a .data directive
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_data_directive(char *);

/**
 * @brief check if giving string is a .string directive
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_string_directive(char *);

/**
 * @brief check if giving string is a .struct directive
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_struct_directive(char *);

/**
 * @brief check if giving string is a .extern directive
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_extern_directive(char *);

/**
 * @brief check if giving string is a .entry directive
 * @param char *field a token from source file
 * @return 1 if true, 0 if not
 */
int is_entry_directive(char *);

/* ----------------------- IS OPERAND ----------------------- */
/**
 * @brief check if operand is valid
 * NOTICE: func do not check if symbol exist,
 * and not if field number of struct is valid;
 * if needed call "is_operand_symbol" OR is_operand_struct".
 * @param char *operand
 * @return address method number on succsses, -1 if not
 */
int is_operand_valid(char *operand);

/**
 * @brief check if operand valid
 * by checking instruction, operand, operand type combonation
 * @param char *operand
 * @param char *instruction
 * @return 1 if true, 0 if not
 */
int is_source_operand_valid(char *, char *);

/**
 * @brief check if giving valid operand are valid combonitaion with instruction type
 * by checking instruction, operand, operand type combonitaion
 * @param char *operand is already valid operand
 * @param char *instruction is already valid instruction
 * @return 1 if true, 0 if not
 */
int is_target_operand_valid(char *, char *);

/**
 * @brief check if operand is a struct valid. num muse be 1 OR 2
 * NOTICE: calling to "get_next_field()" function therefor
 * overwriting giving str
 * @param char *operand
 * @return 1 on succsses, 0 if not
 */
int is_operand_struct_valid(char *operand);

/**
 * @brief check if giving field_number is valid
 * NOTICE: non positive numbers are NOT valid.
 * numbers bigger then symbol_name_length are NOT valid;
 * if symbol_name not exsit then function
 * will stop and return 0
 * @param int field_number
 * @param char *symbol_name
 * @return 1 on sucsses, 0 if not
 */
int is_struct_field_number_valid(int field_number, char *symbol);

/**
 * @brief check if giving operand are valid number
 * NOTICE: if number out of range [-128,127] then fasle
 * @param char *operand
 * @return number on succsses, 0 if not
 */
int is_operand_number(char *);

/**
 * @brief check if giving operand are symbol and defind in symbol-table
 * NOTICE: this function should run ONLY after finish building symbol-table
 * @param char *field a token from source file
 * @return 1 on sucsses, 0 if not
 */
int is_operand_symbol(char *);

/**
 * @brief check if operand is a struct valid AND
 * symbol define in symbol table
 * NOTICE: this function should run ONLY after finish building symbol-table
 * @param char *operand
 * @param char *symbol
 * @param int filed_number
 * @return 1 on succsses, 0 if not
 */
int is_operand_struct(char *, char *, int *);

/* ----------------------- GET NEXT FIELD ----------------------- */

/**
 * @brief get a string and tokenize base on givin delimter
 * its kind of "custom strtok"
 * NOTICE: func overwrite giving string
 * @param char *buffer to tokenize
 * @param char *token tp store data
 * @param char delimiter char
 */
void get_next_field(char *, char *, char);

/**
 * @brief skip whitesapce
 * @param char *str
 * @return num of whitespace
 */
int skip_whitesapce(char *);

/**
 * @brief trim trailing whitespace
 * @param char *field
 * @return char *field
 */
char *trim_trailing_whitespace(char *);

/**
 * @brief append EOL to giving str
 * @param char *str
 */
void append_EOL(char *str);

/* ----------------------- IS LINE ----------------------- */
/**
 * @brief check if giving line directive OR instruction line
 * @param FILE **src_code
 * @param char *line
 * @param int *err_flag
 * @param int LC - Line Counter
 * @return 1 if true, 0 if not
 */
int is_directive_instruction_line(FILE **, char *, int *, int);

/**
 * @brief check if giving line length lees then 81 chars
 * NOTICE: FUNCTION over writing '\n' char with '\0'
 * @param char *line
 * @return 1 if true, 0 if not
 */
int is_line_length_valid(char *);

/**
 * @brief check if giving line is comment line
 * @param char *field first filed of line
 * @return 1 if true, 0 if not
 */
int is_comment_line(char *);

/**
 * @brief check if giving line is empty
 * @param char *first_field of line
 * @return 1 if true, 0 if not
 */
int is_empty_line(char *);

#endif /* TEXT_MANAGER_H */