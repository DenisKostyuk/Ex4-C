all:frequency

frequency: TrieText.o Main.o
	$ gcc -Wall -o frequency Main.o TrieText.o

Main.o: Main.c TrieText.h
	$ gcc -Wall -c  Main.c

TrieText.o: TrieText.c TrieText.h
	$ gcc -Wall -c TrieText.c 


.PHONY: clean all

clean:
	$ rm -f *.o frequency

