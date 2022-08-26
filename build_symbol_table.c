#include "build_symbol_table.h"

/**
 * this file build symbol table
 * and looking for errors
 * if error found returning error to main.
 */

void build_symbol_table(char *file_name, int *dir_start_addr)
{
    FILE *src_code;
    char am_file[LINE_LEN], line[LINE_LEN], line_cpy[LINE_LEN], symbol[LINE_LEN];
    char symbol_field[LINE_LEN], main_field[LINE_LEN];
    int symbol_flag, directive_flag, err_flag = false; /* flags */
    int IC = 0, DC = 0, LC = 0;                        /* counters */

    strcpy(am_file, file_name);
    if (!(src_code = fopen(strcat(am_file, ".am"), "r")))
        perror(__FILE__);

    while ((fgets(line, LINE_LEN, src_code)) != NULL)
    {
        LC++; /* line counter*/
        symbol_flag = directive_flag = false;
        strncpy(line_cpy, line, LINE_LEN);

        if (!is_directive_instruction_line(&src_code, line_cpy, &err_flag, LC))
            continue;
        is_line_length_valid(line);

        /*         -------    IS_SYMBOL_DEFINE    -------         */
        get_next_field(line, symbol_field, SPACE);
        if (is_symbol_definition(symbol_field, symbol))
        {
            symbol_flag = true;
            get_next_field(line, main_field, SPACE);
            if (is_symbol_exist(symbol))
                err_dup_sym(symbol, &err_flag, LC);
        }
        else
            strncpy(main_field, symbol_field, LINE_LEN);

        /*         -------    IS_DIRECTIVE_LINE    -------         */
        if (is_data_string_struct_directive(main_field))
        {
            directive_flag = true;
            if (symbol_flag)
                insert_symbol(symbol, DC, directive_flag, false);
            count_directive_words(line, main_field, &DC, &err_flag, LC);
        }
        else if (is_extern_directive(main_field))
            insert_extern_param(line, &err_flag, LC);

        else if (is_entry_directive(main_field))
            valid_entry_param(line, &err_flag, LC);

        /*         -------    IS_INSTRUCTION_LINE    -------         */
        else if (is_instruction(main_field) != INVALID)
        {
            if (symbol_flag)
                insert_symbol(symbol, IC, directive_flag, false);
            IC++; /* for first word */
            count_operands_words(line, main_field, &IC, &err_flag, LC);
        }

        /* check if too many args */
        if (!is_empty_line(line))
            err_many(line, &err_flag, LC);
    }

    update_symbols_address(IC);
    *dir_start_addr = (*dir_start_addr) + IC;
    fclose(src_code);

    if (err_flag)
        exit(EXIT_FAILURE);
}

/*         --------------------------------------         */
/*         ------------    HELPERS   ------------         */
/*         --------------------------------------         */

/*         -------    COUNT_DC_WORDS    -------         */
void count_directive_words(char *line, char *directive, int *DC, int *err_flag, int LC)
{
    if (is_data_directive(directive))
        count_data_param(line, DC, err_flag, LC);

    else if (is_string_directive(directive))
        count_string_param(line, DC, err_flag, LC);

    else if (is_struct_directive(directive))
        count_struct_param(line, DC, err_flag, LC);
}

void count_data_param(char *line, int *DC, int *err_flag, int LC)
{
    char param[LINE_LEN];
    get_next_field(line, param, COMMA);

    /* first param*/
    if (*param == '\0')
        err_few(param, err_flag, LC);
    else if (!is_number(param))
        err_must_int(param, err_flag, LC);
    else
        (*DC)++;

    /* rest of params , if any*/
    while (!is_empty_line(line))
    {
        get_next_field(line, param, COMMA);
        if (!is_number(param))
            err_must_int(param, err_flag, LC);
        else
            (*DC)++;
    }
}

void count_string_param(char *line, int *DC, int *err_flag, int LC)
{
    char param[LINE_LEN];
    int param_length;
    get_next_field(line, param, '\0');
    if (!is_string(param))
    {
        if (*param == '\0')
            err_few(param, err_flag, LC);
        else
            err_must_str(param, err_flag, LC);
    }
    else
    {
        param_length = strlen(param) - 2; /* -2 for quotation marks; */
        (*DC) = (*DC) + param_length + 1; /* +1 for '\0' */
    }
}

void count_struct_param(char *line, int *DC, int *err_flag, int LC)
{
    char field_num[LINE_LEN];
    get_next_field(line, field_num, COMMA);

    if (is_number(field_num))
        (*DC)++;
    else
    {
        if (*field_num == '\0')
            err_few(field_num, err_flag, LC);
        else
            err_struct_must_int(field_num, err_flag, LC);
    }

    count_string_param(line, DC, err_flag, LC);
}

/*         -------    EXTERN & ENTRY PARAMS    -------         */
void insert_extern_param(char *line, int *err_flag, int LC)
{
    char param[LINE_LEN];
    int directive_flag = true, is_ext = true, address = false;

    get_next_field(line, param, '\0');
    if (!is_symbol_valid(param))
    {
        if (*param == '\0')
            err_few(param, err_flag, LC);
        else
            err_must_sym(param, err_flag, LC);
    }
    else
        insert_symbol(param, address, directive_flag, is_ext);
}

void valid_entry_param(char *line, int *err_flag, int LC)
{
    char param[LINE_LEN];
    get_next_field(line, param, '\0');
    if (!is_symbol_valid(param))
    {
        if (*param == '\0')
            err_few(param, err_flag, LC);
        else
            err_must_sym(param, err_flag, LC);
    }
}

/*         -------    COUNT_OPERANDS_WORDS    -------         */
void count_operands_words(char *line, char *instruction, int *IC, int *err_flag, int LC)
{
    char src_operand[LINE_LEN], trg_operand[LINE_LEN];
    int expected_operands = get_num_of_operands(is_instruction(instruction));
    int register_flag = false;

    /* IF ONLY TARGET OPERAND */
    if (expected_operands == 1)
    {
        get_next_field(line, trg_operand, SPACE);
        if (!is_target_operand_valid(trg_operand, instruction)) /* if invalid */
        {
            if (*trg_operand == '\0')
                err_few(trg_operand, err_flag, LC);
            else
                err_invalid(trg_operand, err_flag, LC);
        }
        else /* count instruction words */
            (*IC) = (*IC) + num_of_operand_words(trg_operand, &register_flag);
    }

    /* IF SOURCE && TARGET OPERAND */
    else if (expected_operands == 2)
    {
        get_next_field(line, src_operand, COMMA);
        get_next_field(line, trg_operand, SPACE);
        if (!is_source_operand_valid(src_operand, instruction)) /* if invalid */
        {
            if (*src_operand == '\0')
                err_few(src_operand, err_flag, LC);
            else
                err_invalid(src_operand, err_flag, LC);
        }
        else /* count instruction words */
            (*IC) = (*IC) + num_of_operand_words(src_operand, &register_flag);

        if (!is_target_operand_valid(trg_operand, instruction)) /* if invalid */
        {
            if (*trg_operand == '\0')
                err_few(trg_operand, err_flag, LC);
            else
                err_invalid(trg_operand, err_flag, LC);
        }
        else /* count instruction words */
            (*IC) = (*IC) + num_of_operand_words(trg_operand, &register_flag);
    }
}

int num_of_operand_words(char *operand, int *register_flag)
{
    if (is_register(operand) != INVALID) /* if its register */
    {
        if (*register_flag)
            return 0;
        (*register_flag) = true;
        return 1;
    }
    if (is_operand_number(operand))
        return 1;
    if (is_operand_struct_valid(operand))
        return 2;
    if (is_symbol_valid(operand))
        return 1;
    return INVALID; /* invalid operand */
}