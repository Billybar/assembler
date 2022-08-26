assembler: main.o macro_parser.o build_symbol_table.o build_output_files.o encoding.o text_manager.o DB_macro.o  DB_instruction.o DB_symbol.o errors.o
		gcc -g -m32 -Wall -ansi -pedantic macro_parser.o build_symbol_table.o build_output_files.o encoding.o text_manager.o DB_macro.o  DB_instruction.o DB_symbol.o errors.o main.o -o assembler

main.o: main.c macro_parser.h build_symbol_table.h build_output_files.h
		gcc -c -m32 -Wall -ansi -pedantic main.c

macro_parser.o: macro_parser.c macro_parser.h text_manager.h
		gcc -c -m32 -Wall -ansi -pedantic macro_parser.c

build_symbol_table.o: build_symbol_table.c build_symbol_table.h text_manager.h
		gcc -c -m32 -Wall -ansi -pedantic build_symbol_table.c

build_output_files.o: build_output_files.c build_output_files.h encoding.h
		gcc -c -m32 -Wall -ansi -pedantic build_output_files.c

encoding.o: encoding.c encoding.h text_manager.h
		gcc -c -m32 -Wall -ansi -pedantic encoding.c

text_manager.o: text_manager.c text_manager.h ./DB/DB_instruction.h ./DB/DB_macro.h ./DB/DB_symbol.h
		gcc -c -m32 -Wall -ansi -pedantic text_manager.c

DB_instruction.o: ./DB/DB_instruction.c ./DB/DB_instruction.h
		gcc -c -m32 -Wall -ansi -pedantic ./DB/DB_instruction.c

DB_macro.o: ./DB/DB_macro.c ./DB/DB_macro.h
		gcc -c -m32 -Wall -ansi -pedantic ./DB/DB_macro.c

DB_symbol.o: ./DB/DB_symbol.c ./DB/DB_symbol.h errors.h
		gcc -c -m32 -Wall -ansi -pedantic ./DB/DB_symbol.c

errors.o: errors.c errors.h
		gcc -c -m32 -Wall -ansi -pedantic errors.c

clean_all:
		rm *.o ./src_files/*.ob ./src_files/*.ent ./src_files/*.ext ./src_files/*.am

clean_o:
		rm *.o