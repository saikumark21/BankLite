output: main.o account.o file_io.o generic.o
	gcc main.o account.o file_io.o generic.o -o output

main.o: main.c
	gcc -c main.c -o main.o

account.o: account.c
	gcc -c account.c -o account.o

file_io.o: file_io.c
	gcc -c file_io.c -o file_io.o

generic.o: generic.c
	gcc -c generic.c -o generic.o

clean:
	rm *.o output.exe