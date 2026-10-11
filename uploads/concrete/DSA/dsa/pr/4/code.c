#include <stdio.h>
#include <string.h>


typedef struct student {
	char name[100];
	int roll;
	

} stud;

void disp (stud s[10] , int j){

for (int i =0;i<j;i++)
{
	printf("%d %s \t",s[i].roll , s[i].name);
}
printf("\n");
}

void linearsearch (stud s[10],int size,int key){

	for (int i=0;i<size;i++){
		if (s[i].roll == key){printf("found key at %d\n",i); return;}
		
		
	}
	printf ("not found \n");

}

void binarysearch (stud s[10],int size,int key){
int low = 0;
int high = size-1;
while (low<=high)
	{
int mid = (low+high)/2;
if (s[mid].roll == key)
		{
	printf("found ! at %d \n", mid);
	return;
		}
else if (s[mid].roll >key)
		{
		low = mid+1;
		}
else high = mid-1;



	}
	
printf ("not found \n");


}

void selectionsort(stud s[10],int size){
for (int i = 0;i<size-1;i++){
	int minpos = i;
		for (int j = i+1;j<size;j++)
		{
			if (s[j].roll <s[minpos].roll)
			{
				minpos = j;
			}
		}
		if (minpos !=i)
		{
		stud temp = s[i];
		s[i] = s[minpos];
		s[minpos]= temp;
		
		
		}
		

	}
disp (s,size);

}

void insertionsort(stud s[10],int size){
for (int i = 1;i<size;i++)
	{
		stud key = s[i];
		int j = i-1;
		while (j>=0 && s[j].roll > key.roll)
		{
			s[j+1] = s[j];
			j--;
			
		}
		s[j+1] = key;

	}
disp (s,size);
}

void shellsort(stud s[10],int size){
int swapped = 0;
int gap = size/2;
do 
	{
		do 
		{

			for (int i=0;i<size-gap-1;i++)
			{
				if (s[i].roll >s[i+gap].roll)
				{
					swapped = 1;
					stud temp = s[i];
					s[i] = s[i+gap];
					s[i+gap] = temp;
				}
			
			
			}	
		
		}
		while (swapped==1);
	
	} 
	
	while ((gap = gap/2)>=1);

disp (s,size);

}

void main (){

stud s [10];
int count,key;

printf ("enter student db size\n");
scanf("%d",&count);
printf("enter student data:\n");
for (int i=0;i<count;i++){
	printf("enter student %d data:number, name \n",i);
	scanf("%d",&s[i].roll);
	scanf("%s",s[i].name);
	
	}

printf ("enter roll no to search: \n");
scanf ("%d",&key);
/*
printf("linear search: \n");
linearsearch(s,count,key);

printf("binary search: \n");
binarysearch(s,count,key);
*/
printf("selection sort: \n");
selectionsort(s,count);

printf("insertion sort: \n");
insertionsort(s,count);

printf("shell sort: \n");
shellsort(s,count);

}
