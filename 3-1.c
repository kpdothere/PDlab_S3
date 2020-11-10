#include<stdio.h>
int flag=0;
void insertionsort(int array[],int n);
void printarr(int array[],int n);
void main(){
	int n;
	scanf("%d",&n);
	int array[n];
	for(int i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	insertionsort(array,n);
	printarr(array,n);
	printf("\n%d",flag);
}
void insertionsort(int array[], int n) 
{ 
    int i,j,key;
    for (i = 1; i < n; i++) { 
        key = array[i]; 
        j = i - 1; 
        while (j>= 0 && array[j] > key)
        {
        	flag++;
            array[j + 1] = array[j]; 
            j--; 
        }
        if (j>=0)
            flag++;
        array[j + 1] = key; 
    } 
} 
void printarr(int array[], int n) 
{  
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}