all : manager_debug

manager_debug : menu_d.o user_d.o main.c
	gcc -o manager_debug menu_d.o user_d.o main.c
menu_d.o : menu.c
	gcc -DDBUG_MODE -c -o menu_d.o menu.c
user_d.o : user.c
	gcc -DDBUG_MODE -c -o user_d.o user.c
manager : menu.o user.o main.c
	gcc -o manager menu.o user.o main.c
user.o : user.c
	gcc -c -o user.o user.c
menu.o : menu.c
	gcc -c -o menu.o menu.c
clean :
	rm *.o manager manager_debug
