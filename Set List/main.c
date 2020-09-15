#include <stdio.h>
#include <stdlib.h>
#include "setList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Set s1 = initialize();
	Set s2 = initialize();
	Set result = initialize();
	int choice,elem,ans,flag; 
	while(1){
		menu();
		choice=choose();
		switch(choice){
			case 1:		menuSet();
						ans = inputSet();
						elem = inputElem();
						if(ans==1)
							s1= add(s1,elem); 
						else if (ans ==2)
							s2 = add(s2,elem); 
						else
							printf("\nPlease enter 1 or 2");
						break; 	
						
			case 2:		menuSet();
						printf("\n3. Set Result");
						ans = inputSet();
						if(ans==1)
							display(s1);
						else if (ans==2)
							display(s2);
						else if (ans==3)
							display(result);
						else 
							printf("\nPlease enter 1 or 2");
						break;
						
			case 3:		menuSet();
						ans = inputSet();
						elem = inputElem();
						if(ans==1)
							flag = contains(s1,elem); 
						else if (ans==2)
							flag = contains(s2,elem); 
						else
							printf("\nPlease enter 1 or 2");
						if(flag==1)
							printf("\nIt is in the Set");
						else 
							printf("\nIt is not in the Set");
						break; 
			
			case 4: 	result=getUnion(result,s1,s2);
						break; 
						
			case 5:		result=intersection(result,s1,s2);
						break; 
						
			case 6:		result=difference(result,s1,s2);
						break; 
			
			case 7:		result=symmetricdifference(result,s1,s2);
						break; 
			
			case 8:		flag = subset(s1,s2);
						if(flag==1)
							printf("\nIt is subset"); 
						else 
							printf("\nIt is not");
						break; 
			
			case 9:		flag = disjoint(s1,s2);
						if(flag==1)
							printf("\nIt is disjoint"); 
						else 
							printf("\nIt is not");
						break; 
			
			case 10: 	flag = equal(s1,s2);
						if(flag==1)
							printf("\nIt is equal"); 
						else 
							printf("\nIt is not");
						break;
			
			case 11:	Exit();
						break;
			default: printf("\nPlease enter 1-11");
		}
		promptUser();
	}
	return 0;
}
