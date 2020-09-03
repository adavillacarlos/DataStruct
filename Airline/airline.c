#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "airline.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initSeats(int seats[], int size){
	int i; 
	for(i=0;i<size;i++) 
		seats[i] = 0;
}

void displaySeats(int seats[], int size){
	box(20,80,1,25);
	int i; 
	gotoxy(40, 3);	printf("Welcome to MGM Airlines!");
	gotoxy(25,5); 	printf("First Class Section: ");
	gotoxy(25,7);	printf("Economy Section: "); 
	
	for(i=0;i<size;i++){
		if(i<size/2){
			gotoxy(50+i*3,5);	printf("[%d]", seats[i]);
		} else {
			gotoxy(35+i*3,7);	printf("[%d]", seats[i]);
		}
	}
	menu();
}

int assignSeat(int st[], int size, int seatType){
	int seat;
	int move; 
	switch(seatType){
		case 1:		seat = assignFirstClass(st,size);
					break;
		case 2:		seat = assignEconomy(st,size);
					break; 	
	}
	if(seat==-1){
		move = moveSeat(seatType);
		if(move==-1)
			return move;
		return assignSeat(st,size,move);
	}
	return seat; 
}

int assignFirstClass(int seats[], int size){
	int i; 
	for(i=0;i<size/2;i++){
		if(seats[i]==0){
			seats[i]=1;
			return i+1;
		}
	}
	return -1;
}

int assignEconomy(int seats[], int size){
	int i; 
	for(i=size/2;i<size;i++){
		if(seats[i]==0){
			seats[i]=1;
			return i+1;
		}
	}
	return -1;
}

void boardPass(int seat){
	box(40,60,15,20);
	gotoxy(42,16);		printf("BOARDING PASS");
	gotoxy(43,18);
	if(seat<5)
		printf("First Class");
	else 
		printf("Economy Class");
	gotoxy(43,19);	printf("Seat Number: %d", seat);
	getche();
}

int moveSeat(int seatType){
	char ans; 
		gotoxy(25,13); 	
	if(seatType==1){
		printf("Would you like to transfer to Economy Class? (y/n): ");
		seatType = 2;
	} else {
		printf("Would you like to transfer to First Class? (y/n): ");
		seatType= 1; 
	}
	
	ans = getche(); 
	if(ans=='n')
		seatType = -1;
	return seatType;
}

void Exit(void){
	system("cls");
	box(20,80,1,10);
	gotoxy(35,5);
	printf("Next flight leaves in 3 hours!");
	gotoxy(30,15); 
	exit(0); 
}

void menu(){
	gotoxy(25,10);	printf("Please type 1 for \"first class\"");
	gotoxy(25,11);	printf("Please type 2 for \"economy\": ");
}

int choice(){
	int seatType; 
	scanf("%d", &seatType);
	if(seatType == 1 || seatType == 2)
		return seatType; 
	else {
		gotoxy(25,13);	printf("Please choose a valid class");
		getche();
		return -1;
	}
}

void box(int x1, int x2, int y1, int y2){
	int x, y; 
	
	//upper part
	for(x=x1; x<=x2; x++){
		gotoxy(x,y1);	putchar(205);
	}
	
	//lower part
	for(x=x1; x<=x2; x++){
		gotoxy(x,y2); 	putchar(205);
	}
	
	//leftside
	for(y=y1; y<=y2; y++){
		gotoxy(x1,y); 	putchar(186);
	}
	
	//rightside
	for(y=y1; y<=y2; y++){
		gotoxy(x2,y); 	putchar(186);
	}
	
	//upperleft
	gotoxy(x1, y1); putchar(201);
	
	//upper right
	gotoxy(x2,y1); 	putchar(187);
	
	//lower left
	gotoxy(x1,y2); 	putchar(200);
	
	//lower right
	gotoxy(x2,y2);  putchar(188);

}


