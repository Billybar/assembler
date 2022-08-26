#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>

/* for printing uses only */
#define COL_RED "\x1b[31m"
#define COL_GREEN "\x1b[32m"
#define COL_YELLOW "\x1b[33m"
#define COL_BLUE "\x1b[34m"
#define COL_MAGENTA "\x1b[35m"
#define COL_CYAN "\x1b[36m"
#define COL_RESET "\x1b[0m"
#define ERROR COL_RED "error: " COL_RESET

enum bool
{
    false,
    true
};

/**
 * @brief mark err_flag and print error
 * @param char *arg
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_many(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *arg
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_few(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *symbol
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_dup_sym(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *line
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_long(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *token
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_unknwon(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *param
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_not_exist(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *param
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_must_int(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *param
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_must_str(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *param
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_struct_must_int(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *param
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_must_sym(char *, int *, int);

/**
 * @brief mark err_flag and print error
 * @param char *param
 * @param int *err_flag
 * @param int LC Line Counter
 */
void err_invalid(char *, int *, int);

#endif /* ERRORS_H */