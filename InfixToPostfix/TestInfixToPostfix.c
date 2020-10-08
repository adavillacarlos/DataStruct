#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack s = createStack();
	stackItem infix[SIZE];
	stackItem postfix[SIZE];
	int choice; 
	int flag=0,ctr=0;
	int exit = 1; 
	do{
		do{
			printf("\nEnter infix: ");
			fgets(infix,SIZE,stdin);
			flag = isValidInput(infix);
		}while(flag!=1);
		
		infixToPostfix(infix,postfix,s);
		printf("Postfix: %s\n",postfix); 
		
		flag=isDigitPresent(postfix);
		if(flag==1){
			printf("Result: %d\n",postfixEval(postfix,s));
		} else
			printf("\nThere is an alphabet so there would be no result\n");
		printf("Do you want to continue? (1/0): ");
		exit = getChoice();
		flag=0; 
		fflush(stdin);
		promptUser();
		freeStack(s);
		
	}while(exit!=0);
	
	return 0;
}

