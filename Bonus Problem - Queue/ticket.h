#define CAPACITY 30

typedef struct node* Nodeptr;

typedef struct node{
	int data;
	Nodeptr next;
}QUEUE_NODE;

typedef struct{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;

typedef QUEUE_HEAD* Queue;

Queue createQueue();
Nodeptr createNode(int item);
void enqueue(Queue q, int item);
int dequeue(Queue q);
int ticketChecker(Queue q,int ticket);
int inputTicket();
void displayQueue(Queue q);
int isQueueEmpty(Queue q);
int queueFront(Queue q);
void freeQueue(Queue q);

void menu();
int getChoice();
int getItem();
void promptUser();
