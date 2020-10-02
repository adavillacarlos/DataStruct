#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack inputS = createStack();
	Stack outputS = createStack(); 
	Queue inputQ = createQueue();
	Queue outputQ = createQueue();
	int deleteTop, deleteFront,choice,item; 
	int flag=0;
	int exit = 0; 
	do{
		menu();
		choice = getChoice();
		switch(choice){
			case 1:  item = getItem();
					 push(inputS,item);
					 enqueue(inputQ,item);
					 flag=1;
					 break; 
			case 2: if(flag==1){
					 	deleteTop = pop(inputS);
					 	enqueue(outputQ,deleteTop);
					 	deleteFront=dequeue(inputQ);
					 	push(outputS,deleteFront);
				   	} else {
				   		printf("\nPlease insert a number first\n");
				   		flag=0;
					}
					 break;
			case 3:  exit=1;
					 printf("\nProgram terminated\n");
					 break; 
			default: printf("\nPlease enter a right choice\n");
		}
		
		if(choice!=3)
			promptUser();
		if(isStackEmpty(inputS)!=1 && isQueueEmpty(inputQ)!=1){
			printf("\nInput Stack: ");
			displayStack(inputS);
			printf("\nInput Queue: ");
			displayQueue(inputQ);
		} else if (flag!=0)
			exit=1;
		
	}while(exit!=1);
	
	if(isQueueEmpty(outputQ)!=1 && isStackEmpty(outputS)!=1){
		printf("\nOutput Stack: "); 
		displayStack(outputS);
		freeStack(outputS);
		printf("\nOutput Queue: ");
		displayQueue(outputQ);
		freeQueue(outputQ);
	}		
	return 0;
}
