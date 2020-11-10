#include<stdio.h>
#include<stdlib.h>
struct heap
{
    int *Array;
    int size;
    int flag;
};
void min_heapify(struct heap *pq,int i)
{

    int l=2*i+1;
    int r=2*i+2;
    int min=i;

    if (l< pq->size && pq->Array[l]< pq->Array[i])
        min=l;
    if (r< pq->size && pq->Array[r]<pq->Array[min])
        min=r;

    if(min!=i)
    {

        // swap

        int t=pq->Array[i];
        pq->Array[i]=pq->Array[min];
        pq->Array[min]=t;
        min_heapify(pq,min);
    }

}
int heap_extract_min(struct heap *pq)
{

    if(pq->size<1)
        return -1;
    else
    {

        int min=pq->Array[0];
        pq->Array[0]=pq->Array[pq->size-1];

        pq->size-=1;

        min_heapify(pq,0);
        return(min);

    }
}
int heap_min(struct heap *pq)
{
    if(pq->size>0)
        return pq->Array[0];
    else
        return (-1);
}
void heap_decrease_key(struct heap *pq,int i,int k)
{
    pq->Array[i]=k;
    while(i>=0 && pq->Array[(i-1)/2]>pq->Array[i])
    {
        int t=pq->Array[i];
        pq->Array[i]=pq->Array[(i-1)/2];
        pq->Array[(i-1)/2]=t;
        i=(i-1)/2;
    }
}
void min_heap_insert(struct heap *pq,int k)
{
    pq->size+=1;
    heap_decrease_key(pq,pq->size-1,k);
}

void main()
{
    char a;
    int i,k;
    struct heap *pq;
    pq=(struct heap*)malloc(sizeof(struct heap));
    pq->Array=(int*)malloc((1000000)*sizeof(int));
    pq->size=0;
    scanf("%c",&a);
    while(a!='s')
    {
        if(a=='i')
        {
            scanf("%d",&k);
            min_heap_insert(pq,k);

        }
        if(a=='e')
            printf("%d",heap_extract_min(pq));
        if(a=='m')
            printf("%d",heap_min(pq));
        if(a=='d')
        {
            scanf("%d %d",&i,&k);
            heap_decrease_key(pq,i,k);
        }
        if(a=='j')
        {
            printf("%d\n",pq->size);
            for(int l=0; l<pq->size; l++)
                printf("%d ",pq->Array[l]);
        }

        scanf("%c",&a);
    }
}