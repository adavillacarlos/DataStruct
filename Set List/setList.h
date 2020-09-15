typedef struct node* nodeptr;
typedef struct node{
	int data;
	nodeptr next;
}Node;
typedef Node* Set;

Set initialize();
//- simply initialize to NULL

void display(Set s);
//- display on the screen all valid elements of the list

Set add(Set s, int elem);
//- simply store elem in the list

int contains(Set s, int elem);
//- search the array elements for the value elem

Set getUnion(Set result, Set s1, Set s2);
//- store in the set result the set resulting from the union of s1 and s2
//- x is an element of s1 union s2 if x is an element of s1 or x is an element of s2

Set intersection(Set result, Set s1, Set s2);
//- store in the set result the set resulting from the intersection of s1 and s2
//- x is an element of s1 intersection s2 if x is an element of s1 and x is an element of s2

Set difference(Set result, Set s1, Set s2);
//- store in the set result the set resulting from the difference of s1 and s2
//- x is an element of s1 - s2 if x is an element of s1 and x is not an element of s2

Set symmetricdifference(Set result, Set s1, Set s2);
//- store in the set result the set resulting from the symmetric difference of s1 and s2
//- x is an element of s1 - s2 if x is an element of s1 and x is not an element of s2 and vice
//versa

int subset(Set s1, Set s2);
//- s1 is a subset of s2 if all elements of s1 are in s2

int disjoint(Set s1, Set s2);
//- two sets are disjoint if the intersection is empty

int equal(Set s1, Set s2);
//- two sets are equal if they have exactly the same elements


//helper functions
nodeptr createNode(int elem);
//- creates a node

void menu(); 
//-main menu

void menuSet();
//-submenu for the sets 

int choose();
//-input choice for the main menu

int inputSet();
//-input choice for the submenu

int inputElem();
//-add element in the set

void Exit();
//-terminates the program

void promptUser();
//-clears the terminal 
