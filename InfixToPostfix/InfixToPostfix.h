#define SIZE 100
#include "Stack.h"

int isValidInput(char infix[]);
void infixtopostfix(char infix[],char postfix[],Stack s);
int isDigit(stackItem item);
int precedence(char c);
float postfixEvaluate(char postfix[],Stack p);
float evaluate(stackItem n1, stackItem n2,float c);
void promptUser();
