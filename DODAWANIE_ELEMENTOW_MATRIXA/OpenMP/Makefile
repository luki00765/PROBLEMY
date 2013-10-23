size=2

all: openmp

openmp: openmp.c
	gcc -fopenmp -o openmp openmp.c

run: openmp
	env OMP_NUM_THREADS=$(size) ./openmp

clean: 
	rm -f openmp *.o *~ 
