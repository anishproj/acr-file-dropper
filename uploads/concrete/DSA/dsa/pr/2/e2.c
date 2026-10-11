#include <stdio.h>

void disp (int a[10][10],int l,int w){
for (int i=0;i<l;i++){

	for (int j =0 ;j <w;j++){
	
	printf ("%d ",a[i][j]);	
	
	}
	printf ("\n");
}

}
//-------------------------------------------
void simple (int a[10][10], int b[10][10]){
int r = a[0][0];
int c = a[0][1];
int d = a[0][2];
printf("----------simple");
b[0][0] = c; b[0][1] = r;  b[0][2] = d;
int k = 1;
for (int i =0; i < c;i++){
	for (int j =1 ; j< d;j++){
		if (a[j][1] = i){
			b[k][0] = a[j][1];
			b[k][1] = a[j][0];
			b[k][2] = a[j][2];
			k++;
			
		
		}	


	}
	
}

disp (b,k,3);




}

void fast_tran(int a[10][3], int b[10][3]){
printf("inside");
int m = a[0][0];
int n = a[0][1];
int t = a[0][2];

if (t==0) return;

b[0][0] = n;
b[0][1] = m;
b[0][2] = t;

int s[10],T[10];

for (int i=0;i<n;i++) s[i] = 0;
T[0] = 1;
for (int i=1;i<=t;i++){
	s[a[i][1]]++;

}

for (int i=1;i<n;i++){
T[i] = T[i-1]+s[i-1];
}

for (int i=1;i<=t;i++){
	int j = a[i][1];
	b[T[j]][0] = a[i][1];
	b[T[j]][1] = a[i][0];
	b[T[j]][2] = a[i][2];
	T[j]++;

	}

printf("disp :\n");
disp(b,t,3);

}





//------------------------------------------
void compact (int a[10][10], int b[10][10], int rows,int cols){
b[0][0] = rows; b[0][1] = cols;
int k =1;
for (int i=0;i<rows;i++){
	for (int j =0 ; j<cols;j++)

		{
			if (a[i][j]!=0){
			
				b[k][0] = i;
				b[k][1] = j;
				b[k][2]= a[i][j];			
				k++;
			}

		}
	}
b[0][2] = k-1;
disp (b,k,3);


}

void input (int a[10][10],int l,int w){
for (int i=0;i<l;i++){


	for (int j =0 ;j <w;j++){
	
	
		scanf ("%d",&a[i][j]);	

	}
	
}

}

int main (){

int inp[10][10], op[10][10];

input(inp,3,3);
compact (inp,op,3,3);
//disp (inp,3,3);
printf("\n----------------------\n");
fast_tran (inp,op);

printf ("\n");
return 0;
}
