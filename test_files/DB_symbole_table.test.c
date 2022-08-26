
void test_get_print_symbole()
{
    char symbole_1[] = "LOOP";
    char symbole_2[] = "LENGTH";
    char symbole_3[] = "hello";
    char symbole_4[] = "he";
    printf("\n-------------------  get__print_symbole  -------------------\n");
    if (get_symbole(symbole_1))
    {
        printf("----SYMBOLE 1----\n");
        print_symbole(get_symbole(symbole_1));
    }
    if (get_symbole(symbole_2))
    {
        printf("----SYMBOLE 2----\n");
        print_symbole(get_symbole(symbole_2));
    }
    if (get_symbole(symbole_3))
    {
        printf("----SYMBOLE 3----\n");
        print_symbole(get_symbole(symbole_3));
    }
    if (get_symbole(symbole_4))
    {
        printf("----SYMBOLE 4----\n");
        print_symbole(get_symbole(symbole_4));
    }
}

void test_insert_symbole()
{
    char symbole_1[] = "LOOP";
    char symbole_2[] = "LENGTH";
    char symbole_3[] = "hello";
    printf("\n-------------------  insert_symbole  -------------------\n");
    insert_symbole(symbole_1, 107, 1, 1);
    insert_symbole(symbole_2, 129, 1, 0);
    insert_symbole(symbole_3, 3, 1, 0);
}

void test_symbloe_list()
{
    test_insert_symbole();
    test_get_print_symbole();
}