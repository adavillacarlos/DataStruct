#define SIZE 10

//initialize seats to 0
void initSeats(int seats[], int size);

//display seats
void displaySeats(int seats[], int size);

//returns seat number if the assignment of the seat is successful,
//calls assignFirstClass() if seatType is 1
// and assign Economy if seatType is 2. 
int assignSeat(int st[], int size, int seatType);

//assign seat and returns seatNumber, 
//if there's no available seatNumber, returns -1. 
int assignFirstClass(int seats[], int size);

//assigns seat and returns seatNumber,
//if there's no available seatNumber, returns -1. 
int assignEconomy(int seats[], int size);

//displays the boarding pass
void boardPass(int seat);

//displays exit message if all the seats are taken 
//or when the person doesn't want to take a seat. 
void Exit(void);

//If the person wished to change the seat type.
int moveSeat(int seatType);

//asks the person for seat type
int choice();

//shows the person the possible choices 
void menu();

//for spacing purposes
void gotoxy(int x, int y); 

//creating a box
void box(int x1, int x2, int y1, int y2);
