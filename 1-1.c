#include<stdio.h>
#include<stdlib.h>
int main(){
	int size, *array, elem, j, flag; //variable and array declarations

	scanf("%d",&size); //assigns the size of the array

	array=(int*)malloc(size*sizeof(int)); //dynamically allocates the size of the array

	for(j=0;j<size;j++)
		scanf("%d",&array[j]); //inputs values to the array

	scanf("%d",&elem); //inputs value to be searched

	for(j=0;j<size;j++){ //checks if elements to be searched is in the array
		if(array[j]==elem){
			printf("%d",j); //if found prints the position of that element
			flag=0;
		}

	}
	if(flag) //if element to be searched is not found in the array prints -1
		printf("%d",-1);
	return 0;


}