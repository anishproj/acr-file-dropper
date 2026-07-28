//------------linear search-----------

#include<stdio.h>
#include<stdlib.h>

typedef struct {

char name [100];
int roll;
float marks;



} student;

void display(student s[10],int size){

printf ("Student\t\t\t Name \t\t\t Roll \t\t\t marks \t\t\t \n");

for (int i=0;i<size;i++){

printf("%d\t\t\t %s \t\t\t %d \t\t\t %f \n",i, s[i].name,s[i].roll,s[i].marks);





		}
}

void linearSearch (student s[10], int size,int rollquery){

for (int i=0;i<size;i++){

if (s[i].roll == rollquery ){

printf("\n found data for %d roll no: \t name: %s \t marks: %f\n",rollquery,s[i].name,s[i].marks);
return;
}
else {

}


}
printf ("not found!!\n");

}

void binarySearch (student s[10] , int size, int rollquery){

int low = 0;
int high = size-1;

for (int i =0;i<size;i++){
int mid = low + (high-low)/2;

if (s[i].roll == rollquery){

printf("\n found data for %d roll no: \t name: %s \t marks: %f\n",rollquery,s[i].name,s[i].marks);
return;

}
else if (s[i].roll > rollquery){
 low = mid +1;


}
else {high = mid-1;}




}
printf ("not found!!\n");


}

void binarySearchRecursive(student s[10] , int low, int high,  int rollquery){
if (!(low>=high)){

int mid = low + (high-low)/2;

if (s[mid].roll == rollquery){
printf("\n found data for %d roll no: \t name: %s \t marks: %f\n",rollquery,s[mid].name,s[mid].marks);
return;

}
else if (rollquery > mid) {

return binarySearchRecursive(s,mid+1 , high , rollquery);

}
else {
return binarySearchRecursive(s,mid-1 , high , rollquery);

}



}

printf("not found!!\n");




}

// sort:
void selectionsort(student s[10], size){

int n = size;
int minpos = i ;

int rtemp;
float mtemp;
char ntemp [10];

student temp;
temp t[10];

for (int i =0; i<n-2;i++){


minpos = i ;
	
	for (int j = 0 ; j< n-1;j++){
	
	if (s[j].marks <s[minpos].marks)
	{
	
	minpos = j;
	}
	
	
}

if (minpos != i ){

temp = s[i];


/*


rtemp = s[i].roll;
mtemp = s[i].marks;
ntemp = s[i].name;

 s[i].roll = s[minpos].roll;
s[i].marks = s[minpos].marks;
 s[i].name = s[minpos].name;

s[minpos].roll = rtemp;
 s[minpos].name = ntemp;
 s[minpos].;

*/


}
	




}







}


void accept(student s[10],int size){

for (int i=0;i<size;i++){

printf("enter student %d name\n",i);
scanf("%s", s[i].name);

printf("enter student %d roll no\n",i);
scanf("%d",& s[i].roll);

printf("enter student %d marks\n",i);
scanf("%f", & s[i].marks);




}


}


int main (){

int size, rollquery , input;

printf("Enter student data size");
scanf ("%d",&size);
student  s1 [10];

accept (s1,size);

printf ("select option: \n1)display\n2)linear search \n3)binary search \n4)binary search recursive \n 5) exit");
scanf ("%d",&input);

while (1){


if(input ==1){
display (s1,size);


}
else if(input ==2){
printf("Enter student roll no to search for \n");
scanf ("%d",&rollquery);

linearSearch (s1,size,rollquery);

exit(0);




}
else if(input ==3){

printf("Enter student roll no to search for \n");
scanf ("%d",&rollquery);
printf("binary search: ------ \n");

binarySearch(s1,size,rollquery);
exit(0);

}
else if(input ==4){
printf("Enter student roll no to search for \n");
scanf ("%d",&rollquery);


printf("recusrive binary search: ------ \n");

binarySearchRecursive(s1,0,size-1,rollquery);
exit(0);

}
else if(input ==5){
exit(0);

}


else printf("invalid input!!\n");









}













return 0;
}
