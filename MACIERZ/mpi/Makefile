MPICC  = mpicc
MPIRUN = mpirun
np=2
size=4

all: mpi

mpi: mpi.c
	$(MPICC) mpi.c -lrt -lm -o mpi

run: mpi
	$(MPIRUN) -np $(np) ./mpi $(size)

clean: 
	rm -f mpi *.o *~ 
