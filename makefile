all: main 

main: GuiC.c
	gcc -Wall -g $(shell pkg-config --cflags gtk+-3.0 ) -o game.exe GuiC.c $(shell pkg-config --libs gtk+-3.0 )