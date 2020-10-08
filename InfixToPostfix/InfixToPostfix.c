#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

int isValidInput(char infix[]){
	int i,ans=0; 
	for(i=0;infix[i]!='\n';i++){
		if(isDigit(infix[i])!=0 || precedence(infix[i])!=0){
			ans = 1; 
		} else {
			ans = 0; 
			break; 
		}
	}
	return ans; 
}


void infixtopostfix(char infix[],char postfix[],Stack s){
	int i, j=0, ans; 
	char c; 
	for(i=0;infix[i]!='\n';i++){
		c = infix[i];
		if(isDigit(c)!=0){
			postfix[j++] = c;
		} else if (precedence(c)!=0){
			while(isEmpty(s)!=1 && precedence(c) <= precedence(stackTop(s)))
				postfix[j++] = pop(s);
			push(s,c);
		}
	}
	while(!isEmpty(s)){
		postfix[j++]= pop(s);
	}
	postfix[j] = '\0';
}


int precedence(char c){
	int ans=0; 
	if( c == '*' || c == '/' || c == '%' ) 
	 	ans = 2; 
    else if (c=='+' || c=='-')
		ans = 1; 
	return ans; 
}

float postfixEvaluate(char postfix[],Stack p){
	int i;
	float ans =0; 
	float n1,n2;
	char c;  
	for(i=0;postfix[i]!='\0';i++){
		c = postfix[i];
		if(isDigit(c))
			push(p,c-'0');
		else {
			n1 = pop(p);
			n2 = pop(p);
			ans = evaluate(n1,n2,c);
			push(p,ans);
		}
	}
	return pop(p);
}

float evaluate(stackItem n1, stackItem n2,float c){
	float ans = 0;
	if(c == '*')
		ans = n2 * n1;
	else if(c == '+')
		ans = n2 + n1;
	else if(c == '-')
		ans = n2 - n1;
	else if(c == '/')
		ans = n2 / (float) n1;
	else if(c=='%'){
		ans = (int)n2%(int)n1;
	}
	return ans;
}

void promptUser(){
	printf("\n");
	system("pause");
	system("cls");
}

int isDigit(stackItem item){
  return (int)item >= 48 && (int)item <= 57;
}
