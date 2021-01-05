CC = gcc -Wall

all: isort txtfind

isort: isort.o
	{CC} $^ -o $@

isort.o: isort.c
	${CC} -c $^

txtfind: txtfind.o
	${CC} $^ -o $@

txtfind.o: txtfind.c
	${CC} -c $^

clean: 
	rm *.o isort txtfind *.a 
