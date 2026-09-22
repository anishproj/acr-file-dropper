#include <stdio.h>
#include <string.h>
#define max 100


void prepost (char E[max]){

char stk [max][max] ,op1[max], op2[max];
char x;
int t = -1;
int l = strlen (E);

for (i =0; i<l; i++){

	x = E[i];
	if (isalnum(x){
	char tkn[2] = {x, '\0'};
	t++;
	strcpy (stk [t], tkn);

	
	}

	else {
	
	if (t<1) {
	
	printf("invalid expression!");
	return;
	 
	
	}
	
	strcpy (op1, stk[t--]);
	strcpy (op2, stk[t--]);
	
	strcpy(E2 , "(");
	strcat(E1, op1);
	
	char opstr [2] = {x, '\0'};
	
	strcat (E2, opstr);
	strcat (E2, op1);
	strcat (E1 , ")");
	
	t++;
	

	
	}

}
















}
