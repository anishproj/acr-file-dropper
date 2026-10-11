#include <stdio.h>
#include <stdlib.h>

void disp(int inp[10][10], int a, int b){
for (int i=0;i<a;i++)
{
	for (int j=0;j<b;j++)
	{
		printf("%d",inp[i][j]);
	}
	printf("\n");
}

}
//-----------------------------------------

void in(int inp[10][10], int a, int b){
for (int i=0;i<a;i++)
{
	for (int j=0;j<b;j++)
	{
		scanf("%d",&inp[i][j]);
	}
	//printf("\n");
}

}
//-----------------------------------------

void compact(int ip[10][10], int op [10][10], int r, int c){
op[0][0] = r;
op[0][1] = c;
int k = 1;

	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (ip[i][j]!=0)
			{
				op[k][0] = i;
				op[k][1] = j;
				op[k][2] = ip[i][j];
				k++;
			}
		
		}
	
	}


op[0][2] = k-1;

disp (op,op[0][2]+1,3);

}
//-----------------------------------------

void simple (int ip[10][10], int op [10][10], int r, int c)
{
int k=1;
op[0][0] = ip [0][1];
op[0][1] = ip [0][0];
op[0][2] = ip [0][2];

for (int i = 0 ; i < ip[0][1];i++)
{
	for (int j =1; j<=ip[0][2];j++)
	{
		if (ip[j][1]==i)
		{
			op[k][0] = ip[j][1];
			op[k][1] = ip[j][0];
			op[k][2] = ip[j][2];
			k++;
		}	
	
	}
	


}
printf("simple: k = %d\n",k);
disp (op,k,3);



}
//-----------------------------------------

void fast(int ip[10][10],int op [10][10])
{
int m,n,t;
m = ip[0][0];
n = ip[0][1];
t = ip[0][2];

 op[0][0]=n;
 op[0][1]=m;
 op[0][2]=t;

int S[10],T[10];

for (int i =0 ;i< n;i++)
{
	S[i] =0;
}

for (int i=1;i<=t;i++)
{
	S[ip[i][1]]++;
}
T[0] = 1;
for (int i=1;i<n;i++)
{
	T[i] = T[i-1]+S[i-1];
}

for (int i = 1;i<=t;i++)
{
	int j = ip[i][1];
	
	op[T[j]][0] = ip[i][1];
	op[T[j]][1] = ip[i][0];
	op[T[j]][2] = ip[i][2];
	T[j]++;
}


printf("fast: \n");
disp (op,op[0][2]+1,3);



}



//-----------------------------------------
int main (){

int input[10][10], output[10][10], o[10][10],row,col;
printf ("enter rows and cols\n");
scanf("%d",&row);
scanf("%d",&col);

printf ("enter data\n");
in(input,row,col);
printf("original matrix:\n");
disp(input,row,col);
printf("compact matrix:\n");
compact(input,output,row,col);
simple(output,o,row,col);
fast(output,o);


return 0;
}
