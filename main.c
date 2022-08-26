#include "build_symbol_table.h"
#include "build_output_files.h"
#include "macro_parser.h"

/**
 * NOTICE: tab canot replace space.
 * when space shuold separete between fields then tab is not enugh,
 * space must be in between
 */

int main(int argc, char *argv[])
{
    /* holds the address starting point of DC */
    int DC_start_addr = LOADING_ADDR;
    char file_name[LINE_LEN];
    int i = 1;

    if (argc == 1)
        exit(EXIT_FAILURE);

    for (; i < argc; i++)
    {
        strcpy(file_name, argv[i]);
        macro_parser(file_name);
        build_symbol_table(file_name, &DC_start_addr);
        build_output_files(file_name, DC_start_addr);

        /* reset DC counter for next source file */
        DC_start_addr = LOADING_ADDR;
    }

    return 0;
}