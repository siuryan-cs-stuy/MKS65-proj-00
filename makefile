all:
	gcc -o exec linked_list.c main.c

run: all
	./exec

valgrind:
	gcc -g linked_list.c main.c
	valgrind --leak-check=yes ./a.out

clean:
	rm *~
	clear

cleanall:
	rm test
	rm *~
	clear
