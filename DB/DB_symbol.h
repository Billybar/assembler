#ifndef DB_SYMBOL_H
#define DB_SYMBOL_H

#include "../errors.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYMBOL_NAME_MAX_LENGTH 32
#define LINE_LEN 82

#define LOADING_ADDR 100

/* symbol list node */
struct Symbol
{
    char *name;
    int address;
    int is_directive;
    int is_external;
    int is_entry;
    struct Symbol *next;
};

/**
 * @brief insert symbol to the end
 * @param char *symbol_name
 * @param int address im memory
 * @param int directive_flag
 * @param int ext_flag
 */
void insert_symbol(char *, int, int, int);

/**
 * @brief find symbol by name
 * @param char *symbol_name
 * @return pointer to symbol
 */
struct Symbol *get_symbol(char *);

/**
 * @brief print giving symbol by pointer
 * @param struct Symbol *symbol_pointer
 */
void print_symbol(struct Symbol *);

/**
 * @brief print symbol address
 * @param void
 */
void print_symbols_address(void);

/**
 * @brief update symbol address. add 100 for each symbol addr
 * if dirctive flag then add IC as well
 * @param int IC Instruction Counter
 */
void update_symbols_address(int);

/**
 * @brief free list
 */
void free_symbol_list();

#endif /* BD_SYMBOL_H */