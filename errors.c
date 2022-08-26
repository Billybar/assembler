#include "errors.h"

void err_many(char *str, int *err_flag, int LC)
{
    (*err_flag) = true;
    printf("line: %d " ERROR "argument: %s\t too many arguments \n", LC, str);
}

void err_few(char *str, int *err_flag, int LC)
{
    (*err_flag) = true;
    printf("line: %d " ERROR "argument: %s\ttoo few arguments\n", LC, str);
}

void err_dup_sym(char *str, int *err_flag, int LC)
{
    (*err_flag) = true;
    printf("line: %d " ERROR "symbol: %s\tduplicate symbol declaration\n", LC, str);
}

void err_long(char *str, int *err_flag, int LC)
{
    (*err_flag) = true;
    printf("line: %d " ERROR "line: %s\tline too long\n", LC, str);
}

void err_unknwon(char *str, int *err_flag, int LC)
{
    (*err_flag) = true;
    printf("line: %d " ERROR "token: %s\tunknwon token\n", LC, str);
}

void err_not_exist(char *str, int *err_flag, int LC)
{
    (*err_flag) = true;
    printf("line: %d " ERROR "symbol: %s\tsymbol not exist\n", LC, str);
}

void err_must_int(char *str, int *err_flag, int LC)
{
    *err_flag = true;
    printf("line: %d " ERROR "param: %s\tdata param's must be int\n", LC, str);
}

void err_must_str(char *str, int *err_flag, int LC)
{
    *err_flag = true;
    printf("line: %d " ERROR "param: %s\tstring param must be string\n", LC, str);
}

void err_struct_must_int(char *str, int *err_flag, int LC)
{
    *err_flag = true;
    printf("line: %d " ERROR "num: %s\tstruct first param must int\n", LC, str);
}

void err_must_sym(char *str, int *err_flag, int LC)
{
    *err_flag = true;
    printf("line: %d " ERROR "param: %s\tparam must be symbol\n", LC, str);
}

void err_invalid(char *str, int *err_flag, int LC)
{
    *err_flag = true;
    printf("line: %d " ERROR "operand: %s\tinvalid operand\n", LC, str);
}
