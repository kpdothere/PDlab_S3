#include<stdio.h>
int inv=0; //declaring global variable inv to calculate the no.of inversions
void mergesort(int Array[],int p, int r);
void merge(int Array[], int p, int q, int r);
void main(){
	int n;
	scanf("%d",&n);

	int Array[n]; //declaring array of size n

	for(int i=0;i<n;i++){
		scanf("%d",&Array[i]); //scanning values of the array
	}
	mergesort(Array,0,n-1); //calling mergesort

	for(int i=0;i<n;i++){
		printf("%d ",Array[i]); //printing the sorted array
	}
	printf("\n%d",inv); //printing the no.of inversions
}
void mergesort(int Array[],int p,int r)
{
    if(p<r)
    {
        int q =p+(r-p)/2; //assigning q as the middle element

        mergesort(Array,p,q); //mergesort of left array

        mergesort(Array,q+1,r); //mergesort of right array

        merge(Array,p,q,r); //merging both the arrays
    }
}
void merge(int Array[],int p, int q, int r){

	int n1=q-p+1; //declaring size of left subarray

	int n2=r-q; //declaring size of right subarray

	int L[n1+1],R[n2+1]; //declaring left and right subarrays

	for(int i=0;i<n1;i++)
		L[i]=Array[p+i]; //storing elements of the left subarray

	for(int i=0;i<n2;i++)
		R[i]=Array[q+i+1]; //storing lements of the right subarray

	L[n1]=99999; //assigning sentinel value for last element of left subarray

	R[n2]=99999; //assigning sentinel value for last element of right subarray

	int i=0,j=0;
	for(int k=p;k<=r;k++){
		if(L[i]<=R[j]){ 
			Array[k]=L[i];
			i++;
		}
		else{
			Array[k]=R[j];
			j++;
			inv+=(n1-i); //if L[i]<R[j] since left and right subarrays are already sorted all the elements after L[i] will be greater than R[j] so no of inversions= elements after L[i+1] upto L[q]
		}
	}
}
