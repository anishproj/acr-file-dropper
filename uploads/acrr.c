#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define max 100

void post_infix(char post[max]){


char stk[max][max];

int t = -1; 


char op1[max], op2 [max] , E1 [max], x;



 int l = strlen (post); //-1;
 
 for (int i =0 ; i< l; i++){
 
 x = post[i];
  
 	if (isalnum(x)){
 	
 	char tkn[2] = {x, '\0'};
 	t++;
	strcpy (stk[t] ,tkn);
	 
 	
 	
 	
 	}
 	
 	else {
 	
 	if (t<1) {printf ("invalid expression! \n");
 	return;
 	}
 	
 	
 	
 	strcpy (op2, stk[t--]);
 	strcpy (op1 ,stk[t--]);
 	
 	 strcpy(E1, "(");
         strcat(E1, op1);
            
           
        char opstr[2] = {x, '\0'};
        strcat(E1, opstr);
            
        strcat(E1, op2);
        strcat(E1, ")");

          
        t++;
        strcpy(stk[t], E1);
 
 
 
 
 }
 if (t == 0) {
        printf("infix exp: %s\n", stk[t]);
    } else {
        printf("err invalid exp\n");
    }
 
 
 }// end of function-
 
 
 
 int main (){
 
 char input[100];
 
 printf ("enter expression \n");
 scanf("%s",input);
 post_infix (input);
 
 
 
 
 return 0 ;
 
 }
 
 
 
