#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *head;
	struct node *tail;
};
struct node* create_node(int k);
int queue_empty(struct queue* Q);
void enqueue(struct queue* Q,struct node* temp);
void dequeue(struct queue* Q);


void main()
{
	struct queue *Q;
	Q->head=NULL;
	Q->tail=NULL;

	char c;
	scanf("%c",&c);
	while(c!='t')
	{
		if(c=='i') //insert
		{
			int k;
			scanf("%d",&k);
			enqueue(Q,create_node(k));
		}
 
		if(c=='d') //delete
		{
			dequeue(Q);
		}
		if(c=='e') //check if empty
		{
			printf("%d\n",queue_empty(Q));
		}
		if(c=='p') //printing
		{
			struct node *x;
			for(x=Q->head;x!=NULL;x=x->next)
			{
				printf("%d ",x->data);
			}
			printf("\n");
		}
		scanf("%c",&c);
	}	
}
struct node* create_node(int k)
{
	struct node *temp;  
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=k;
	temp->next=NULL;
	return temp;
}
int queue_empty(struct queue* Q)
{
	if(Q->head==NULL && Q->tail==NULL)
		return -1;
	return 1;
}
void enqueue(struct queue* Q,struct node* temp)
{
	if(Q->head==NULL && Q->tail==NULL)
	{
		Q->head=temp;
		Q->tail=temp;
	}
	else
	{
		Q->tail->next=temp;
		Q->tail=temp;
	}
}
void dequeue(struct queue* Q)
{
	if(queue_empty(Q)==-1)
		printf("-1\n");
	else
	{
		if(Q->head==Q->tail)
		{
			printf("%d\n",Q->head->data);
			Q->head=NULL;
			Q->tail=NULL;
		}
		else
		{
			printf("%d\n",Q->head->data);
			Q->head=Q->head->next;
		}
	}
		
}