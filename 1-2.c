#include<stdio.h>
#include<stdlib.h>
int main(){
	int *array, temp, size,flag; //variables and array declaration

	scanf("%d",&size); //asks to input the size of the array

	array=(int*)malloc(size*sizeof(int)); //dynamically allocates the size of the array

	for(int i=0;i<size;i++) 
		scanf("%d",&array[i]); //asks to input the elements of the array
	for(int i=0;i<size-1;i++){
		flag=1;
		for(int j=0;j<size-1-i;j++){
			if(array[j]>array[j+1]){ //bubblesort algorithm for 2 adjacent elements if first element is larger their values are swapped
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
			flag=0; //flag's value will only be set to zero if atleast one swapping occurs
		}
		if (flag) //if flag is nonzero the loop breaks as the array is already sorted and no more swapping is requuired
			break;
	}
	for(int i=0;i<size;i++)
		printf("%d ",array[i]); //printing the sorted elements of the array
	return 0;

}