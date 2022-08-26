void test_is_instruction()
{
        printf("\n-------------------  is_instruction  -------------------\n");
        printf("is_instruction(\"mov\"): \t%d\n", is_instruction("mov"));
        printf("is_instruction(\"cmp\"): \t%d\n", is_instruction("cmp"));
        printf("is_instruction(\"add\"): \t%d\n", is_instruction("add"));
        printf("is_instruction(\"sub\"): \t%d\n", is_instruction("sub"));
        printf("is_instruction(\"not\"): \t%d\n", is_instruction("not"));
        printf("is_instruction(\"clr\"): \t%d\n", is_instruction("clr"));
        printf("is_instruction(\"lea\"): \t%d\n", is_instruction("lea"));
        printf("is_instruction(\"inc\"): \t%d\n", is_instruction("inc"));
        printf("is_instruction(\"dec\"): \t%d\n", is_instruction("dec"));
        printf("is_instruction(\"jmp\"): \t%d\n", is_instruction("jmp"));
        printf("is_instruction(\"bne\"): \t%d\n", is_instruction("bne"));
        printf("is_instruction(\"get\"): \t%d\n", is_instruction("get"));
        printf("is_instruction(\"prn\"): \t%d\n", is_instruction("prn"));
        printf("is_instruction(\"jsr\"): \t%d\n", is_instruction("jsr"));
        printf("is_instruction(\"rts\"): \t%d\n", is_instruction("rts"));
        printf("is_instruction(\"hlt\"): \t%d\n", is_instruction("hlt"));
        printf("is_instruction(\"hl\"): \t%d\n", is_instruction("hl"));
        printf("is_instruction(\" \"): \t%d\n", is_instruction(" "));
        printf("is_instruction(\"Mov\"): \t%d\n", is_instruction("Mov"));
}

void test_is_register()
{
        printf("\n-------------------  is_register  -------------------\n");
        printf("is_register(\"r0\"): \t%d\n", is_register("r0"));
        printf("is_register(\"r1\"): \t%d\n", is_register("r1"));
        printf("is_register(\"r2\"): \t%d\n", is_register("r2"));
        printf("is_register(\"r3\"): \t%d\n", is_register("r3"));
        printf("is_register(\"r4\"): \t%d\n", is_register("r4"));
        printf("is_register(\"r5\"): \t%d\n", is_register("r5"));
        printf("is_register(\"r6\"): \t%d\n", is_register("r6"));
        printf("is_register(\"r7\"): \t%d\n", is_register("r7"));
        printf("is_register(\"r8\"): \t%d\n", is_register("r8"));
        printf("is_register(\"r9\"): \t%d\n", is_register("r9"));
        printf("is_register(\"r10\"): \t%d\n", is_register("r10"));
        printf("is_register(\"R0\"): \t%d\n", is_register("R0"));
        printf("is_register(\"R1\"): \t%d\n", is_register("R1"));
        printf("is_register(\"\"): \t%d\n", is_register(""));
}

void test_is_number()
{
        printf("\n-------------------  is_number  -------------------\n");
        printf("is_number(+1): \t%d\n", is_number("+1"));
        printf("is_number(-2): \t%d\n", is_number("-2"));
        printf("is_number(34): \t%d\n", is_number("34"));
        printf("is_number(-34): \t%d\n", is_number("-34"));
        printf("is_number(+34): \t%d\n", is_number("+34"));
        printf("is_number(a): \t%d\n", is_number("a"));
        printf("is_number(א): \t%d\n", is_number("א"));
        printf("is_number(.1): \t%d\n", is_number(".1"));
        printf("is_number(1.1): \t%d\n", is_number("1.1"));
        printf("is_number(+): \t%d\n", is_number("+"));
        printf("is_number(511): \t%d\n", is_number("511"));
        printf("is_number(-512): \t%d\n", is_number("-512"));
        printf("is_number(512): \t%d\n", is_number("512"));
        printf("is_number(-513): \t%d\n", is_number("-513"));
}

void test_is_string()
{
        printf("\n-------------------  is_string  -------------------\n");
        printf("is_string(\"abcde\"): \t%d\n", is_string("\"abcde\""));
        printf("is_string(\"abcde): \t%d\n", is_string("\"abcde"));
        printf("is_string(abcde\"): \t%d\n", is_string("abcde\""));
        printf("is_string(a\"abcde\"): \t%d\n", is_string("a\"abcde\""));
        printf("is_string(\"abcde\"d): \t%d\n", is_string("\"abcde\"d"));
        printf("is_string(\"a'9'a\") \t%d\n", is_string("\"a'6'a\""));
        printf("is_string(\"a'9'a\") \t%d\n", is_string("\"asdfghjkl\""));
        printf("is_string(\"a'9'a\") \t%d\n", is_string("\"a sdfghjkl\""));
        printf("is_string(\"a'9'a\") \t%d\n", is_string("\"a    sdfghjkl\""));
        printf("is_string(\"a'9'a\") \t%d\n", is_string("\' asdfghjkl\'"));
        printf("is_string(\"\") \t%d\n", is_string("\"\""));
        printf("is_string(\"\") \t%d\n", is_string("\""));
}

//--- IS_MACRO
void test_is_macro_definition()
{
        printf("\n-------------------  is_macro_definition  -------------------\n");
        printf("is_macro_definition(\"macro\"): \t%d\n", is_macro_definition("macro"));
        printf("is_macro_definition(\"Macro\"): \t%d\n", is_macro_definition("Macro"));
        printf("is_macro_definition(\"macr\"): \t%d\n", is_macro_definition("macr"));
        printf("is_macro_definition(\"macroo\"): \t%d\n", is_macro_definition("macroo"));
        printf("is_macro_definition(\"\"): \t%d\n", is_macro_definition(""));
}

//--- IS_SYMBOLE
void test_is_symbole_definition()
{
        char symbole[30] = "\0";
        printf("\n-------------------  is_symbole_definition  -------------------\n");
        printf("is_symbole_definition(\"A   A:\"): \t%d\n", is_symbole_definition("A    A:", symbole));
        printf("is_symbole_definition(\"abc:\"): \t%d\n", is_symbole_definition("abc:", symbole));
        printf("is_symbole_definition(\"abc\"): \t%d\n", is_symbole_definition("abc", symbole));
        printf("is_symbole_definition(\"r1:\"): \t%d\n", is_symbole_definition("r1:", symbole));
        printf("is_symbole_definition(\"mov:\"): \t%d\n", is_symbole_definition("mov:", symbole));
        printf("is_symbole_definition(\"ABC:\"): \t%d\n", is_symbole_definition("ABC:", symbole));
        printf("is_symbole_definition(\"ab2:\"): \t%d\n", is_symbole_definition("ab2:", symbole));
        printf("is_symbole_definition(\"AB3:\"): \t%d\n", is_symbole_definition("AB3:", symbole));
        printf("is_symbole_definition(\"aB4:\"): \t%d\n", is_symbole_definition("aB4:", symbole));
        printf("is_symbole_definition(\"1:\"): \t%d\n", is_symbole_definition("1:", symbole));
        printf("is_symbole_definition(\"123:\"): \t%d\n", is_symbole_definition("123:", symbole));
        printf("is_symbole_definition(\"012:\"): \t%d\n", is_symbole_definition("012:", symbole));
        printf("is_symbole_definition(\"_12:\"): \t%d\n", is_symbole_definition("_12:", symbole));
        printf("is_symbole_definition(\"!@:\"): \t%d\n", is_symbole_definition("!@:", symbole));
        printf("is_symbole_definition(\"#:\"): \t%d\n", is_symbole_definition("r#:", symbole));
        printf("is_symbole_definition(\"%%:\"): \t%d\n", is_symbole_definition("%%:", symbole));
        printf("is_symbole_definition(\"^:\"): \t%d\n", is_symbole_definition("^:", symbole));
        printf("is_symbole_definition(\"&:\"): \t%d\n", is_symbole_definition("&:", symbole));
        printf("is_symbole_definition(\"::\"): \t%d\n", is_symbole_definition("::", symbole));
        printf("is_symbole_definition(\"=:\"): \t%d\n", is_symbole_definition("=:", symbole));
        printf("is_symbole_definition(\"+:\"): \t%d\n", is_symbole_definition("+:", symbole));
        printf("is_symbole_definition(\"a-1:\"): \t%d\n", is_symbole_definition("a-1:", symbole));
        printf("is_symbole_definition(\"a+2:\"): \t%d\n", is_symbole_definition("a+2:", symbole));
        printf("is_symbole_definition(\"a:1\"): \t%d\n", is_symbole_definition("a:1", symbole));
        printf("is_symbole_definition(\"a:a\"): \t%d\n", is_symbole_definition("a:a", symbole));
        printf("is_symbole_definition(\"a::\"): \t%d\n", is_symbole_definition("a::", symbole));
        printf("is_symbole_definition(\"A A:\"): \t%d\n", is_symbole_definition("A A:", symbole));
        printf("is_symbole_definition(\"A   A:\"): \t%d\n", is_symbole_definition("A    A:", symbole));
        printf("is_symbole_definition(\"aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA:\"): \t%d\n", is_symbole_definition("aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA:", symbole));
        printf("is_symbole_definition(\"a12345678901234567890123456789:\"): \t%d\n", is_symbole_definition("a12345678901234567890123456789:", symbole));
}

void test_is_symbole_valid()
{
        printf("\n-------------------  is_symbole_valid  -------------------\n");
        printf("is_symbole_valid(\"A   A\"): \t%d\n", is_symbole_valid("A    A:"));
        printf("is_symbole_valid(\"abc\"): \t%d\n", is_symbole_valid("abc"));
        printf("is_symbole_valid(\"abc\"): \t%d\n", is_symbole_valid("abc"));
        printf("is_symbole_valid(\"r1\"): \t%d\n", is_symbole_valid("r1"));
        printf("is_symbole_valid(\"mov\"): \t%d\n", is_symbole_valid("mov"));
        printf("is_symbole_valid(\"ABC\"): \t%d\n", is_symbole_valid("ABC"));
        printf("is_symbole_valid(\"ab2\"): \t%d\n", is_symbole_valid("ab2"));
        printf("is_symbole_valid(\"AB3\"): \t%d\n", is_symbole_valid("ABC"));
        printf("is_symbole_valid(\"aB4\"): \t%d\n", is_symbole_valid("aB4:"));
        printf("is_symbole_valid(\"1\"): \t%d\n", is_symbole_valid("1"));
        printf("is_symbole_valid(\"123\"): \t%d\n", is_symbole_valid("123"));
        printf("is_symbole_valid(\"012:\"): \t%d\n", is_symbole_valid("012:"));
        printf("is_symbole_valid(\"_12:\"): \t%d\n", is_symbole_valid("_12:"));
        printf("is_symbole_valid(\"!@:\"): \t%d\n", is_symbole_valid("!@:"));
        printf("is_symbole_valid(\"#:\"): \t%d\n", is_symbole_valid("r#:"));
        printf("is_symbole_valid(\"%%:\"): \t%d\n", is_symbole_valid("%%:"));
        printf("is_symbole_valid(\"^:\"): \t%d\n", is_symbole_valid("^:"));
        printf("is_symbole_valid(\"&:\"): \t%d\n", is_symbole_valid("&:"));
        printf("is_symbole_valid(\"::\"): \t%d\n", is_symbole_valid("::"));
        printf("is_symbole_valid(\"=:\"): \t%d\n", is_symbole_valid("=:"));
        printf("is_symbole_valid(\"+:\"): \t%d\n", is_symbole_valid("+:"));
        printf("is_symbole_valid(\"a-1\"): \t%d\n", is_symbole_valid("a-1"));
        printf("is_symbole_valid(\"a+2\"): \t%d\n", is_symbole_valid("a+2"));
        printf("is_symbole_valid(\"a:1\"): \t%d\n", is_symbole_valid("a:1"));
        printf("is_symbole_valid(\"-1\"): \t%d\n", is_symbole_valid("-1"));
        printf("is_symbole_valid(\"a\"): \t%d\n", is_symbole_valid("a"));
        printf("is_symbole_valid(\"A A\"): \t%d\n", is_symbole_valid("A A"));
        printf("is_symbole_valid(\"A   A\"): \t%d\n", is_symbole_valid("A    A"));
        printf("is_symbole_valid(\"aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\"): \t%d\n", is_symbole_valid("aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
        printf("is_symbole_valid(\"a12345678901234567890123456789\"): \t%d\n", is_symbole_valid("a12345678901234567890123456789"));
}

void test_is_symbole_exist()
{
        char str_1[] = "STRSTRS";
        char str_2[] = "abcdefg";
        char str_3[] = "hello";
        char str_4[] = "HELLo";

        printf("\n-------------------  is_symbole_exist  -------------------\n");

        printf("%d\n", is_symbole_exist(str_1));
        printf("%d\n", is_symbole_exist(str_2));
        printf("%d\n", is_symbole_exist(str_3));
        printf("%d\n", is_symbole_exist(str_4));
}

void test_is_symbole_extern()
{
        char str_1[] = "STRSTRS";
        char str_2[] = "abcdefg";
        char str_3[] = "hello";
        char str_4[] = "HELLo";

        printf("\n-------------------  is_symbole_extern  -------------------\n");

        printf("%d\n", is_symbole_extern(str_1));
        printf("%d\n", is_symbole_extern(str_2));
        printf("%d\n", is_symbole_extern(str_3));
        printf("%d\n", is_symbole_extern(str_4));
}

//--- IS_DIRECTIVE
void test_is_data_directive()
{
        printf("\n-------------------  is_data_directive  -------------------\n");
        printf("is_data_directive(.data): \t%d\n", is_data_directive(".data"));
        printf("is_data_directive(data): \t%d\n", is_data_directive("data"));
        printf("is_data_directive(.dataa): \t%d\n", is_data_directive(".dataa"));
        printf("is_data_directive(.ddata): \t%d\n", is_data_directive(".ddata"));
        printf("is_data_directive(1): \t%d\n", is_data_directive("1"));
        printf("is_data_directive(.dataa): \t%d\n", is_data_directive(".dataa"));
        printf("is_data_directive(): \t%d\n", is_data_directive(""));
}

void test_is_string_directive()
{
        printf("\n-------------------  is_string_directive  -------------------\n");
        printf("is_string_directive(.string): \t%d\n", is_string_directive(".string"));
        printf("is_string_directive(string): \t%d\n", is_string_directive("string"));
        printf("is_string_directive(.stringa): \t%d\n", is_string_directive(".stringa"));
        printf("is_string_directive(.dstring): \t%d\n", is_string_directive(".dstring"));
        printf("is_string_directive(1): \t%d\n", is_string_directive("1"));
        printf("is_string_directive(.stringa): \t%d\n", is_string_directive(".stringa"));
        printf("is_string_directive(): \t%d\n", is_string_directive(""));
}

void test_is_struct_directive()
{
        printf("\n-------------------  is_struct_directive  -------------------\n");
        printf("is_struct_directive(.struct): \t%d\n", is_struct_directive(".struct"));
        printf("is_struct_directive(struct): \t%d\n", is_struct_directive("struct"));
        printf("is_struct_directive(.structa): \t%d\n", is_struct_directive(".structa"));
        printf("is_struct_directive(.dstruct): \t%d\n", is_struct_directive(".dstruct"));
        printf("is_struct_directive(1): \t%d\n", is_struct_directive("1"));
        printf("is_struct_directive(.structa): \t%d\n", is_struct_directive(".structa"));
        printf("is_struct_directive(): \t%d\n", is_struct_directive(""));
}

void test_is_extern_directive()
{
        printf("\n-------------------  is_extern_directive  -------------------\n");
        printf("is_extern_directive(.extern): \t%d\n", is_extern_directive(".extern"));
        printf("is_extern_directive(extern): \t%d\n", is_extern_directive("extern"));
        printf("is_extern_directive(.externa): \t%d\n", is_extern_directive(".externa"));
        printf("is_extern_directive(.dextern): \t%d\n", is_extern_directive(".dextern"));
        printf("is_extern_directive(1): \t%d\n", is_extern_directive("1"));
        printf("is_extern_directive(.externa): \t%d\n", is_extern_directive(".externa"));
        printf("is_extern_directive(): \t%d\n", is_extern_directive(""));
}

void test_is_entry_directive()
{
        printf("\n-------------------  is_entry_directive  -------------------\n");
        printf("is_entry_directive(.entry): \t%d\n", is_entry_directive(".entry"));
        printf("is_entry_directive(entry): \t%d\n", is_entry_directive("entry"));
        printf("is_entry_directive(.entrya): \t%d\n", is_entry_directive(".entrya"));
        printf("is_entry_directive(.dentry): \t%d\n", is_entry_directive(".dentry"));
        printf("is_entry_directive(1): \t%d\n", is_entry_directive("1"));
        printf("is_entry_directive(.entrya): \t%d\n", is_entry_directive(".entrya"));
        printf("is_entry_directive(): \t%d\n", is_entry_directive(""));
}

//--- IS_OPERAND
void test_is_operand_number()
{
        printf("\n-------------------  is_operand_number  -------------------\n");
        printf("is_operand_number(+): \t%d\n", is_operand_number("+"));
        printf("is_operand_number(#+1): \t%d\n", is_operand_number("#+1"));
        printf("is_operand_number(#-2): \t%d\n", is_operand_number("#-2"));
        printf("is_operand_number(#34): \t%d\n", is_operand_number("#34"));
        printf("is_operand_number(#-34): \t%d\n", is_operand_number("#-34"));
        printf("is_operand_number(#+34): \t%d\n", is_operand_number("#+34"));
        printf("is_operand_number(#a): \t%d\n", is_operand_number("#a"));
        printf("is_operand_number(#א): \t%d\n", is_operand_number("#א"));
        printf("is_operand_number(#.1): \t%d\n", is_operand_number("#.1"));
        printf("is_operand_number(+): \t%d\n", is_operand_number("+"));
        printf("is_operand_number(+1): \t%d\n", is_operand_number("+1"));
        printf("is_operand_number(4678): \t%d\n", is_operand_number("4678"));
}

void test_is_source_operand_valid()
{
        char opr_1[] = "#1";
        char opr_2[] = "r1";
        char opr_3[] = "symbole";
        char opr_4[] = "struct.8";
        char opr_5[] = "";
        char opr_6[] = "#1";
        char opr_7[] = "r1";
        char opr_8[] = "symbole";
        char opr_9[] = "struct.8";
        char opr_10[] = "";
        char opr_11[] = "#1";
        char opr_12[] = "r1";
        char opr_13[] = "symbole";
        char opr_14[] = "struct.8";
        char opr_15[] = "";

        printf("\n-------------------  is_source_operand_valid  -------------------\n");
        printf("when(\"#1\",\"lea\"): \t%d\n", is_source_operand_valid(opr_1, "lea"));
        printf("when(\"r1\",\"lea\"): \t%d\n", is_source_operand_valid(opr_2, "lea"));
        printf("when(\"symbole\",\"lea\"): \t%d\n", is_source_operand_valid(opr_3, "lea"));
        printf("when(\"struct.8\",\"lea\"): \t%d\n", is_source_operand_valid(opr_4, "lea"));
        printf("when(\"#1\",\"prn\"): \t%d\n", is_source_operand_valid(opr_5, "prn"));
        printf("when(\"r1\",\"cmp\"): \t%d\n", is_source_operand_valid(opr_6, "cmp"));
        printf("when(\"symbole\",\"prn\"): \t%d\n", is_source_operand_valid(opr_7, "prn"));
        printf("when(\"\",\"add\"): \t%d\n", is_source_operand_valid(opr_10, "add"));
        printf("when(\"#1\",\"mov\"): \t%d\n", is_source_operand_valid(opr_11, "mov"));
        printf("when(\"#1\",\"add\"): \t%d\n", is_source_operand_valid(opr_14, "add"));
        printf("when(\"symbole\",\"sub\"): \t%d\n", is_source_operand_valid(opr_8, "sub"));
}

void test_is_target_operand_valid()
{

        char opr_1[] = "#1";
        char opr_2[] = "r1";
        char opr_3[] = "symbole";
        char opr_4[] = "struct.8";
        char opr_5[] = "";
        char opr_6[] = "#1";
        char opr_7[] = "r1";
        char opr_8[] = "symbole";
        char opr_9[] = "struct.8";
        char opr_10[] = "";
        char opr_11[] = "#1";
        char opr_12[] = "r1";
        char opr_13[] = "symbole";
        char opr_14[] = "struct.8";
        char opr_15[] = "";
        char opr_16[] = "#1";

        printf("\n-------------------  is_target_operand_valid  -------------------\n");
        printf("when(\"#1\",\"cmp\"): \t%d\n", is_target_operand_valid(opr_1, "cmp"));
        printf("when(\"#1\",\"prn\"): \t%d\n", is_target_operand_valid(opr_6, "prn"));
        printf("when(\"#1\",\"add\"): \t%d\n", is_target_operand_valid(opr_11, "add"));
        printf("when(\"#1\",\"mov\"): \t%d\n", is_target_operand_valid(opr_16, "mov"));
        printf("when(\"\",\"cmp\"): \t%d\n", is_target_operand_valid(opr_5, "cmp"));
        printf("when(\"r1\",\"rtss\"): \t%d\n", is_target_operand_valid(opr_2, "rtss"));
        printf("when(\"r1\",\"add\"): \t%d\n", is_target_operand_valid(opr_7, "add"));
        printf("when(\"symbole\",\"mov\"): \t%d\n", is_target_operand_valid(opr_3, "mov"));
}

void test_is_operand_symbole()
{
        char str_1[] = "STRSTRS";
        char str_2[] = "abcdefg";
        char str_3[] = "hello";
        char str_4[] = "HELLo";
        char str_5[] = "";
        char str_6[] = " ";
        char str_7[] = "STRSTRS ";

        printf("\n-------------------  is_operand_symbole  -------------------\n");

        printf("%d\n", is_operand_symbole(str_1));
        printf("%d\n", is_operand_symbole(str_2));
        printf("%d\n", is_operand_symbole(str_3));
        printf("%d\n", is_operand_symbole(str_4));
        printf("%d\n", is_operand_symbole(str_5));
        printf("%d\n", is_operand_symbole(str_6));
        printf("%d\n", is_operand_symbole(str_7));
}

void test_is_operand_struct()
{
        char opr_1[] = "STRSTRS.1";
        char symbole_1[82];
        int fn_1 = 0;

        char opr_2[] = "abcdefg.7";
        char symbole_2[82];
        int fn_2 = 0;

        char opr_3[] = "hello.6";
        char symbole_3[82];
        int fn_3 = 0;

        char opr_4[] = "hello";
        char symbole_4[82];
        int fn_4 = 0;

        char opr_5[] = "";
        char symbole_5[82];
        int fn_5 = 0;

        char opr_6[10];
        char symbole_6[82];
        int fn_6 = 0;

        char opr_7[] = "STRSTRS.8";
        char symbole_7[82];
        int fn_7 = 0;

        printf("\n-------------------  is_operand_struct  -------------------\n");

        printf("%d\n", is_operand_struct(opr_1, symbole_1, &fn_1));
        printf("%d\n", is_operand_struct(opr_2, symbole_2, &fn_2));
        printf("%d\n", is_operand_struct(opr_3, symbole_3, &fn_3));
        printf("%d\n", is_operand_struct(opr_4, symbole_4, &fn_4));
        printf("%d\n", is_operand_struct(opr_5, symbole_5, &fn_5));
        printf("%d\n", is_operand_struct(opr_6, symbole_6, &fn_6));
        printf("%d\n", is_operand_struct(opr_7, symbole_7, &fn_7));
}

void test_is_operand_struct_valid()
{
        char str_1[] = "STRSTRS.1";
        char str_2[] = "abcdefg.7";
        char str_3[] = "hello.6";
        char str_4[] = "hello";
        char str_5[] = "$sas.2";
        char str_6[10];
        char str_7[] = "STRSTRS.8";

        printf("\n-------------------  is_operand_struct_valid  -------------------\n");

        printf("%d\n", is_operand_struct_valid(str_1));
        printf("%d\n", is_operand_struct_valid(str_2));
        printf("%d\n", is_operand_struct_valid(str_3));
        printf("%d\n", is_operand_struct_valid(str_4));
        printf("%d\n", is_operand_struct_valid(str_5));
        printf("%d\n", is_operand_struct_valid(str_6));
        printf("%d\n", is_operand_struct_valid(str_7));
}

//--- GET_NEXT_FIELD
void test_skip_whitesapce()
{

        printf("\n-------------------  skip_whitesapce  -------------------\n");
        printf("skip_whitesapce(2)--> %d\n", skip_whitesapce("  world\n"));
        printf("skip_whitesapce(7)--> %d\n", skip_whitesapce("       world\n"));
        printf("skip_whitesapce(3)--> %d\n", skip_whitesapce("   , 34\n"));
        printf("skip_whitesapce(1)--> %d\n", skip_whitesapce(" hello . world\n"));
        printf("skip_whitesapce(0)--> %d\n", skip_whitesapce("hello . world\n"));
}

void test_trim_trailing_whitespace()
{
        char str_1[] = "Hello  ";
        char str_2[] = ".  ";
        char str_3[] = ",  ";
        char str_4[] = "hello  ";
        char str_5[] = "hello           ";

        printf("\n-------------------  trim_trailing_whitespace  -------------------\n");
        printf("trim_trailing_whitespace(Hello)--> %s\n", trim_trailing_whitespace(str_1));
        printf("trim_trailing_whitespace(.)--> %s\n", trim_trailing_whitespace(str_2));
        printf("trim_trailing_whitespace(,)--> %s\n", trim_trailing_whitespace(str_3));
        printf("trim_trailing_whitespace(hello)--> %s\n", trim_trailing_whitespace(str_4));
        printf("trim_trailing_whitespace(hello)--> %s\n", trim_trailing_whitespace(str_5));
}

void test_get_next_field()
{
        char line_1[82];
        strcpy(line_1, "  STR:   .struct 8, \"abcdef\"");
        char token_1[82];
        printf("\n-------------------  get_next_field  -------------------\n");
        printf("\n//--- LINE 1\n");
        printf("line: _%s_\ttoken:_%s_\n", line_1, token_1);
        get_next_field(line_1, token_1, SPACE);
        printf("line: _%s_\ttoken:_%s_\n", line_1, token_1);
        get_next_field(line_1, token_1, SPACE);
        printf("line: _%s_\ttoken:_%s_\n", line_1, token_1);
        get_next_field(line_1, token_1, COMMA);
        printf("line: _%s_\ttoken:_%s_\n", line_1, token_1);
        get_next_field(line_1, token_1, SPACE);
        printf("line: _%s_\ttoken:_%s_\n", line_1, token_1);

        char line_2[82];
        strcpy(line_2, " HELLO:   mov #6,   \"s1\"  ");
        char token_2[82];
        printf("\n//--- LINE 2\n");
        printf("line: _%s_\ttoken:_%s_\n", line_2, token_2);
        get_next_field(line_2, token_2, SPACE);
        printf("line: _%s_\ttoken:_%s_\n", line_2, token_2);
        get_next_field(line_2, token_2, SPACE);
        printf("line: _%s_\ttoken:_%s_\n", line_2, token_2);
        get_next_field(line_2, token_2, COMMA);
        printf("line: _%s_\ttoken:_%s_\n", line_2, token_2);
        get_next_field(line_2, token_2, SPACE);
        printf("line: _%s_\ttoken:_%s_\n", line_2, token_2);
}

// ---
void test_is_comment_line()
{
        printf("\n-------------------  is_comment_line  -------------------\n");
        printf("is_comment_line(;aasasa): \t%d\n", is_comment_line(";asasas"));
        printf("is_comment_line(as): \t%d\n", is_comment_line("as"));
        printf("is_comment_line(;): \t%d\n", is_comment_line(";"));
        printf("is_comment_line(): \t%d\n", is_comment_line(""));
}

void test_is_empty_line()
{
        printf("\n-------------------  is_empty_line  -------------------\n");
        printf("is_empty(\\n): \t%d\n", is_empty_line("\n"));
        printf("is_empty(as): \t%d\n", is_empty_line("as"));
        printf("is_empty(;): \t%d\n", is_empty_line(";"));
        printf("is_empty(): \t%d\n", is_empty_line(""));
}