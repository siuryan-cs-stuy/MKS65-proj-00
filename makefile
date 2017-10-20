all:
	gcc -o exec linked_list.c music_player.c main.c

run: all
	./exec

valgrind:
	gcc -g linked_list.c music_player.c main.c
	valgrind --leak-check=yes ./a.out

clean:
	rm *~
	clear

cleanall:
	rm exec
	rm a.out
	rm *~
	clear
