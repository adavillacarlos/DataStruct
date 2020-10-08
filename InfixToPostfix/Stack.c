#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack createStack(){
 	Stack s = (Stack)malloc(sizeof(STACK_HEAD));
    s->count = 0;
    s->top = NULL;
    return s;
}

Nodeptr createNode(stackItem item){
	Nodeptr ptr = (Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data = item; 
	ptr->next = NULL;
	return ptr; 
}

void push(Stack s,stackItem item){
	Nodeptr temp = createNode(item);
	temp->next = s->top;
	s->top = temp;
	(s->count)++; 
}

stackItem pop(Stack s){
	Nodeptr	temp = s->top; 
	stackItem ans = temp->data; 
	s->top = temp->next; 
	temp->next = NULL;
	free(temp);
	(s->count)--;
	return ans; 
}

void displayStack(Stack s){
	Nodeptr ptr = s->top;
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next; 
	}
	printf("\n");
}

stackItem isStackEmpty(Stack s){
	return s->top == NULL;
}

stackItem stackTop(Stack s){
	return s->top->data;	
}

void freeStack(Stack s){
	Nodeptr temp;
	while(s->top!=NULL){
		temp = s->top;
		s->top = s->top->next;
		temp->next = NULL; 
		free(temp);
		(s->count)--;
	}
}
