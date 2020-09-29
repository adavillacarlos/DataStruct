#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack inputS = createStack();
	Stack outputS = createStack(); 
	Queue inputQ = createQueue();
	Queue outputQ = createQueue();
	int deleteTop, deleteFront; 
	int exit = 0; 
	int choice,item; 
	
	do{
		exit=0;
		menu();
		choice = getChoice();
		switch(choice){
			case 1:  item = getItem();
					 push(inputS,item);
					 enqueue(inputQ,item);
					 break; 
			case 2:  deleteTop = stackTop(inputS);
					 pop(inputS);
					 enqueue(outputQ,deleteTop);
					 deleteFront = queueFront(inputQ);
					 dequeue(inputQ);
					 push(outputS,deleteFront);
					 break; 
			case 3:  exit=1;
					 break; 
			default: printf("\nPlease enter a right choice\n");
		}
		if(choice!=3)
			promptUser();
		if(isStackEmpty(inputS)==1 && isQueueEmpty(inputQ)==1)
			exit = 1;
		else {
			printf("\nInput Stack: ");
			displayStack(inputS);
			printf("\nInput Queue: ");
			displayQueue(inputQ);
		}		
	}while(exit!=1);
	if(isStackEmpty(inputS)==1 && isQueueEmpty(inputQ)==1){
		printf("\nOutput Stack: "); 
		displayStack(outputS);
		free(outputS);
		printf("\nOutput Queue: ");
		displayQueue(outputQ);
		free(outputQ);
	}
	return 0;
}
