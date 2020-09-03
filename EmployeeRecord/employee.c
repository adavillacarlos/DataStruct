#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "employee.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int createSize(){
	int size;
	printf("Enter size: ");
	scanf("%d",&size);
	return size;
}

void readName(payrecord payroll[], int i){
	printf("Last Name: "); 
	gets(payroll[i].name.last);
	printf("First Name: "); 
	gets(payroll[i].name.first);
	printf("Middle Name: "); 
	gets(payroll[i].name.middle);
}

void printName(payrecord payroll[], int i){
	gotoxy(10,3+i);
	printf("%s, %s %s", payroll[i].name.last, payroll[i].name.first, payroll[i].name.middle);
}

void printSummary(double gross, double tax){
	printf("\nTotal Gross: %.2lf",gross);
	printf("\nTotal Tax: %.2lf", tax);
}

void readRecords(payrecord payroll[], int n){
	int x;  
	for(x=0;x<n;x++){
		printf("\nRecord %d",x+1);
		printf("\nID: "); 
		scanf("%d",&payroll[x].id);
		fflush(stdin);
		readName(payroll,x);
		printf("Hours per Week: "); 
		scanf("%f",&payroll[x].hours);
		printf("Rate: ");
		scanf("%f",&payroll[x].rate);
	}
}

void printRecords(payrecord payroll[], int n){
	int x;
	system("cls");
	gotoxy(50,0); 			printf("PAYROLL");
	gotoxy(2,2); 			printf("ID"); 
	gotoxy(10,2);			printf("Name");
	gotoxy(40,2);			printf("Hours");
	gotoxy(50,2);			printf("Rate"); 
	gotoxy(60,2);			printf("Regular");
	gotoxy(75,2);			printf("Overtime"); 
	gotoxy(90,2);			printf("Gross"); 
	gotoxy(100,2);			printf("Tax"); 
	gotoxy(110,2);			printf("Net");
	for(x=0;x<n;x++){
		gotoxy(2,3+x);		printf("%d",payroll[x].id);
							printName(payroll,x);
		gotoxy(40,3+x);		printf("%.2f", payroll[x].hours);
		gotoxy(50,3+x); 	printf("%.2f", payroll[x].rate);
		gotoxy(60,3+x);		printf("%.2f", payroll[x].regular);
		gotoxy(75,3+x);		printf("%.2f", payroll[x].overtime);
		gotoxy(90,3+x);		printf("%.2f", payroll[x].gross);
		gotoxy(100,3+x);	printf("%.2f", payroll[x].tax_withheld);
		gotoxy(110,3+x);	printf("%.2f", payroll[x].net);
	}
}

double calcRecords(payrecord payroll[], int n, double *taxptr){
	int x; 
	double totalGross=0;
	float taxRate=0;
	for(x=0;x<n;x++){
		if(payroll[x].hours>40){
			payroll[x].regular = 40 * payroll[x].rate;
			payroll[x].overtime = (payroll[x].hours-40) * 1.5 * payroll[x].rate; 
		} else {
			payroll[x].regular = payroll[x].hours * payroll[x].rate;
			payroll[x].overtime = 0; 
		}
		payroll[x].gross = payroll[x].regular + payroll[x].overtime; 
		totalGross = totalGross + payroll[x].gross; 
		if(payroll[x].gross<500)
			taxRate = 0.15; 
		else if (payroll[x].gross<1000)
			taxRate = 0.28;
		else 
			taxRate = 0.33; 
		payroll[x].tax_withheld = payroll[x].gross * taxRate;
		*taxptr = *taxptr + payroll[x].tax_withheld; 
		payroll[x].net = payroll[x].gross - payroll[x].tax_withheld;
	}
	return totalGross; 
}

void menu(){
	printf("Menu"); 
	printf("\n[1] Create Pay Records");
	printf("\n[2] Calculate Records"); 
	printf("\n[3] Print Records"); 
	printf("\n[4] Print Summary");
	printf("\n[5] Exit");
	printf("\nEnter Choice: ");
	
}

void Exit(){
	printf("\n\nProgram has ended successfully");
	exit(1);
}


