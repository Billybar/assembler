void test_get_num_of_operands()
{

    printf("\n-------------------  get_num_of_operands  -------------------\n");
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(1));
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(2));
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(3));
    printf("should be: 1 \tresult: %d\n", get_num_of_operands(4));
    printf("should be: 1 \tresult: %d\n", get_num_of_operands(5));
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(6));
    printf("should be: 1 \tresult: %d\n", get_num_of_operands(7));
    printf("should be: 1 \tresult: %d\n", get_num_of_operands(8));
    printf("should be: 1 \tresult: %d\n", get_num_of_operands(10));
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(1));
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(3));
    printf("should be: 1 \tresult: %d\n", get_num_of_operands(5));
    printf("should be: 2 \tresult: %d\n", get_num_of_operands(0));
    printf("should be: 0 \tresult: %d\n", get_num_of_operands(14));
    printf("should be: 0 \tresult: %d\n", get_num_of_operands(15));
    printf("should be: -1 \tresult: %d\n", get_num_of_operands(16));
    printf("should be: -1 \tresult: %d\n", get_num_of_operands(17));
}

void test_get_opcode()
{

    printf("\n-------------------  get_opcode  -------------------\n");
    printf("should be: 0 \tresult: %d\n", get_opcode("mov"));
    printf("should be: 1 \tresult: %d\n", get_opcode("cmp"));
    printf("should be: 2 \tresult: %d\n", get_opcode("add"));
    printf("should be: 3 \tresult: %d\n", get_opcode("sub"));
    printf("should be: 4 \tresult: %d\n", get_opcode("not"));
    printf("should be: 5 \tresult: %d\n", get_opcode("clr"));
    printf("should be: 6 \tresult: %d\n", get_opcode("lea"));
    printf("should be: 7 \tresult: %d\n", get_opcode("inc"));
    printf("should be: 8 \tresult: %d\n", get_opcode("dec"));
    printf("should be: 9 \tresult: %d\n", get_opcode("jmp"));
    printf("should be: 11 \tresult: %d\n", get_opcode("get"));
    printf("should be: -1 \tresult: %d\n", get_opcode("none"));
    printf("should be: 12 \tresult: %d\n", get_opcode("prn"));
    printf("should be: 13 \tresult: %d\n", get_opcode("jsr"));
    printf("should be: -1 \tresult: %d\n", get_opcode("none"));
    printf("should be: 14 \tresult: %d\n", get_opcode("rts"));
    printf("should be: 15 \tresult: %d\n", get_opcode("hlt"));
    printf("should be: 10 \tresult: %d\n", get_opcode("bne"));
}