#include <stdio.h>
#include <stdlib.h>
#include "survey.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int SIZE = 10;
	int i;
	int freqsize=0;
	int *freq = (int*) calloc(SIZE,sizeof(int));
	int item, count=0,choice;
	Statistician answer = (Statistician) malloc(sizeof(int)*SIZE);
	while(1){
		menu();
		choice = choose();
		printf("Size of array: %d\n",count);
		switch(choice){
			case 1:		item = input();
						add(answer, &count, &SIZE,item);
						break; 
			case 2:		printf("\nMean: %.2f", mean(answer,count));
						break;
			case 3:		printf("\nMedian: %.2f",median(answer,count));
						break; 
			case 4: 	freqsize=0;
						printf("\nMode: ");
						mode(freq,&freqsize,answer,count);
						for(i=0;i<freqsize;i++)
							printf(" %d ", freq[i]);
						break; 
			case 5:		printf("\nMax: %d",max(answer,count));
						break; 
			case 6:		printf("\nMin: %d",min(answer,count));
						break;
			case 7:		printf("\nRange: %d",range(answer,count));
						break; 
			case 8:		histogram(answer,count);
						break;
			case 9:		displayAll(freq,&freqsize,answer,count);
						break; 
			case 10:	Exit(answer);	
						break; 
			default:	printf("Please input 1-10");
		}
		promptContinue();
	}
	return 0;
}
