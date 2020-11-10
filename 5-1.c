#include<stdio.h>
#include<stdlib.h>
struct heap{ // defining a structure of heap datatype
	
		int *Array;
		int size;
		int count;
};
void maxheapify(struct heap *h,int i){

	int largest = i; // Initialize largest as root 

    int l = 2*i + 1; // left  = 2*index of root +1

    int r = 2*i + 2; // right = 2*index of root +2
  
    // If left child is larger than root 

    if (l < h->size){
    	h->count++;
    	if (h->Array[l] > h->Array[largest])
        	largest = l; 

  	}

    // If right child is larger than largest so far 

    if (r < h->size){
    	h->count++;
    	if(h->Array[r] > h->Array[largest])
        	largest = r; 
  	
  	}

    // If largest is not root 

    if (largest !=i) 
    {   
    	//swapping root and largest so far

    	int t=h->Array[largest];
		h->Array[largest]=h->Array[i];
		h->Array[i]=t;

        // Recursively heapify the affected sub-tree

        maxheapify(h,largest); 
    } 
}
void buildmaxheap(struct heap *h){

	// travesing through all the parent nodes till root

	int i=(h->size/2)-1;
	while(i>=0){
		maxheapify(h,i);
		i--;

	}
}
void heapsort(struct heap *h){

	// buiding max heap

	buildmaxheap(h);

	//swapping root element to the end of the array in each iteration

	for(int i=h->size-1;i>0;i--){

		int t=h->Array[i];
		h->Array[i]=h->Array[0];
		h->Array[0]=t;

		// reducing the size of array by 1 in each iteration

		h->size-=1;

		//max heapifying the swapped array

		maxheapify(h,0);
	}
}
void main(){

	struct heap h; //declaring structure of datatype heap and name h

	//reading the size of the array

	int n;
	scanf("%d",&n);

	h.size=n;

	h.Array=(int*)malloc(n*sizeof(int)); //dynamically allocating the size of the array

	//reading the unsorted array

	int k=0;
	while(k<n){
		scanf("%d",&h.Array[k]);
		k++;
	}

	h.count=0; //element for counting no.of comparisons

	heapsort(&h); //heapsorting the array

	//printing the sorted array

	k=0;
	while(k<n){
		printf("%d ",h.Array[k]);
		k++;
	}

	// printing the no.of comparisons performed

	printf("\n%d",h.count);
}