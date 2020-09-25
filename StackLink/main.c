#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(int argc, char *argv[]) {
	Stack s = newStack();
	stackItem symbols[SIZE];
	int status=0,flag=0;
	int ask=1; 
	do{
		do{
			printf("Enter Symbols: ");
			fgets(symbols,SIZE,stdin);
			flag = isValidInput(symbols);
		}while(flag!=1); 
		flag=0;
		status = isValid(s,symbols);
		if(status==1)
			printf("\nMatch\n");
		else 
			printf("\nMismatch\n");
		printDisplay(s,status);
		printf("\nDo you want to continue? (1/0): ");
		scanf("%d",&ask);
		fflush(stdin);
		freeStack(s);
		system("cls");
	}while(ask!=0);
	
	return 0;
}
