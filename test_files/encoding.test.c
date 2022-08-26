void test_encode_data_directive_param()
{
    int DC = 0;
    char ten[] = "10";
    printf("\n-------------------  encode_data_directive_param  -------------------\n");
    encode_data_directive_param("17", &DC);
    encode_data_directive_param(ten, &DC);
    encode_data_directive_param("-9", &DC);
}

void test_encode_string_directive_param()
{
    int DC = 0;
    char abc[] = "abcdef";
    printf("\n-------------------  encode_string_directive_param  -------------------\n");
    encode_string_directive_param(abc, &DC);
    encode_string_directive_param("hello", &DC);
    encode_string_directive_param("s1", &DC);
}

void test_encode_struct_directive_param()
{
    int DC = 0;
    char struct1[] = "8, \"abcdef\"";
    char struct2[] = "7,\"hello\"";
    char struct3[] = "6,   \"s1\"";
    char struct4[] = "-6, \"s2\"";

    printf("\n-------------------  encode_struct_directive_param  -------------------\n");
    encode_struct_directive_param(struct1, &DC);
    encode_struct_directive_param(struct2, &DC);
    encode_struct_directive_param(struct3, &DC);
    encode_struct_directive_param(struct4, &DC);
}

void test_encode_number(int *is_source_operand, int *IC)
{
    int num1 = 4;
    int num2 = -4;
    int num3 = 6;
    int num4 = -6;
    int num5 = 9;
    int num6 = -9;
    int num7 = 127;  // the greates number operand
    int num8 = -128; // the smallest number operand

    printf("\n-------------------  encode_number  -------------------\n");
    encode_number(num1, IC);
    encode_number(num2, IC);
    encode_number(num3, IC);
    encode_number(num4, IC);
    encode_number(num5, IC);
    encode_number(num6, IC);
    encode_number(num7, IC);
    encode_number(num8, IC);
}

void test_encode_symbole_address()
{
    int IC = 0;
    char struct1[] = "STRSTRS";
    char struct2[] = "abcdefg";
    char struct3[] = "hello";

    printf("\n-------------------  encode_symbole_address  -------------------\n");
    encode_symbole_address(struct1, &IC);
    encode_symbole_address(struct2, &IC);
    encode_symbole_address(struct3, &IC);
}

void test_encode_register(int *is_source_reg, int *IC)
{
    int reg1 = 1;
    int reg2 = 2;
    int reg3 = 3;
    int reg4 = 4;
    int reg5 = 5;
    int reg6 = 6;
    int reg7 = 7;
    int reg0 = 0;

    printf("\n-------------------  encode_register  -------------------\n");
    // source then target
    encode_register(reg1, "source", is_source_reg, IC);
    encode_register(reg2, "target", is_source_reg, IC);
    (*is_source_reg) = false;

    //---- only source
    encode_register(reg7, "source", is_source_reg, IC);
    (*is_source_reg) = false;

    //---- only target
    encode_register(reg4, "target", is_source_reg, IC);
    (*is_source_reg) = false;

    //---- only source
    encode_register(reg0, "source", is_source_reg, IC);
    (*is_source_reg) = false;

    //---- only target
    encode_register(reg0, "target", is_source_reg, IC);
    (*is_source_reg) = false;
}

void test_encode_operand(int *is_source_reg, int *IC)
{
    char num1[] = "#1";
    char num2[] = "#2";
    char struct1[] = "STRSTRS.6";
    char struct2[] = "abcdefg.7";
    char sym1[] = "hello";
    char sym2[] = "HELLO";
    char reg1[] = "r1";
    char reg2[] = "r2";

    printf("\n-------------------  encode_operand  -------------------\n");
    printf("//--Operand: %s\n", num1);
    encode_operand(num1, NULL, NULL, IC);
    printf("//--Operand: %s\n", num2);
    encode_operand(num2, NULL, NULL, IC);
    printf("//--Operand: %s\n", struct1);
    encode_operand(struct1, NULL, NULL, IC);
    printf("//--Operand: %s\n", struct2);
    encode_operand(struct2, NULL, NULL, IC);
    printf("//--Operand: %s\n", sym1);
    encode_operand(sym1, NULL, NULL, IC);
    printf("//--Operand: %s\n", sym2);
    encode_operand(sym2, NULL, NULL, IC);
    printf("//--Operand: %s\n", reg1);
    encode_operand(reg1, "source", is_source_reg, IC);
    printf("Operand: %s\n", reg2);
    encode_operand(reg2, "target", is_source_reg, IC);
}

void test_encode_first_word(int *IC)
{
    int opcode;
    char *source_operand, target_operand;

    char src_opr_1[] = "SRTSRTS.6";
    char trg_opr_1[] = "hello";
    char src_opr_2[] = "r2";
    char trg_opr_2[] = "hello";
    char src_opr_3[] = "SRTSRTS.6";
    char trg_opr_3[] = "abcdefg";
    char src_opr_4[] = "r1";
    char trg_opr_4[] = "r4";
    char src_opr_5[] = "SRTSRTS.6";
    char trg_opr_5[] = "hello";
    char src_opr_6[] = "SRTSRTS.6";
    char trg_opr_6[] = "#-5";
    char trg_opr_7[] = "#@";

    printf("\n-------------------  encode first word  -------------------\n");
    encode_first_word(MOV, src_opr_1, trg_opr_1, IC);
    encode_first_word(ADD, src_opr_2, trg_opr_2, IC);
    encode_first_word(JMP, NULL, trg_opr_3, IC);
    encode_first_word(PRN, NULL, trg_opr_6, IC);
    encode_first_word(SUB, src_opr_4, trg_opr_4, IC);
    encode_first_word(HLT, NULL, NULL, IC);
    encode_first_word(SUB, src_opr_4, "#2", IC);
    encode_first_word(HLT, trg_opr_1, NULL, IC);
    encode_first_word(SUB, src_opr_4, trg_opr_7, IC);
    encode_first_word(HLT, NULL, trg_opr_1, IC);
}