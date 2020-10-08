#define SIZE 100
#include "Stack.h"

int getChoice();
void promptUser();
int isDigitPresent(stackItem postfix[]);
int precedence(stackItem c); 
int isValidInput(stackItem infix[]);

void infixToPostfix(stackItem infix[],stackItem postfix[],Stack s);
int postfixEval(stackItem postfix[],Stack s);
