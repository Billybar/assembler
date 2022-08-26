#include "DB_symbol.h"

/* root of symbol list */
static struct Symbol *root = NULL;
/* tail of symbol list */
static struct Symbol *tail = NULL;

void insert_symbol(char *name, int address, int directive_flag, int ext_flag)
{
    struct Symbol *new_symbol = (struct Symbol *)malloc(sizeof(struct Symbol));
    new_symbol->name = (char *)malloc(SYMBOL_NAME_MAX_LENGTH * sizeof(char));
    if ((!new_symbol) || (!new_symbol->name))
        perror(__FILE__);

    strncpy(new_symbol->name, name, SYMBOL_NAME_MAX_LENGTH);
    new_symbol->address = address;
    new_symbol->is_directive = directive_flag;
    new_symbol->is_external = ext_flag;
    new_symbol->next = NULL;

    if (root == NULL)
    {
        root = tail = new_symbol;
    }
    else
    {
        tail->next = new_symbol;
        tail = tail->next;
    }
}

struct Symbol *get_symbol(char *name)
{
    struct Symbol *symbol_ptr = root;

    while (symbol_ptr != NULL)
    {
        if (strcmp(name, symbol_ptr->name) == 0)
            break;

        symbol_ptr = symbol_ptr->next;
    }

    return symbol_ptr;
}

void update_symbols_address(int IC)
{
    struct Symbol *symbol = root;

    while (symbol != NULL)
    {
        if (symbol->is_external == true)
            ; /* go to next symbol */
        else if ((symbol->is_directive == true))
            symbol->address = (symbol->address + LOADING_ADDR + IC);
        else
            symbol->address = (symbol->address + LOADING_ADDR);

        symbol = symbol->next;
    }
}

void free_symbol_list()
{
    struct Symbol *tmp = root;

    while (root != NULL)
    {
        tmp = root;
        root = root->next;
        free(tmp->name);
        tmp->name = NULL;
        free(tmp);
        tmp = NULL;
    }
}

/*   ---   PRINT   ---   */
void print_symbol(struct Symbol *symbol_ptr)
{
    printf("name: \t\t%s\n", symbol_ptr->name);
    printf("address: \t%d\n", symbol_ptr->address);
    printf("is_data: \t%d\n", symbol_ptr->is_directive);
    printf("is_ext: \t%d\n", symbol_ptr->is_external);
    printf("next: \t\t%p\n", (void *)symbol_ptr->next);
}

void print_symbols_address(void)
{
    struct Symbol *symbol = root;
    printf("\n---------------------------------\n");
    printf("\tName\t|\tAddress\n");
    printf("---------------------------------\n");
    while (symbol != NULL)
    {
        printf("\t%s\t|\t%d\n", symbol->name, symbol->address);
        symbol = symbol->next;
    }
    printf("---------------------------------\n");
}