// void test_count_data_param(char *line_1, int *DC)
// {
//     printf("\n-------------------  count_data_param  -------------------\n");
//     printf("\n//--- LINE 1\n");
//     printf("line: _%s\n", line_1);
//     count_data_param(line_1, DC);
//     printf("line: _%s_\n", line_1);
// }

// void test_count_string_param(char *line_1, int *DC)
// {
//     printf("\n-------------------  count_string_param  -------------------\n");
//     printf("\n//--- LINE 1\n");
//     printf("line: _%s_\n", line_1);
//     count_string_param(line_1, DC);
//     printf("line: _%s_\n", line_1);
// }

// void test_count_struct_param(char *line_1, int *DC)
// {
//     printf("\n-------------------  count_struct_param  -------------------\n");
//     printf("\n//--- LINE 1\n");
//     printf("line: _%s_\n", line_1);
//     count_struct_param(line_1, DC);
//     printf("line: _%s_\n", line_1);
// }

// void test_insert_extern_param(char *line_1)
// {
//     printf("\n-------------------  insert_extern_param  -------------------\n");
//     printf("\n//--- LINE 1\n");
//     printf("line: _%s_\n", line_1);
//     insert_extern_param(line_1);
//     printf("line: _%s_\n", line_1);
// }

// void test_valid_entry_param(char *line_1)
// {
//     printf("\n-------------------  valid_entry_param  -------------------\n");
//     printf("\n//--- LINE 1\n");
//     printf("line: _%s_\n", line_1);
//     valid_entry_param(line_1);
//     printf("line: _%s_\n", line_1);
// }

// void test_num_of_operand_words()
// {
//     int reg_flag = false;
//     char opr_1[] = "#1";
//     char opr_2[] = "symbole";
//     char opr_3[] = "struct.1";
//     char opr_4[] = "r1";
//     char opr_5[] = "r2";
//     char opr_6[] = "";

//     printf("\n-------------------  num_of_operand_words  -------------------\n");
//     printf("Operand: _%s_\tReg_flag: %d\n", opr_1, reg_flag);
//     printf("%d\n", num_of_operand_words(opr_1, &reg_flag));
//     printf("Operand: _%s_\tReg_flag: %d\n", opr_2, reg_flag);
//     printf("%d\n", num_of_operand_words(opr_2, &reg_flag));
//     printf("Operand: _%s_\tReg_flag: %d\n", opr_3, reg_flag);
//     printf("%d\n", num_of_operand_words(opr_3, &reg_flag));
//     printf("Operand: _%s_\tReg_flag: %d\n", opr_4, reg_flag);
//     printf("%d\n", num_of_operand_words(opr_4, &reg_flag));
//     printf("Operand: _%s_\tReg_flag: %d\n", opr_5, reg_flag);
//     printf("%d\n", num_of_operand_words(opr_5, &reg_flag));
//     printf("Operand: _%s_\tReg_flag: %d\n", opr_6, reg_flag);
//     printf("%d\n", num_of_operand_words(opr_6, &reg_flag));
// }

// void test_count_operands_words(char *line_1, int *IC)
// {
//     char instr_1[] = "mov";
//     char instr_2[] = "not";
//     char instr_3[] = "hlt";

//     printf("\n-------------------  count_operands_words  -------------------\n");
//     printf("line: _%s_\n", line_1);
//     count_operands_words(line_1, instr_3, IC);
// }

void test_build_symbole_table(char *file_name, int *dir_addr)
{
    build_symbole_table(file_name, dir_addr);
}