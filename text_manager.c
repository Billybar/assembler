#include "text_manager.h"

/* -----------------------  ----------------------- */
int is_number(char *field)
{
    int i = 0, length = strlen(field);

    if (*field == '-' || *field == '+')
        i = 1; /* skip to first digit */

    for (; i < length; i++)
        if (!isdigit(*(field + i)))
            return false;

    return (atoi(field)); /* its valid number */
}

int is_string(char *field)
{
    int i, length = strlen(field);

    if (length == 1) /* empty string */
        return false;

    if ((*field) != '"' || (*(field + (length - 1))) != '"') /* if NOT start and end with " " */
        return false;

    for (i = 0; i < length; i++)
        if (!isprint(*(field + i))) /* if not printable*/
            return false;

    return length; /* its valid string */
}

int is_instruction(char *field)
{
    return get_opcode(field);
}

int is_register(char *filed)
{
    if (strcmp(filed, "r0") == 0)
        return 0;
    else if (strcmp(filed, "r1") == 0)
        return 1;
    else if (strcmp(filed, "r2") == 0)
        return 2;
    else if (strcmp(filed, "r3") == 0)
        return 3;
    else if (strcmp(filed, "r4") == 0)
        return 4;
    else if (strcmp(filed, "r5") == 0)
        return 5;
    else if (strcmp(filed, "r6") == 0)
        return 6;
    else if (strcmp(filed, "r7") == 0)
        return 7;

    return INVALID; /* not register */
}

/* ----------------------- IS MACRO ----------------------- */
int is_macro_definition(char *field)
{
    if (strcmp(field, "macro") == 0)
        return true;
    else
        return false;
}

int is_endmacro(char *field)
{
    if (strncmp(field, "endmacro\n", strlen(field)) == 0)
        return true;
    else if (strncmp(field, "endmacro", strlen(field)) == 0)
        return true;
    else
        return false;
}

int is_macro_exist(struct Macro **macro_ptr, char *field)
{
    if (((*macro_ptr) = get_macro(field)))
        return true;
    else
        return false;
}

int is_macro_var_valid(char *field)
{
    return is_symbol_valid(field);
}

/* ----------------------- IS SYMBOL ----------------------- */
int is_symbol_exist(char *symbol)
{
    if (get_symbol(symbol))
        return true;
    else
        return false;
}

int is_symbol_extern(char *symbol)
{
    if (is_symbol_exist(symbol) && get_symbol(symbol)->is_external)
        return true;
    else
        return false;
}

int is_symbol_valid(char *field)
{
    int i;

    if (is_instruction(field) != -1) /* if is instruction */
        return false;
    if (is_register(field) != -1) /* if is register */
        return false;

    if (!(isalpha(*field))) /* validate first letter */
        return false;

    for (i = 1; *(field + i) != '\0'; i++) /* validate rest of field */
    {
        if (i >= 30)
            return false;
        if (!(isalnum(*(field + i))))
            return false;
    }

    return true; /* its valid symbol */
}

int is_symbol_definition(char *field, char *symbol)
{
    if ((*(field + strlen(field) - 1)) == ':') /* if end == ':'*/
    {
        (*(field + strlen(field) - 1)) = '\0'; /* overwrite ':' */
        strcpy(symbol, field);
        return is_symbol_valid(symbol); /* validate symbol */
    }
    else
        return false;
}

/* ----------------------- IS DIRECTIVE ----------------------- */
int is_directive(char *field)
{
    if (is_data_string_struct_directive(field))
        return true;
    if (is_extern_directive(field))
        return true;
    if (is_entry_directive(field))
        return true;

    /*else*/
    return false;
}

int is_data_string_struct_directive(char *field)
{

    if (is_data_directive(field) ||
        is_string_directive(field) ||
        is_struct_directive(field))
        return true;
    else
        return false;
}

int is_extern_directive(char *field)
{
    if (strcmp(field, ".extern") == 0)
        return true;
    else
        return false;
}

int is_entry_directive(char *field)
{
    if (strcmp(field, ".entry") == 0)
        return true;
    else
        return false;
}

int is_string_directive(char *field)
{
    if (strcmp(field, ".string") == 0)
        return true;
    else
        return false;
}

int is_data_directive(char *field)
{
    if (strcmp(field, ".data") == 0)
        return true;
    else
        return false;
}

int is_struct_directive(char *field)
{
    if (strcmp(field, ".struct") == 0)
        return true;
    else
        return false;
}

/* ----------------------- IS OPERAND ----------------------- */
int is_operand_valid(char *operand)
{
    /* return operand addressing type */
    if (is_operand_number(operand))
        return IMMEDIATE_ADDR;
    else if (is_register(operand) != INVALID) /* if register */
        return DIRECT_REG_ADDR;
    else if (is_symbol_valid(operand))
        return DIRECT_ADDR;
    else if (is_operand_struct_valid(operand))
        return STRUCT_ACCESS_ADDR;
    else
        return INVALID;
}

int is_operand_number(char *operand)
{
    if (*operand == '#')
        return (is_number(operand + 1));
    else
        return false;
}

int is_operand_symbol(char *operand)
{
    if (is_symbol_exist(operand))
        return true;
    else
        return false;
}

int is_operand_struct(char *operand, char *symbol, int *field_number)
{
    char field_number_str[SYMBOL_NAME_MAX_LENGTH];

    get_next_field(operand, symbol, DOT);
    get_next_field(operand, field_number_str, COMMA);
    (*field_number) = atoi(field_number_str);

    if (is_operand_symbol(symbol))
        return true;
    else
        return false;
}

int is_operand_struct_valid(char *operand)
{
    char temp_operand[LINE_LEN];
    char symbol[SYMBOL_NAME_MAX_LENGTH];
    char field_number[SYMBOL_NAME_MAX_LENGTH];
    int num;
    strncpy(temp_operand, operand, LINE_LEN);

    get_next_field(temp_operand, symbol, DOT);
    get_next_field(temp_operand, field_number, '\0');
    num = (is_number(field_number));

    if (is_symbol_valid(symbol) && (num == FIRST_FIELD || num == SECOND_FIELD))
        return true;
    return false;
}

int is_source_operand_valid(char *operand, char *instruction)
{
    int address_method = is_operand_valid(operand);
    int opcode = get_opcode(instruction);

    if (address_method == INVALID) /* if not valid operand */
        return false;

    switch (opcode)
    {
    case MOV:
        return true;
    case CMP:
        return true;
    case ADD:
        return true;
    case SUB:
        return true;
    case LEA:
        if ((address_method == DIRECT_ADDR) ||
            (address_method == STRUCT_ACCESS_ADDR))
            return true;
        else
            return false;
    default: /* if not one of the operadns above */
        return false;
    }
}

int is_target_operand_valid(char *operand, char *instruction)
{
    int address_method = is_operand_valid(operand);
    int opcode = get_opcode(instruction); /* instruction opcode*/

    if (address_method == INVALID) /* if INVALID operand */
        return false;
    if (opcode == INVALID) /* if INVALID instruction name */
        return false;
    if (opcode == RTS)
        return false;
    if (opcode == HLT)
        return false;

    /* if operand is number && instruction NOT (cmp OR prn) */
    if ((address_method == IMMEDIATE_ADDR) &&
        !((opcode == CMP) || (opcode == PRN)))
        return false;
    else
        return true;
}

/* ----------------------- GET NEXT FIELD ----------------------- */
void get_next_field(char *line, char *field, char delimiter)
{
    int lineIndex = 0, fieldIndex = 0;
    char *to_next_field;
    char chr = '\n';

    if (*line == EOF)
    {
        (*field) = '\0';
        return;
    }
    if (*line == '\0')
    {
        (*field) = '\0';
        return;
    }

    lineIndex = skip_whitesapce(line); /* get first non whilesapce index */

    /* -- GET FIELD -- */
    while ((chr = *(line + lineIndex)) != '\0')
    {
        if (chr == delimiter)
            break;
        *(field + fieldIndex) = chr;
        fieldIndex++;
        lineIndex++;
    }
    /* -- --------- -- */

    *(field + fieldIndex) = '\0'; /* add null */
    if (chr == '\0')              /* if end of line then reset */
        (*line) = '\0';
    else
    {
        to_next_field = (line + lineIndex + 1); /* +1 for skip delimiter */
        memmove(line, to_next_field, LINE_LEN);
    }

    trim_trailing_whitespace(field);
}

int skip_whitesapce(char *str)
{
    int index = 0;
    while (isspace(*(str + index)))
        index++;
    return index; /* first non whilesapce index*/
}

char *trim_trailing_whitespace(char *str)
{
    char *end;
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
        end--;

    end[1] = '\0'; /* add null */
    return str;
}

void append_EOL(char *str)
{
    char *start = str, *end = str + strlen(str);
    if (*start == '\0') /* if empty str*/
    {
        (*start) = '\n';
        start[1] = '\0';
    }
    else if (*(end - 1) == '\n') /* if EOL exists*/
        ;
    else if (*end == '\0')
    {
        *end = '\n';
        end[1] = '\0';
    }
}

/* ----------------------- IS LINE ----------------------- */
int is_directive_instruction_line(FILE **src_code, char *line, int *err_flag, int LC)
{
    char symbol_field[LINE_LEN], main_field[LINE_LEN], symbol[LINE_LEN];

    if (!is_line_length_valid(line)) /* invalid length line*/
    {
        err_long(line, err_flag, LC);
        while (((char)fgetc((*src_code))) != '\n')
            ; /*go to next line*/
        return false;
    }
    else if (is_empty_line(line) || is_comment_line(line)) /* empty or comment line*/
        return false;

    /* if symbole go to next field */
    get_next_field(line, symbol_field, SPACE);
    if (is_symbol_definition(symbol_field, symbol))
        get_next_field(line, main_field, SPACE);
    else
        strncpy(main_field, symbol_field, LINE_LEN);
    /* ---------------------------- */

    if (is_directive(main_field) ||
        is_instruction(main_field) != INVALID) /* directive or instruction line*/
    {
        return true;
    }
    else /* invalid line */
    {
        err_unknwon(main_field, err_flag, LC);
        return false;
    }
}

int is_line_length_valid(char *line)
{
    int i = 0;
    for (; i < LINE_LEN - 1; i++)
    {
        if (line[i] == '\0') /* for last line in file (edge case)*/
            return true;
        if (line[i] == '\n')
        {
            line[i] = '\0'; /*over wirte EOL*/
            return true;
        }
    }
    return false;
}

int is_comment_line(char *field)
{
    if (*field == ';')
        return true;
    else
        return false;
}

int is_empty_line(char *field)
{
    while ((*field != '\0'))
    {
        if (!isspace(*field))
            break;
        field++;
    }
    if ((*field) == '\0')
        return true;
    else
        return false;
}