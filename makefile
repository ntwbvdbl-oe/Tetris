#file:		makefile
#author:	zju3180101729

CC		= gcc
LIBOBJS	= libgraphics/exceptio.o\
		  libgraphics/genlib.o\
		  libgraphics/graphics.o\
		  libgraphics/random.o\
		  libgraphics/simpio.o\
		  libgraphics/strlib.o
OBJS	= main.o draw.o game.o init.o\
		  button.o label.o grid.o block.o textbox.o list.o
BIN		= main.exe
CFLAGS	= -static-libstdc++ -static-libgcc -mwindows -Wfatal-errors

.PHONY:	all clean

all: $(BIN)

$(BIN):	$(OBJS) $(LIBOBJS)
	$(CC) $(OBJS) $(LIBOBJS) -o $(BIN) $(CFLAGS)

main.o draw.o game.o init.o: game.h button.h label.h grid.h block.h textbox.h list.h

button.o: button.h

label.o: label.h

grid.o: grid.h

block.o: block.h

textbox.o: textbox.h

list.o: list.h

clean:
	del $(BIN) $(OBJS)

