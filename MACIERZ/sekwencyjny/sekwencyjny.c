/*
Przy rozwiązaniu mpi przy 4 procesach uzyskujemy średni czas 0.014
przy rozwiazaniu sekwencyjnym: 0.004
Widać dużą stratą czasu na komunikacji....
*/

#include <stdio.h>
#include "timers.h" 

int main(int argc, char **argv){	
  if (argc > 1) {
	int size;
	if (sscanf(argv[1], "%d", &size)) {
		printf("Macierz o rozmiarach: %dx%d\n", size,size);
		pTimer T = newTimer();
		int matrix[size][size];	
		int vector[size];
		int result[size];
		int i,j,k;
		
		for (i = 0; i < size; i++) {
			result[i] = 0;
		}

		for (i = 0; i < size; i++){
			for (j = 0; j < size; j++){
				matrix[i][j] = (int)(rand() % 10);	
			}
			vector[i] =  (int)(rand() % 10);	
		}

			startTimer(T);
			for (i = 0; i < size; i++){
				for (j = 0; j < size; j++){
				 result[i] += matrix[i][j] * vector[j];
				}
			}
		stopTimer(T);
			printf("Czas wykonania = %f\n", getTime(T));

		if (size <= 16) {
			for (i = 0; i < size; i++){
				for (j = 0; j < size; j++){
					printf("%d\t",matrix[i][j]);
				}
				printf("| %d\t|", vector[i]);
				printf("| %d\t|\n", result[i]);
			}
		}
		else { printf("Wyświetlanie macierzy powyżej 16x16 jest nie przejrzyste.\n"); }
	 } else {
		printf("Parametrem musi byc liczba\n");
	}
}	else {
	printf("Musisz podac rozmiar macierzy!\n");
}
	return 0;
}


