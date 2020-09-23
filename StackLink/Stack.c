#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int isValidInput(stackItem symbols[]){
	int i,ans=0; 
	for(i=0;symbols[i]!='\n';i++){
		if(symbols[i] == '(' || symbols[i]==')' || 
		   symbols[i] == '[' || symbols[i]==']' ||
		   symbols[i] == '{' || symbols[i]=='}')
			ans=1;
		else {
			ans=0; 
			break;
		}
	}
	return ans; 
}


Stack newStack(){
	Stack s = (Stack) malloc(sizeof(STACK_HEAD));
	s->count = 0; 
	s->top=NULL;
	return s;
}

Nodeptr createNode(stackItem item){
	Nodeptr ptr = (Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data = item; 
	ptr->next = NULL;
	return ptr;
}

void freeStack(Stack s){
	Nodeptr temp;
	while(s->top!=NULL){
		temp = s->top;
		s->top = s->top->next;
		temp->next = NULL; 
		free(temp);
	}
	return;
}

void push(Stack s,stackItem item){
	Nodeptr temp = createNode(item);
	temp->next = s->top;
	s->top = temp;
	(s->count)++; 
	return;
}

void pop(Stack s){
	Nodeptr temp; 
	temp = s->top; 
	s->top = temp->next; 
	temp->next = NULL;
	free(temp);
	(s->count)--;
	return;
}

stackItem stackTop(Stack s){
	return s->top->data;	
}

int isEmpty(Stack s){
	return s->top == NULL;
}

int isValid(Stack s, stackItem symbols[]){
	int i, ans=1; 
	int pair=1;
	stackItem top;
	//used \n because used fgets for input
	for(i=0;symbols[i]!='\n';i++){
		if(symbols[i]=='(' || symbols[i]=='{' || symbols[i] == '['){
			push(s,symbols[i]);
		} else {
			if(isEmpty(s)){
				ans = 0;
				break; 
			} else {
				top = stackTop(s);
				if(isPair(symbols[i],top)){
					pop(s);
					ans = 1; 
				} else {
					ans = 0; 
					break; 
				}
			}
		}
	}
	return (isEmpty(s) && ans==1);
}

int isPair(stackItem item,stackItem top){
	int ans;
	if(top=='(' && item ==')')
		ans=1; 
	else if (top=='{' && item=='}')
		ans=1;
	else if(top=='[' && item==']')
		ans = 1; 
	else 
		ans=0;
	return ans;  
}

void display(Stack s){
	Nodeptr ptr = s->top;
	while(ptr!=NULL){
		printf("%c ", ptr->data);
		ptr = ptr->next; 
	}
	printf("\n");
	return;
}

void printDisplay(Stack s,int status){
	if(status!=1){
		if(s->top!=NULL){
			printf("Remaining Stack: \n");
			display(s);
		}
	} else
		printf("Stack is empty due to balanced symbols\n");
	return;
}

void Exit(){
	printf("Program Terminated");
	exit(1);
	return; 
}
