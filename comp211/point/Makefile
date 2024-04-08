# Variables
TARGET=lec14
OBJ_FILES=main.o Guards.o point.o path.o
CC=gcc
CC_FLAGS=-Wall -Wextra -std=c11 -g
LINK_MATH=-lm

# Rules
lec14: main.o Guards.o Point.o #Path.o 
	gcc -Wall -Wextra -std=c11 -g main.o Guards.o point.o  -o lec14 -lm #Path.o

main.o: main.c
	${CC} ${CC_FLAGS} -c main.c

point.o: point.c
	${CC} ${CC_FLAGS} -c point.c

#Path.o: Path.c
#	${CC} ${CC_FLAGS} -c Path.c

Guards.o: Guards.c
	${CC} ${CC_FLAGS} -c Guards.c

.PHONY: clean
clean:
	rm -f ${OBJ_FILES} ${TARGET}