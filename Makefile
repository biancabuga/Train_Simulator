# UPB 2024

all: test build run

build:
	touch tema1.in tema1.out
	gcc -o tema1 -Wall *.c main.h \
		lists/*.c \
		operations/*.c

run:
	./tema1

clean:
	rm ./tema1

archive:
	zip -r tema1.zip *.c *.h operations lists README Makefile

valgrind:
	valgrind --leak-check=yes --track-origins=yes ./tema1 aux;

test:
	cat Teste/Input/test30.in > tema1.in