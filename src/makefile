output: main.o account.o
	gcc main.o account.o -o output

main.o: main.c
	gcc -c main.c -o main.o

account.o: account.c
	gcc -c account.c -o account.o

clean:
	del /Q *.o output.exe
