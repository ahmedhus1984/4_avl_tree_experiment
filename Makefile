avl:avl.o
	gcc -g3 -Wall avl.o -o avl.exe
avl.o:avl.c
	gcc -g3 -c -Wall avl.c -o avl.o
clear:
	rm *.o
clean:
	rm *.o *.exe
