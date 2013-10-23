size=4

all: sekwencyjny

sekwencyjny: sekwencyjny.c
	gcc sekwencyjny.c -lrt -lm -o sekwencyjny

run: sekwencyjny
	./sekwencyjny $(size)

clean: 
	rm -f sekwencyjny *.o *~ 
