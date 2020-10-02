#include <stdio.h>
#include <stdlib.h>
#include "ticket.h"

Queue createQueue(){
	Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
	q->front = q->rear = NULL;
	q->count = 0; 
	return q;
}

Nodeptr createNode(int item){
	Nodeptr ptr = (Nodeptr)malloc(sizeof(QUEUE_NODE));
	ptr->data = item; 
	ptr->next = NULL;
	return ptr; 
}

void enqueue(Queue q, int item){
	Nodeptr temp = createNode(item);
	if(isQueueEmpty(q))
		q->front = temp; 
	else
		q->rear->next = temp; 
	q->rear = temp; 
	(q->count)++;
}

int dequeue(Queue q){
	Nodeptr temp = q->front; 
	int ans = temp->data;
	if(q->count==1)
		q->rear=NULL;
	q->front = q->front->next; 
	temp->next = NULL;
	free(temp);
	q->count--;	
	return ans; 
}

int ticketChecker(Queue q,int ticket){
	Nodeptr ptr = q->front; 
	int flag=0;
	while(ptr!=NULL){
		if(ptr->data==ticket){
			flag=1;
			break; 
		}
		ptr = ptr->next; 
	}
	return flag; 
}

int inputTicket(){
	int n; 
	do{
		printf("Enter seat number: ");
		scanf("%d",&n);
	}while(n>CAPACITY);
	return n;
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

void menu(){
	printf("\nMENU\n");
	printf("\n[1] Get Ticket");
	printf("\n[2] Submit Ticket");
	printf("\n[3] Exit");
}

int getChoice(){
	int ans; 
	printf("\nEnter choice: ");
	scanf("%d",&ans);
	return ans;
}

void promptUser(){
	system("pause");
	system("cls");
}
