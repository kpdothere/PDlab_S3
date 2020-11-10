#include <stdio.h>

//function declarations

int partition(int Array[], int p,int q, int r);

void quicksort(int Array[],int p,int r);

void print(int Array[],int size);

static int flag=0; //flag notes the no.of comparisons

void main(){

	int size; //declare size of the array

	scanf("%d",&size); //ask to input size of the array

	int Array[size]; //declare array

	for(int i=0;i<size;i++){

		scanf("%d",&Array[i]); //ask to input each elements of the array
	}

	int q=0;

	quicksort(Array,0,size-1); 

	print(Array,size);

	printf("\n%d",flag);

}

void print(int Array[],int size){ //function to print the sorted array

	for (int i=0;i<size;i++){

		printf("%d ",Array[i]);
	}
}
int partition(int Array[],int p,int q,int r){

	int pivot=Array[r]; //declaring pivot as the last element of the array

	int i=p-1; 

	for(int j=p;j<=r-1;j++){ //traversing through the array

		if(Array[j]<=pivot){ //if element is less than pivot

			flag++;

			//swapping Array[i+1] & Array[j]

			int t=Array[j];

			Array[j]=Array[++i];

			Array[i]=t;
		}

		else

			flag++;
	}

	//swapping Array[r] & Array[i+1]

	int t=Array[r];

	Array[r]=Array[i+1];

	Array[i+1]=t;

	q=i+1;

	return q; //returning the right position of the element whose left elements are less than and right elements are greater than it
}
void quicksort(int Array[],int p,int r){

	if(p<r){


		int q=partition(Array,p,q,r); //calling partition function

		quicksort(Array,p,q-1); //quicksorting the left part of the unsorted array

		quicksort(Array,q+1,r); //quicksorting the right portion of the unsorted array
	}

}