#include "encoding.h"

/* local globals */
static int DC_memory[MEMORY_LENGHT] = {0};
static int IC_memory[MEMORY_LENGHT] = {0};

/* --------------- encode directive params ---------- */
void encode_data_directive_param(char *param, int *DC)
{
    DC_memory[(*DC)] = atoi(param);
    (*DC)++;
}

void encode_string_directive_param(char *param, int *DC)
{
    char str[LINE_LEN];
    int i = 0, str_len;
    if (strlen(param) < 3) /* avoiding segFalut; been extra safe*/
        return;

    strncpy(str, (param + 1), (strlen(param) - 1)); /*trim quotation mark*/
    str[strlen(param) - 2] = '\0';
    str_len = strlen(str);

    for (; i < str_len; i++)
    {
        DC_memory[(*DC)] = (int)(*(str + i));
        (*DC)++;
    }
    DC_memory[(*DC)] = 0; /*add null*/
    (*DC)++;
}

void encode_struct_directive_param(char *param, int *DC)
{
    int i, number, str_length;
    char number_field[82];
    char str_field[82];
    get_next_field(param, number_field, COMMA);
    get_next_field(param, str_field, SPACE);

    number = atoi(number_field);
    str_length = strlen(str_field);

    DC_memory[(*DC)] = number; /* encode number field */
    (*DC)++;

    for (i = 1; i < str_length - 1; i++) /* encode string field */
    {
        DC_memory[(*DC)] = (int)(*(str_field + i));
        (*DC)++;
    }

    DC_memory[(*DC)] = 0; /* add null */
    (*DC)++;
}

/* --------------- encode instruction word ---------- */
void encode_first_word(int opcode, char *src_operand, char *trg_operand, int *IC, int *err_flag, int LC)
{
    int src_addr_method, trg_addr_method;

    opcode = opcode << SIXTH_BIT;

    if (*src_operand)
        src_addr_method = get_address_method(src_operand, FOURTH_BIT, err_flag, LC);
    else
        src_addr_method = 0; /* no src operand */

    if (*trg_operand)
        trg_addr_method = get_address_method(trg_operand, SECOND_BIT, err_flag, LC);
    else
        trg_addr_method = 0; /* no trg operand */

    IC_memory[(*IC)] = opcode | src_addr_method | trg_addr_method;
    (*IC)++;
}

int get_address_method(char *operand, int bit_position, int *err_flag, int LC)
{
    int addr_method = is_operand_valid(operand);

    if (addr_method == INVALID)
    {
        err_invalid(operand, err_flag, LC);
        return false;
    }
    else
        return (addr_method << bit_position);
}

/* --------------- encode operand ---------- */
void encode_operand(char *operand, char *operand_type, int *is_src_reg, int *IC, int *err_flag, int LC)
{
    int reg_num, field_number;
    char symbol[SYMBOL_NAME_MAX_LENGTH];

    if (is_operand_number(operand))
    {
        int num = atoi((operand + 1)); /* +1 for skiping '#' */
        encode_number(num, IC);
    }

    else if ((reg_num = is_register(operand)) != INVALID) /* if its register */
        encode_register(reg_num, operand_type, is_src_reg, IC);

    else if (is_operand_symbol(operand))
        encode_symbol_address(operand, IC);

    else if (is_operand_struct(operand, symbol, &field_number))
    {
        encode_symbol_address(symbol, IC);
        encode_number(field_number, IC);
    }

    else /* invalid operand */
        err_unknwon(operand, err_flag, LC);
}

/* --------------- encode_operand Helpers ---------- */
void encode_register(int reg_num, char *operand_type, int *is_src_reg, int *IC)
{
    if (strcmp(operand_type, "target") == 0)
    {
        if (*is_src_reg) /* if source and target operands is register*/
        {
            (*IC)--; /* use same word with source operand */
            IC_memory[(*IC)] = (IC_memory[(*IC)] | (reg_num << SECOND_BIT));
        }
        else
        {
            IC_memory[(*IC)] = (reg_num << SECOND_BIT);
        }
    }
    else if (strcmp(operand_type, "source") == 0)
    {
        (*is_src_reg) = true;
        IC_memory[(*IC)] = reg_num << SIXTH_BIT;
    }
    (*IC)++;
}

void encode_number(int number, int *IC)
{
    IC_memory[(*IC)] = (number << SECOND_BIT); /* ARE = 0 */
    (*IC)++;
}

void encode_symbol_address(char *symbol, int *IC)
{
    int ARE, symbol_address;

    if (is_symbol_extern(symbol))
        IC_memory[(*IC)] = 1; /* ARE = 1 , address = 0 */
    else                      /*  not extern symbole  */
    {
        ARE = 2;
        symbol_address = get_symbol(symbol)->address;
        symbol_address <<= SECOND_BIT; /* move bits */
        IC_memory[(*IC)] = (symbol_address | ARE);
    }
    (*IC)++;
}

void get_encoded_memory(int *IC_mem, int *DC_mem)
{
    memcpy(IC_mem, IC_memory, MEMORY_LENGHT * sizeof(int));
    memcpy(DC_mem, DC_memory, MEMORY_LENGHT * sizeof(int));
}
