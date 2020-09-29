#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

Stack createStack(){
 	Stack s = (Stack)malloc(sizeof(STACK_HEAD));
    s->count = 0;
    s->top = NULL;
    return s;
}

Queue createQueue(){
	Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
	q->front = q->rear = NULL;
	q->count = 0; 
	return q;
}

Nodeptr createNode(int item){
	Nodeptr ptr = (Nodeptr)malloc(sizeof(NODE));
	ptr->data = item; 
	ptr->next = NULL;
	return ptr; 
}

void push(Stack s,int item){
	Nodeptr temp = createNode(item);
	temp->next = s->top;
	s->top = temp;
	(s->count)++; 
}

void pop(Stack s){
	Nodeptr	temp = s->top; 
	s->top = temp->next; 
	temp->next = NULL;
	free(temp);
	(s->count)--;
}

void displayStack(Stack s){
	Nodeptr ptr = s->top;
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next; 
	}
	printf("\n");
}

int isStackEmpty(Stack s){
	return s->top == NULL;
}

int stackTop(Stack s){
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

//Queue
void enqueue(Queue q, int item){
	Nodeptr temp = createNode(item);
	if(isQueueEmpty(q))
		q->front = temp; 
	else
		q->rear->next = temp; 
	q->rear = temp; 
	(q->count)++;
}

void dequeue(Queue q){
	Nodeptr temp = q->front; 
	if(q->count==1)
		q->rear=NULL;
	q->front = q->front->next; 
	temp->next = NULL;
	free(temp);
	q->count--;	
}

void displayQueue(Queue q){
	Nodeptr ptr = q->front; 
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next; 
	}
	printf("\n");;
}

int isQueueEmpty(Queue q){
	return q->count==0;
}

int queueFront(Queue q){
	return q->front->data; 
}

void freeQueue(Queue q){
	Nodeptr temp; 
	while(q->front!=NULL){
		temp = q->front;
		q->front = q->front->next;
		temp->next = NULL; 
		free(temp);
		(q->count)--;
	}
}


//Helper Functions

void menu(){
	printf("\nMENU\n");
	printf("\n[1] Insert Integer");
	printf("\n[2] Delete Integer");
	printf("\n[3] Exit");
}

int getChoice(){
	int ans; 
	printf("\nEnter choice: ");
	scanf("%d",&ans);
	return ans;
}

int getItem(){
	int ans; 
	printf("\nEnter item: ");
	scanf("%d",&ans);
	return ans;
}

void promptUser(){
	system("pause");
	system("cls");
}


