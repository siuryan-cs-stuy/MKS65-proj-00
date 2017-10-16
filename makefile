all:
	gcc -o test linked_list.c main.c

run: all
	./test

clean:
	rm *~
	clear

cleanall:
	rm test
	rm *~
	clear
