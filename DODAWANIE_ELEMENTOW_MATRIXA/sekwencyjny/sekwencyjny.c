#include<stdio.h>
#include<stdlib.h>
#include "timers.h"

int main(int argc,char **argv){
	int i,j;
	int sum = 0;
	int matrix[3][3];
	pTimer T = newTimer();
	startTimer(T);
	srand(time(0));
	for(i=0;i<3;i++){
	  for(j=0;j<3;j++){
	  	matrix[i][j] = rand() % 10;
		sum += matrix[i][j];
		printf("%d\t ",matrix[i][j]);
	  }
	  printf("\n");	
	}
	stopTimer(T);
	printf("\nsum: %d\n",sum);
	printf("Czas obliczen: %f\n", getTime(T));
	return 0;
}
