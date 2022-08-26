#ifndef DB_MACRO_H
#define DB_MACRO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NAME_MAX_LENGTH 32
#define LINE_LEN 82

/* macro list node */
struct Macro
{
    char *name;
    char *data;
    struct Macro *next;
};

/**
 * @brief insert macro to the end
 * @param char *macro_name
 * @param char *macro_data ptr address
 */
void insert_macro(char *, char *);

/**
 * @brief find macro by name
 * @param char *macro_name
 * @return pointer to macro
 */
struct Macro *get_macro(char *);

/**
 * @brief print giving macro by pointer
 * @param struct Macro *macro_pointer
 */
void print_macro(struct Macro *);

/**
 * @brief print symbol address
 * @param void
 */
void print_macro_list(void);

/**
 * @brief free list
 */
void free_macro_list();

#endif /* DB_MACRO_H */