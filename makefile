all:
	gcc -o exec linked_list.c main.c music_player.c

run: all
	./exec

valgrind:
	gcc -g linked_list.c main.c
	valgrind --leak-check=yes ./a.out

clean:
	rm *~
	clear

cleanall:
	rm exec
	rm *~
	clear
