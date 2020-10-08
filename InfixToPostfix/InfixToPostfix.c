#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfixToPostfix.h"

int getChoice(){
	int n; 
	printf("\nEnter your choice: ");
	scanf("%d",&n);
	return n;
}

void promptUser(){
	system("pause");
	system("cls");
}


int isValidInput(stackItem infix[]){
	int i, ans = 0; 
	for(i=0;infix[i]!='\n';i++){
		if(isalnum(infix[i]) !=0 ||  precedence(infix[i])!=3){
			ans=1; 
		} else{
			ans = 0; 
			break; 
		}
	}
	return ans; 
}


int isDigitPresent(stackItem postfix[]){
	int i, ans = 0; 
	for(i=0;postfix[i]!='\0';i++){
		if(isdigit(postfix[i]) != 0 ||  precedence(postfix[i])!=3){
			ans=1; 
		} else{
			ans = 0; 
			break; 
		}
	}
	return ans; 
}

int precedence(stackItem c){
	int ans; 
	if(c=='*' || c=='/' || c=='%')
		ans = 2; 
	else if(c=='+' || c=='-')
		ans = 1; 
	else
		ans = 3; 
	return ans; 
} 

void infixToPostfix(stackItem infix[],stackItem postfix[],Stack s){
	int i,c,j=0,x;
	for(i=0;infix[i]!='\n';i++){
		c = infix[i];
		if(isdigit(c)!=0){
			postfix[j++] = c;
		} else {
			while(isStackEmpty(s)!=1 && precedence(c)<=precedence(stackTop(s)))
				postfix[j++] = pop(s);
			push(s,c);
		}
	}
	while(!isStackEmpty(s)){
		postfix[j++] = pop(s);
	}
	postfix[j]='\0';
}

int postfixEval(stackItem postfix[],Stack s){
	int i,c,num,n1,n2; 
	char nn3;
	for(i=0;postfix[i]!='\0';i++){
		c = postfix[i]; 
		if(isdigit(c)==1)
			push(s,c-'0');
		else {
			n1 = pop(s);
			n2 = pop(s); 
			switch(c){
				case '+':	push(s,n1+n2);  break;
				case '-': 	push(s,n2-n1);  break;
				case '*':	push(s,n1*n2);  break;
				case '/':	push(s,n2/n1);  break; 
				case '%':	push(s,n2%n1); 	break; 
			}
		}
	}
	return pop(s);	
}

