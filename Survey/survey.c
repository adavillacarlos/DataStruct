#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

int input(){
	int item;
	while(1){
		printf("Input num (1-9): ");
		scanf("%d",&item);
		if(item>=1 && item<=9)
			return item;
	}
}

void add(Statistician answer, int *count, int *SIZE, int item){
	int i=0,j,temp; 
	
	if(*count==*SIZE){
		*SIZE= (*SIZE) * 2; 
		answer = realloc(answer,(*SIZE)*sizeof(int));
	} 
	answer[(*count)++] = item;
	for(i=0;i<*count;i++){
		for(j=i;j>0;j--){
			if(answer[j-1] > answer[j]){
				temp = answer[j-1]; 
				answer[j-1] = answer[j];
				answer[j] = temp;
			}
		}
	}
	
}

float mean(Statistician answer, int count){
	int i; 
	float ans=0;
	for(i=0;i<count;i++)
		ans+=answer[i];
	ans/=count;
	return ans; 
}

float median(Statistician answer, int count){
	int mid = count/2;
	if(count%2!=0)
		return answer[mid];
	else 
		return ((answer[mid] + answer[mid+1])/2);
}

int max(Statistician answer, int count){
	return answer[count-1];
}

int min(Statistician answer, int count){
	return answer[0];
}

int range(Statistician answer, int count){
	return ((answer[count-1]) - (answer[0]));
}

void mode(int freq[], int *freqsize, Statistician answer, int count){
	int i,item=0,max=0; 
	int respons[9]={0};

	for(i=0;i<count;i++){
		item=answer[i];
		respons[item-1]++;
	}
	
	for(i=0;i<count;i++){
		if(max<=respons[i])
			max = respons[i];
	}
	
	if(max==1){
		printf("None");
	} else {
		for(i=0;i<9;i++){
			if(respons[i]==max){
				freq[i]=i+1;
				(*freqsize)++;
			}
		}
	} 

}

void histogram(Statistician answer, int count){
	printf("\nHistogram: \n");
	int i, j,k=0,l=0,m=0;
	for(i=9;i>=1;i--){
		printf("[%d]",i);
		l=0;
		for(j=k;j<count;j++){
			if(answer[j]==i){
				printf(" *");
				k++;
				l++;
			}
		}
		if(m<=l) m = l;
			printf("\n");
	}
	printf("   ");
	for(i=1;i<=m;i++) 
		printf(" %d",i);
}


void menu(){
	printf("MENU");
	printf("\n1. Insert Element "); 
	printf("\n2. Mean");
	printf("\n3. Median");
	printf("\n4. Mode");
	printf("\n5. Max");
	printf("\n6. Min");
	printf("\n7. Range");
	printf("\n8. Histogram");
	printf("\n9. Exit");
}

int choose(){
	int choice; 
	printf("\nEnter choice: ");
	scanf("%d",&choice);
	return choice; 
}

void promptContinue(){
	fflush(stdin);
	printf("\n");
	system("pause");
	system("cls");
}

void Exit(Statistician answer){
	free(answer);
	printf("Program terminated");
	exit(1);
}
