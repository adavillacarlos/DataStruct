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

Stack createStack();
Nodeptr createNode(stackItem item);
void push(Stack s,stackItem item);
stackItem pop(Stack s);
void displayStack(Stack s);
stackItem isStackEmpty(Stack s); 
stackItem stackTop(Stack s); 
void freeStack(Stack s); 

