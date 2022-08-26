#include "DB_macro.h"

/* m_root of macro list */
static struct Macro *m_root = NULL;
/* m_tail of macro list */
static struct Macro *m_tail = NULL;

void insert_macro(char *name, char *data)
{
    struct Macro *new_macro = (struct Macro *)malloc(sizeof(struct Macro));
    new_macro->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    new_macro->data = (char *)malloc((strlen(data) + 1) * sizeof(char));

    strncpy(new_macro->name, name, (strlen(name) + 1)); /* +1 for null terminator */
    strncpy(new_macro->data, data, (strlen(data) + 1)); /* +1 for null terminator */
    new_macro->next = NULL;

    if (m_root == NULL)
    {
        m_root = m_tail = new_macro;
    }
    else
    {
        m_tail->next = new_macro;
        m_tail = m_tail->next;
    }
}

struct Macro *get_macro(char *name)
{
    struct Macro *macro_ptr = m_root;

    while (macro_ptr != NULL)
    {
        if (strcmp(name, macro_ptr->name) == 0)
            break;

        macro_ptr = macro_ptr->next;
    }

    return macro_ptr;
}

void free_macro_list()
{
    struct Macro *tmp = m_root;

    while (m_root != NULL)
    {
        tmp = m_root;
        m_root = m_root->next;
        free(tmp->name);
        free(tmp->data);
        tmp->name = tmp->data = NULL;
        free(tmp);
        tmp = NULL;
    }
}

/*   ---   PRINT   ---   */
void print_macro(struct Macro *macro_ptr)
{
    printf("name: \t\t%s\n", macro_ptr->name);
    printf("data:__%s\n", macro_ptr->data);
}

void print_macro_list(void)
{
    struct Macro *macro = m_root;
    printf("\n---------------------------------\n");
    printf("\tMACROS LIST\n");
    printf("---------------------------------\n");
    while (macro != NULL)
    {
        printf("%s\n%s\n", macro->name, macro->data);
        macro = macro->next;
    }
    printf("---------------------------------\n");
}