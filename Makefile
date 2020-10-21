all: simple_thread_in_C 

part1: simple_thread_in_C.c
	gcc -pthread -o simple_thread_in_C.out simple_thread_in_C.c

clean:
	-rm *.out
