#include "macro_parser.h"

void macro_parser(char *file_name)
{
    FILE *src_code, *am_file;
    struct Macro *macro;
    char tmp_f[LINE_LEN], line[LINE_LEN], first_field[LINE_LEN];

    /* --- OPEN FILES --- */
    strcpy(tmp_f, file_name);
    if (!(src_code = fopen(strcat(tmp_f, ".as"), "r")))
        perror(__FILE__);
    strcpy(tmp_f, file_name);
    if (!(am_file = fopen(strcat(tmp_f, ".am"), "w")))
        perror(__FILE__);

    /* --- WALK THROUGH SOURCE FILE --- */
    while ((fgets(line, LINE_LEN, src_code)) != NULL)
    {
        if (is_empty_line(line) || is_comment_line(line))
            continue;

        get_next_field(line, first_field, SPACE);

        if (is_macro_definition(first_field))
            append_DB_macro(line, &src_code); /* append data to DB_macro */

        else if (is_macro_exist(&macro, first_field))
            fputs(macro->data, am_file); /*copy macro data to file.am*/

        else
        {
            append_EOL(line);
            fprintf(am_file, "%s %s", first_field, line); /*copy source line to file.am*/
        }
    }

    fclose(src_code);
    fclose(am_file);
    free_macro_list();
}

void append_DB_macro(char *line, FILE **src_code)
{
    char fields[LINE_LEN], var_name[LINE_LEN], *data = NULL;

    get_next_field(line, var_name, '\n');
    while ((fgets(line, LINE_LEN, *src_code)) != NULL)
    {
        if (is_empty_line(line) || is_comment_line(line))
            continue;

        get_next_field(line, fields, '\0');
        if (is_endmacro(fields))
            break;
        else
            copy_data(fields, &data); /* get macro val */
    }

    insert_macro(var_name, data);

    free(data);
    data = NULL;
}

void copy_data(char *line, char **data)
{
    char *temp_ptr;
    static int LC;

    append_EOL(line);
    if (*data == NULL) /* malloc and copy */
    {
        LC = 1;
        (*data) = (char *)malloc((strlen(line) + 1) * sizeof(char));
        if (!(*data))
            EXIT_FAILURE;

        strcpy((*data), line);
    }
    else /* realloc and copy */
    {
        LC++;
        temp_ptr = (char *)realloc((*data), (LINE_LEN * LC) * sizeof(char));
        if (!temp_ptr)
            EXIT_FAILURE;

        (*data) = temp_ptr;
        strcat((*data), line);
    }
}
