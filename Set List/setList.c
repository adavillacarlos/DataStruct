#include <stdio.h>
#include <stdlib.h>
#include "setList.h"

Set initialize(){
	Set head = NULL;
	return head; 
}

void display(Set s){
	nodeptr ptr = s; 
	while(ptr!=NULL){
		printf("%d ",ptr->data); 
		ptr = ptr->next;
	}
	printf("\n");
}

int contains(Set s, int elem){
	nodeptr ptr = s; 
	while(ptr!=NULL){
		if(ptr->data==elem)
			return 1; 
		ptr = ptr->next;
	}
	return 0;
}
nodeptr createNode(int elem){
	nodeptr ptr; 
	ptr = (nodeptr) malloc (sizeof(Node));
	ptr->data = elem; 
	ptr->next = NULL;
	return ptr;
}

Set add(Set s, int elem){
	nodeptr temp; 
	if(contains(s,elem) == 0){
		temp = createNode(elem);
		temp->next = s; 
		s = temp;
	}
	return s; 
}

void getUnion(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		result = add(result,ptr1->data);
		ptr1 = ptr1->next;
	}
	while(ptr2!=NULL){
		if(contains(result,ptr2->data)==0)
			result=add(result,ptr2->data);
		ptr2 = ptr2->next;
	}
	display(result);
}

void intersection(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		if(contains(s2,ptr1->data)==1)
			result = add(result,ptr1->data); 
		ptr1 = ptr1->next;
	}
	display(result);
}

void difference(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2;
	while(ptr1!=NULL){
		if(contains(s2,ptr1->data)==0)
			result = add(result,ptr1->data);
		ptr1 = ptr1->next;
	}
	display(result);
}

void symmetricdifference(Set result, Set s1, Set s2){
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		if(contains(s2,ptr1->data)==0)
			result = add(result,ptr1->data);
		ptr1 = ptr1->next;
	}
	while(ptr2!=NULL){
		if(contains(s1,ptr2->data)==0)
			result = add(result,ptr2->data);
		ptr2 = ptr2->next;
	}
	display(result);
}

int subset(Set s1, Set s2){
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2;  
	while(ptr1!=NULL){
		if(contains(s2,ptr1->data)==0)
			return 0;
		ptr1 = ptr1->next;
	}
	return 1; 
}

int disjoint(Set s1, Set s2){
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		if(contains(s2,ptr1->data)==1)
			return 0; 
		ptr1 = ptr1->next;
	}
	return 1;
}

int equal(Set s1, Set s2){
//	nodeptr ptr1 = s1; 
//	nodeptr ptr2 = s2;
//	while(ptr1!=NULL && ptr2!=NULL){
//		if(contains(s1,ptr2->data)==0)
//			return 0;
//		if(contains(s2, ptr1->data)==0)
//			return 0;
//		ptr1 = ptr1->next;
//		ptr2 = ptr2->next;
//	}
//	return 1; 
	if(subset(s1,s2)==1 && subset(s2,s1)==1)
		return 1; 
	return 0;
}

void menu(){
	printf("\nMENU");
	printf("\n1. Add"); 
	printf("\n2. Display");
	printf("\n3. Contains");
	printf("\n4. Union");
	printf("\n5. Intersection"); 
	printf("\n6. Difference");
	printf("\n7. Symmetric Difference");
	printf("\n8. Subset");
	printf("\n9. Disjoint");
	printf("\n10. Equal"); 
	printf("\n11. Exit");
}

void menuSet(){
	printf("\n1. Set 1");
	printf("\n2. Set 2");
}
int choose(){
	int choice; 
	printf("\nPlease enter a number (1-11): "); 
	scanf("%d",&choice);
	return choice; 
}

int inputSet(){
	int ans; 
	printf("\nPlease enter a set: ");
	scanf("%d",&ans);
	return ans;
}
int inputElem(){
	int elem;
	printf("\nPlease enter an element: ");
	scanf("%d",&elem); 
	return elem;
}
void Exit(){
	printf("\nProgram Terminated");
	exit(1);
}

void promptUser(){
	fflush(stdin);
	printf("\n");
	system("pause");
	system("cls");
}
