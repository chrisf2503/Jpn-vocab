main: main.o
	g++ -o main main.o 

main.o: main.cpp jpnVocab.h

clean:
	-rm -f *o