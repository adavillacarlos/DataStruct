#define SIZE 100
typedef struct node* Nodeptr;

typedef struct{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;
typedef float stackItem; 

typedef struct node{
	stackItem data;
	Nodeptr next;
}STACK_NODE;

Stack newStack();
void freeStack(Stack s);
void push(Stack s,stackItem item); 
stackItem pop(Stack s); 
stackItem stackTop(Stack s); 
int isEmpty(Stack s);
void display(Stack s);
Nodeptr createNode(stackItem item);

int isValidInput(char infix[]);
void infixtopostfix(char infix[],char postfix[],Stack s);
int isDigit(stackItem item);
int precedence(char c);
float postfixEvaluate(char postfix[],Stack p);
float evaluate(stackItem n1, stackItem n2,char c);
void promptUser();
