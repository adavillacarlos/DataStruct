#define SIZE 100
typedef struct node* Nodeptr;

typedef struct{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef char stackItem; 

typedef struct node{
	stackItem data;
	Nodeptr next;
}STACK_NODE;


Stack newStack();
void freeStack(Stack s);
void push(Stack s,stackItem item); // insert at the top - push
void pop(Stack s); // deleting the top element - pop
stackItem stackTop(Stack s); // returns the top item
int isEmpty(Stack s);
void display(Stack s);

Nodeptr createNode(stackItem item);
int isValid(Stack s, stackItem symbols[]);
int isValidInput(stackItem symbols[]);
void printDisplay(Stack s,int status);
int isPair(stackItem item,stackItem top);
void Exit();

