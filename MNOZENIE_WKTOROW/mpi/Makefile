MPICC  = mpicc
MPIRUN = mpirun
np=4

all: mpi

mpi: mpi.c
	$(MPICC) mpi.c -lrt -lm -o mpi

run: mpi
	$(MPIRUN) -np $(np) ./mpi

clean: 
	rm -f mpi *.o *~ 
