typedef struct node* Nodeptr;

typedef struct node{
	int data;
	Nodeptr next;
}NODE;

typedef struct{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;

typedef struct {
    int count;
    Nodeptr top;
} STACK_HEAD;

typedef STACK_HEAD* Stack;
typedef QUEUE_HEAD* Queue;

Stack createStack();
Queue createQueue();
Nodeptr createNode(int item);

void push(Stack s,int item);
int pop(Stack s);
void displayStack(Stack s);
int isStackEmpty(Stack s);
int stackTop(Stack s);
void freeStack(Stack s);

void enqueue(Queue q, int item);
int dequeue(Queue q);
void displayQueue(Queue q);
int isQueueEmpty(Queue q);
int queueFront(Queue q);
void freeQueue(Queue q);

void menu();
int getChoice();
int getItem();
void promptUser();

