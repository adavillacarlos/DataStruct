#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack s = newStack();
	Stack p = newStack();
	char infix[SIZE];
	char postfix[SIZE];
	int flag=0;
	int ask=1; 
	do{
		do{
			printf("Enter infix: ");
			fgets(infix,SIZE,stdin);
			flag = isValidInput(infix);
		}while(flag!=1);
		flag=0;
		infixtopostfix(infix,postfix,s);
		printf("\nPostfix: ");
		puts(postfix);
		printf("\nResult: %0.2f",postfixEvaluate(postfix,p));
		printf("\nDo you want to continue? (1/0): ");
		scanf("%d",&ask);
		promptUser();
		fflush(stdin);
		freeStack(s);
		freeStack(p);
		system("cls");
	}while(ask!=0);
	return 0;
}
