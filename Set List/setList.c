#include <stdio.h>
#include <stdlib.h>
#include "setList.h"

Set initialize(){
	//initializes the head to NULL
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
	//check if the element has a copy already in the set
	while(ptr!=NULL){
		if(ptr->data==elem)
			return 1; 
		ptr = ptr->next;
	}
	return 0;
}

nodeptr createNode(int elem){
	nodeptr ptr; 
	//allocates address for the node
	ptr = (nodeptr) malloc (sizeof(Node));
	ptr->data = elem; 
	//initializes the next node for NULL
	ptr->next = NULL;
	return ptr;
}

Set add(Set s, int elem){
	nodeptr temp; 
	//checks first if the element has a copy already
	if(contains(s,elem) == 0){
		//creates the node & places it as well. 
		temp = createNode(elem);
		//initialize the next node to the set 
		temp->next = s; 
		//initialize the set to the temp set. 
		s = temp;
	}
	return s; 
}

Set getUnion(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		//adds the first part of the result
		result = add(result,ptr1->data);
		ptr1 = ptr1->next;
	}
	while(ptr2!=NULL){
		//checks for the duplicates then adds it to the result set if there is none 
		if(contains(result,ptr2->data)==0)
			result=add(result,ptr2->data);
		ptr2 = ptr2->next;
	}
	printf("\nUnion Successful");
	return result; 
}

Set intersection(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		//checks copies of element of set 1 in set 2
		//adds if there is a duplicate on the result. 
		if(contains(s2,ptr1->data)==1)
			result = add(result,ptr1->data); 
		ptr1 = ptr1->next;
	}
	printf("\nIntersection Successful");
	return result; 
}

Set difference(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2;
	while(ptr1!=NULL){
		//checks if there is no copy of element of set 1 in set 2 
		//and if there is no copy of the element, add it on the result
		if(contains(s2,ptr1->data)==0)
			result = add(result,ptr1->data);
		ptr1 = ptr1->next;
	}
	printf("\nDifference Successful");
	return result; 
}

Set symmetricdifference(Set result, Set s1, Set s2){
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2; 
	while(ptr1!=NULL){
		//checks if there is no copy of elements of set 1 in set 2
		//adds them if there is none.
		if(contains(s2,ptr1->data)==0)
			result = add(result,ptr1->data);
		ptr1 = ptr1->next;
	}
	while(ptr2!=NULL){
		//checks if there is no copy of elements of set 2 in set 1
		//adds them if there is none
		if(contains(s1,ptr2->data)==0)
			result = add(result,ptr2->data);
		ptr2 = ptr2->next;
	}
	printf("\nSymmetric Difference Successful");
	return result;
}

int subset(Set s1, Set s2){
	nodeptr ptr1 = s1; 
	nodeptr ptr2 = s2;  
	while(ptr1!=NULL){
		//checks if there is no element of set 1 in set 2
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
		//checks if there is element of set 1 in set 2
		if(contains(s2,ptr1->data)==1)
			return 0; 
		ptr1 = ptr1->next;
	}
	return 1;
}

int equal(Set s1, Set s2){
	//calls the subset to check if the all elements in the set
	// are present in the opposite set. 
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
