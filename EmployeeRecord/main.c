#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(int argc, char *argv[]) {
	int size, choice; 
	double tax = 0, gross;
	payrecord payroll[100];
	while(1){
		menu();
		scanf("%d",&choice);
		switch(choice){
			case 1:		size = createSize();
						readRecords(payroll,size);
						break; 
			case 2:		gross = calcRecords(payroll,size,&tax);
						break; 
			case 3:		printRecords(payroll,size);
						break; 
			case 4:		printSummary(gross,tax);
						break; 
			case 5:		Exit();
						break;
			default:	printf("Please enter a valid choice");
		}
		printf("\n\n");
		system("pause");
		system("cls");
	}

	return 0;
}


