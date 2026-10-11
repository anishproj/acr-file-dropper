//matrix addition:
#include  <stdio.h>

void add(int a[10][10],int b[10][10], int l,int w){
int c[10][10];

for (int i =0;i<l;i++){

    for (int j =0;j<w;j++){
    
    c[i][j] = a[i][j]+ b[i][j];
    
    }



}

disp (c,l,w);

}


void disp(int m[10][10], int l,int w){

for (int i =0;i<l;i++){

    for (int j =0;j<w;j++){
    
   printf(" %d\t",m[i][j]);
    
    }
    printf("\n");



}


}


void input(int m[10][10], int l,int w){

for (int i =0;i<l;i++){

    for (int j =0;j<w;j++){
    
   printf("\nenter input %d%d ",i,j);
   scanf ("%d",&m[i][j]);
    
    }
    printf("\n");



}


}



int main (){

int mat [10][10], mat2 [10][10];


printf ("test");

input (mat,3,3);
input (mat2,3,3);
add (mat,mat2,3,3);


printf("\n");
return 0;
}
