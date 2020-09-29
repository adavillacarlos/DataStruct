#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack inputStack = createStack();
	Stack outputStack = createStack(); 
	Queue inputQueue = createQueue();
	Queue outputQueue = createQueue();
	int deleteTop, deleteFront; 
	int exit = 0; 
	int choice,item; 
	
	do{
		exit=0;
		menu();
		choice = getChoice();
		switch(choice){
			case 1:  item = getItem();
					 push(inputStack,item);
					 enqueue(inputQueue,item);
					 break; 
			case 2:  deleteTop = stackTop(inputStack);
					 pop(inputStack);
					 enqueue(outputQueue,deleteTop);
					 deleteFront = queueFront(inputQueue);
					 dequeue(inputQueue);
					 push(outputStack,deleteFront);
					 break; 
			case 3:  exit=1;
					 break; 
			default: printf("\nPlease enter a right choice\n");
		}
		if(choice!=3)
			promptUser();
		
		if(isStackEmpty(inputStack)==1 && isQueueEmpty(inputQueue)==1){
			printf("\nOutput Stack: "); 
			displayStack(outputStack);
			printf("\nOutput Queue: ");
			displayQueue(outputQueue);
		} else {
			printf("\nInput Stack: ");
			displayStack(inputStack);
			printf("\nInput Queue: ");
			displayQueue(inputQueue);
		}
		
	}while(exit!=1);
	return 0;
}
