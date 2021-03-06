#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "timers.h"
#define ROOT 0

int main(int argc, char **argv){	
  if (argc > 1) {
	int size; // deklarujemy wielkość Macierzy
	int np, rank; // np - ilość nodów
	pTimer T = newTimer();		
		
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &np);	
	if (sscanf(argv[1], "%d", &size)) {
	  if (size % np == 0) { 
	int podzial = (int)size/np;
	int matrix[size][size]; 
	int vector[size];
	int result[size];
	int res_result[podzial]; // każdy proces podstawi wynik do indexu res_result ktory bedzie numerem jego procesu
	int i,j,k;
	int res_matrix[size][podzial]; // [kolumna, wiersz]
	  if(rank == 0){
		printf("podzial: %d\n", podzial);
	  }	srand(time(0));
				
	// wektor rozwiązania
	  for (i =0; i < podzial; i++) {
		res_result[i] = 0;
	  }	

	  if (rank == ROOT) {
		for (i = 0; i < size; i++){
			for (j = 0; j < size; j++){
				matrix[i][j] = (int)(rand() % 10);	
			}
	           vector[i] =  (int)(rand() % 10);	
		}
	}
	
	if (rank == ROOT) {
	startTimer(T);
	}	
	/* Wysłanie części macierzy do procesów */
					
	for (k =0; k< size; k++ ){
/*(void *sendbuf, int sendcnt, MPI_Datatype sendtype, 
   void *recvbuf, int recvcnt, MPI_Datatype recvtype, int root, 
               MPI_Comm comm)*/
	MPI_Scatter(matrix[k], podzial, MPI_INT, &res_matrix[k], podzial, 			MPI_INT, ROOT, MPI_COMM_WORLD); 
	}
/*    (void *buffer, int count, MPI_Datatype datatype, int root,MPI_Comm comm )*/
	MPI_Bcast( vector, size, MPI_INT, 0,  MPI_COMM_WORLD);	
			
//Mnoży swoje czesci Matrixa przez wektor = res_result
	for (i = 0; i < podzial; i++){
		for (j = 0; j < size; j++){
			res_result[i] += res_matrix[j][i] * vector[j];
				
		} // j - kolumna, i - wiersz
	}
// cześciowe rozwiązanie - res_result
// odbierany bufor - result

/*(void *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, int root, MPI_Comm comm)*/
	MPI_Gather(&res_result, podzial, MPI_INT, result, podzial, MPI_INT, ROOT, 			MPI_COMM_WORLD);	
			
			
	if (rank == ROOT) {
		stopTimer(T);
		if (size <= 16) {
		  for (i = 0; i < size; i++){
		    for (j = 0; j < size; j++){
		      printf("%d\t",matrix[j][i]);
		    }
		   printf("| %d\t|", vector[i]);
		   printf("| %d\t|\n", result[i]);
		  }
					
		}
	printf("Czas obliczen = %f\n", getTime(T));
		}
	} else {
	  if (rank == ROOT) {	printf("Źle dobrane parametry wielkość macierzy musi być podzielna przez liczbe procesów.\n"); }
		}
	} else {
	  if (rank == ROOT) { printf("Zly paramter wywoałania programu! Musi to być liczba.\n"); }
		}
	} else {
	   printf("Musisz podac parametr.\n");
	}
	
	MPI_Finalize();
	
	return 0;
}


