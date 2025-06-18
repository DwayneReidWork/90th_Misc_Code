sorting_demo_program: main.o sorting_algorithms.o utility_functions.o
	gcc main.o sorting_algorithms.o utility_functions.o -o sorting_demo_program

main.o: main.c
	gcc -c main.c -o main.o

sorting_algorithms.o: sorting_algorithms.c
	gcc -c sorting_algorithms.c -o sorting_algorithms.o

utility_functions.o: utility_functions.c
	gcc -c utility_functions.c -o utility_functions.o

clean: sorting_demo_program
	rm *.o sorting_demo_program