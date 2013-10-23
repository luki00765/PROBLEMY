#include<stdio.h>
#include<stdlib.h>
#include "timers.h"
#include<omp.h>
int main(int argc,char **argv){
	int i,j;
	int sum = 0;
	int N;
	#pragma omp parallel 
	N = 100*omp_get_num_threads(); // numery wątków
	printf("N: %d\n", N);	

	int matrix[N][N];	
	pTimer T = newTimer();
	startTimer(T);
	srand(time(0));

	
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
	  	matrix[i][j] = rand() % 10;
		printf("%d\t ",matrix[i][j]);
	  }
	  printf("\n");	
	}
	
	
	for(i=0;i<N;i++){
	#pragma omp parallel for  \
	   reduction(+ : sum)
	  for(j=0;j<N;j++){
		sum += matrix[i][j];
		//printf("sum: %d, id: %d\n",sum,omp_get_thread_num());
	  }
	}	
	
	stopTimer(T);
	printf("\nsum: %d\n",sum);
	printf("Czas obliczen: %f\n", getTime(T));
	return 0;
}
