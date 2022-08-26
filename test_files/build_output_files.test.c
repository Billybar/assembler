void test_build_output_files()
{
    FILE *fp_src;
    if (!(fp_src = fopen("./src_files/entry.txt", "r")))
        perror(__FILE__);

    char file_name[82] = "./src_files/entry.txt";
    build_output_files(file_name);
}
