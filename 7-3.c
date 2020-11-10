#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int *Array;
	int head;
	int tail;
	int n;
};

int queue_empty(struct queue *Q);
int queue_full(struct queue *Q);
void enqueue(struct queue *Q,int k);
void dequeue(struct queue *Q);



void main()
{
	struct queue *Q;
	Q=(struct queue*)malloc(sizeof(struct queue));

	scanf("%d",&Q->n);
	Q->Array=(int*)malloc(sizeof(int)*Q->n);

	Q->head=-1;
	Q->tail=0;

	char c;
	scanf("%c",&c);
	while(c!='t')
	{
		if(c=='i') //insert
		{
			int k;
			scanf("%d",&k);
			enqueue(Q,k);
		}
 
		if(c=='d') //delete
		{
			dequeue(Q);
		}
		if(c=='f') //check if full
		{
			printf("%d\n",queue_full(Q));
		}
		if(c=='e') //check if empty
		{
			printf("%d\n",queue_empty(Q));
		}
		// if(c=='p') //printing
		// {
		// 	if(Q->head!=-1) //not empty
		// 	{
		// 		if(Q->head==Q->tail) // if full
		// 		{
		// 			for(int x=Q->head,i=0;i<Q->n;x=(x+1)%Q->n,i++)
		// 				printf("%d ",Q->Array[x]);

		// 		}
		// 		else
		// 		{
		// 			for(int x=Q->head;x!=Q->tail;x=(x+1)%Q->n)
		// 				printf("%d ",Q->Array[x]);
		// 		}
		// 	}
		// 	printf("\n");
		// }	
		scanf("%c",&c);
	}	
}
int queue_full(struct queue *Q)
{
	if(Q->head==Q->tail || !Q->n) //if size is zero
		return -1;
	return 1;
}
int queue_empty(struct queue *Q)
{
	if(Q->head==-1)
		return -1;
	return 1;
}
void enqueue(struct queue *Q,int k)
{
	if(queue_full(Q)==-1) // if full
		printf("-1\n");
	else
	{
		if(Q->head==-1) // if empty
		{
			Q->head=0;
			Q->Array[Q->tail]=k;
			Q->tail=(Q->tail+1)%Q->n;
		}
		else
		{
			Q->Array[Q->tail]=k;
			Q->tail=(Q->tail+1)%(Q->n);
		}
	}
}
void dequeue(struct queue *Q)
{
	if(queue_empty(Q)==-1) //if empty
		printf("-1\n");
	else
	{
		if(((Q->head+1)%Q->n)==Q->tail) //only one element
		{
			printf("%d\n",Q->Array[Q->head]);
			Q->head=-1;Q->tail=0;
		} 
		else
		{
			printf("%d\n",Q->Array[Q->head]);
			Q->head=(Q->head+1)%(Q->n);
		}

	}
}