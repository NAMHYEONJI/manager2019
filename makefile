CC = gcc
CFLAGE = -W -Wall
TARGET = manager
OBJECTS = main.o menu.o user.o
DOBJECTS = main_d.o menu_d.o user_d.o

all : $(TARGET)

manager_debug : $(DOBJECT)
	$(CC) $(CFLAGE) -o $@ $^  

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGE) -o $@ $^

main_d.o : main.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -d $@ $^

user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -d $@ $^

clean : 
	rm *.o manager manager_debug 
