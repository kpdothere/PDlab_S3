#include <stdio.h>
long BinSearch(int array[], int elem, long first, long last);
int main(){ long size,m=0,posn=-1;
	int elem;
	scanf("%ld",&size); //asks to input size of the array
	scanf("%ld",&m); //asks to input no of queries
	int array[size]; //array declaration
	for(long i=0; i<size; i++){ //asks to input each elements of the array
		scanf("%d",&array[i]);
	}
	for(long i=0;i<m;i++){ //for reading queries
		scanf("%d",&elem);
		posn=BinSearch(array,elem,0,size-1); //Binary Search
		long j=posn;
		if(posn!=-1){ //first occurence of element in the array
			for(j=posn;j>=0;j--){
				if(array[j]!=elem)
					j++;
					break;
			}
			if(j==-1)
				j++;
			printf("%ld\n",j);
		}
		else
			printf("%ld\n",posn);

	}
	return 0;
}
long BinSearch(int array[],int elem,long first,long last){
	if(first>last)
		return -1;
	long mid=first+(last-1)/2;
	if(elem==array[mid])
		return mid;
	if(elem<array[mid])
		last=mid-1;
	if(elem>array[mid])
		first=mid+1;
	return BinSearch(array,elem,first,last);
}