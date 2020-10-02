#include <stdio.h>
#include <stdlib.h>
#include "ticket.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue inputQ = createQueue();
	Queue outputQ = createQueue();
	int deleteFront,queueEmpty; 
	int exit = 0; 
	int choice,ticket,flag,flag2; 
	do{
		exit=0;
		menu();
		choice = getChoice();
		switch(choice){
			case 1:  ticket = inputTicket();
					 flag = ticketChecker(inputQ,ticket);
					 flag2 = ticketChecker(outputQ,ticket);
					 if(flag!=1 && flag2!=1)
					 	enqueue(inputQ,ticket);
					 else 
					 	printf("\nSeat is taken\n");
					 break; 
			case 2:  if(isQueueEmpty(inputQ)!=1){
				 		deleteFront=dequeue(inputQ);
						enqueue(outputQ,deleteFront);
					} else
						printf("\nPlease reserve ticket first\n");
					 break; 
			case 3:  printf("Program terminated");
					 exit=1;
					 break; 
			default: printf("\nPlease enter a right choice\n");
		}
		if(choice!=3)
			promptUser();
		if(outputQ->count==CAPACITY){
			printf("BUS IS NOW FULL");
			free(inputQ);
			free(outputQ);
			exit=1;
		}else {
			printf("\nReserved Seats: ");
			displayQueue(inputQ);
			if(outputQ->count!=0){
				printf("\nSeats Taken inside the Bus: ");
				displayQueue(outputQ);
			}
		}
	}while(exit!=1);
	return 0;
}
