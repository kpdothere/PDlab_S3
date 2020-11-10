#include<stdio.h>
#include<stdlib.h>
struct stack
{
	long int data;
	struct stack *next;
};
struct node
{
	struct stack *top;
};

struct stack* create_node(long int k);
void push(struct node* S,struct stack *temp);
int stack_empty(struct node* S);
void pop(struct node* S);

void main()
{
	struct node *S;
	S->top=NULL;

	char c;
	scanf("%c",&c);
	while(c!='t')
	{
		if(c=='i') //insert
		{
			long int k;
			scanf("%ld",&k);
			push(S,create_node(k));
		}
 
		if(c=='d') //delete
		{
			pop(S);
		}
		if(c=='e') //check if empty
		{
			printf("%d\n",stack_empty(S));
		}
		if(c=='p') //printing
		{
			struct stack *x;
			for(x=S->top;x!=NULL;x=x->next)
			{
				printf("%ld ",x->data);
			}
			printf("\n");
		}
		scanf("%c",&c);
	}	
}
struct stack* create_node(long int k)
{
	struct stack *temp;
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=k;
	temp->next=NULL;
	return temp;
}
void push(struct node* S,struct stack* temp)
{
	temp->next=S->top;
	S->top=temp;
}
int stack_empty(struct node* S)
{
	if(S->top==NULL)
		return -1;
	return 1;
}
void pop(struct node* S)
{
	if(stack_empty(S)==-1)
		printf("-1\n");
	else
	{
		printf("%ld\n",S->top->data);
		S->top=S->top->next;
	}
}