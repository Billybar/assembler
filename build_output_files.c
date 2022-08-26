#include "build_output_files.h"

void build_output_files(char *file_name, int DC)
{
    FILE *src_code;
    char am_file[LINE_LEN], line[LINE_LEN], symbol[LINE_LEN];
    char symbol_field[LINE_LEN], main_field[LINE_LEN]; /* first 2 fields in line*/
    int err_flag = false;                              /* flag */
    int IC = LOADING_ADDR, LC = 0;                     /* counters */

    strcpy(am_file, file_name);
    if (!(src_code = fopen(strcat(am_file, ".am"), "r")))
        perror(__FILE__);

    while ((fgets(line, LINE_LEN, src_code)) != NULL)
    {
        LC++; /* line counter*/
        if (!is_line_length_valid(line) || is_empty_line(line) || is_comment_line(line))
            continue;

        /*         -------    IS_SYMBOL_DEFINE    -------         */
        get_next_field(line, symbol_field, SPACE);
        if (is_symbol_definition(symbol_field, symbol))
            get_next_field(line, main_field, SPACE);
        else
            strncpy(main_field, symbol_field, LINE_LEN);

        /*         -------    IS_DIRECTIVE_LINE    -------         */
        if (is_directive(main_field))
            encode_directive(line, main_field, file_name, &err_flag, &DC, LC);

        /*         -------    IS_INSTRUCTION_LINE    -------         */
        else if (is_instruction(main_field) != INVALID)
            encode_instruction(line, main_field, file_name, &err_flag, &IC, LC);
    }

    if (!err_flag)
        build_ob_file(file_name, DC, IC);
    fclose(src_code);
    free_symbol_list();
    if (err_flag)
        exit(EXIT_FAILURE);
}

void build_ob_file(char *file_name, int DC, int IC)
{
    FILE *ob_file;
    char name[LINE_LEN], address[5] = {0}, code[5] = {0}, IC_len[4] = {0}, DC_len[4] = {0};
    int IC_mem[MEMORY_LENGHT], DC_mem[MEMORY_LENGHT];
    int i = LOADING_ADDR;

    strcpy(name, file_name);
    strcat(name, ".ob");
    ob_file = fopen(name, "w");
    get_encoded_memory(IC_mem, DC_mem); /* get data from encoding local globals */

    dec_to_base32(IC_len, (IC - LOADING_ADDR));
    dec_to_base32(DC_len, (DC - IC));

    /* trim '!' in headline */
    if (*IC_len == '!')
        memmove(IC_len, IC_len + 1, strlen(IC_len));
    if (*DC_len == '!')
        memmove(DC_len, DC_len + 1, strlen(DC_len));
    /* --------------------------- */

    /* print headline */
    fprintf(ob_file, "%s %s\n", IC_len, DC_len);

    /* print INSTRUCTION memory */
    for (; i < IC; i++)
    {
        dec_to_base32(address, i);
        dec_to_base32(code, ((unsigned)IC_mem[i]));
        fprintf(ob_file, "%s\t%s\n", address, code);
    }

    /* print DIRCTIVE memory */
    for (; i < DC; i++)
    {
        dec_to_base32(address, i);
        dec_to_base32(code, DC_mem[i]);
        fprintf(ob_file, "%s\t%s\n", address, code);
    }

    fclose(ob_file);
}

void build_ent_file(char *file_name, char *symbol)
{
    FILE *ent_file;
    struct Symbol *ent_symbol;
    char name[LINE_LEN], base32_num[5] = {0};
    strcpy(name, file_name);
    strcat(name, ".ent");

    ent_file = fopen(name, "a");

    ent_symbol = get_symbol(symbol);
    dec_to_base32(base32_num, ent_symbol->address);
    fprintf(ent_file, "%s\t%s\n", ent_symbol->name, base32_num);

    fclose(ent_file);
}

void build_ext_file(char *symbol, char *file_name, int IC)
{
    FILE *ext_file;
    char name[LINE_LEN], base32_num[5] = {0};
    strcpy(name, file_name);
    strcat(name, ".ext");

    IC--; /* go back to operand address */
    ext_file = fopen(name, "a");

    dec_to_base32(base32_num, IC);
    fprintf(ext_file, "%s\t%s\n", symbol, base32_num);

    fclose(ext_file);
}

void dec_to_base32(char *dest, unsigned int num)
{
    int base = 32;
    char chars[] = "!@#$%^&*<>abcdefghijklmnopqrstuv";
    dest[1] = chars[num % base];
    num /= base;
    dest[0] = chars[num % base];
}

void encode_directive(char *line, char *direc, char *f_name, int *err_flag, int *DC, int LC)
{
    char param[LINE_LEN];

    if (is_data_directive(direc)) /* data */
    {
        while (!is_empty_line(line))
        {
            get_next_field(line, param, COMMA);
            encode_data_directive_param(param, DC);
        }
    }

    get_next_field(line, param, '\0');

    if (is_string_directive(direc)) /* string */
        encode_string_directive_param(param, DC);

    else if (is_struct_directive(direc)) /* struct */
        encode_struct_directive_param(param, DC);

    else if (is_entry_directive(direc)) /* entry */
    {
        if (!is_symbol_exist(param))
            err_not_exist(param, err_flag, LC);
        else
            build_ent_file(f_name, param);
    }
}

void encode_instruction(char *line, char *instrct, char *f_name, int *err_flag, int *IC, int LC)
{
    char src_operand[LINE_LEN] = {0}, trg_operand[LINE_LEN] = {0};
    int expected_operands = get_num_of_operands(is_instruction(instrct));
    int reg_flag = false, opcode = get_opcode(instrct);

    /* --- EXTRACT OPERANDS --- */
    if (expected_operands == 1)
        get_next_field(line, trg_operand, '\0');
    if (expected_operands == 2)
    {
        get_next_field(line, src_operand, COMMA);
        get_next_field(line, trg_operand, '\0');
    }

    /* --- ENCODE FIRST WORD --- */
    encode_first_word(opcode, src_operand, trg_operand, IC, err_flag, LC);

    /* --- ENCODE OPERANDS --- */
    if (*src_operand)
        encode_operand(src_operand, "source", &reg_flag, IC, err_flag, LC);
    if (*trg_operand)
        encode_operand(trg_operand, "target", &reg_flag, IC, err_flag, LC);

    /* --- APPEND TO EXT FILE --- */
    if (is_symbol_exist(src_operand) && is_symbol_extern(src_operand))
        build_ext_file(src_operand, f_name, *IC);
    if (is_symbol_exist(trg_operand) && is_symbol_extern(trg_operand))
        build_ext_file(trg_operand, f_name, *IC);
}