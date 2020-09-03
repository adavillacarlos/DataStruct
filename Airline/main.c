#include <stdio.h>
#include <stdlib.h>
#include "airline.h"

int main(int argc, char *argv[]) {
	int seats[SIZE];
	int seatType,seat;
	initSeats(seats,SIZE);
	while(1){
		if(seats[SIZE/2-1]==1 && seats[SIZE-1]==1)
			Exit();
		else {
			system("cls");
			displaySeats(seats,SIZE);
			seatType = choice();
			if(seatType!=-1){
				seat = assignSeat(seats,SIZE,seatType);
				if(seat!=-1)
					boardPass(seat);
				else 
					Exit();
			}
		}
	}
	
	return 0;
}
