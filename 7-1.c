#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int *Array;
	int top;
	int size;
};

//function declarations

int stackempty(struct stack* S);
int stackfull(struct stack* S);
void push(struct stack* S,int k);
void pop(struct stack* S);

void main()
{
	struct stack* S;
	S=(struct stack*)malloc(sizeof(struct stack)); //dynamic memmory allocation
	S->top=-1;
	scanf("%d",&S->size);
	S->Array=(int*)malloc(sizeof(int)*(S->size));
	char c;
	scanf("%c",&c);
	while(c!='t')
	{
		if(c=='i') //insert
		{
			int k;
			scanf("%d",&k);
			push(S,k);
		}

		if(c=='d') //delete
		{
			pop(S);
		}
		if(c=='e') //check if empty
		{
			printf("%d\n",stackempty(S));
		}
		if(c=='p') //printing
		{
			for(long int i=0;i<=S->top;i++)
			{
				printf("%ld ",S->Array[i]);
			}
			printf("\n");
		}
		if(c=='f') //if full
		{
			printf("%d\n",stackfull(S));
		}
		scanf("%c",&c);

	}
}
int stackempty(struct stack* S)
{
	if(S->top<0)
		return -1;
	return 1;
}
int stackfull(struct stack* S)
{
	if(S->top>=(S->size-1))
		return -1;
	return 1;
}
void push(struct stack* S,int k)
{
	
	if(stackfull(S)==1)
	{
		S->top+=1;
		S->Array[S->top]=k;
	}
	else
		printf("-1\n");
}
void pop(struct stack* S)
{
	if(stackempty(S)==1)
	{
		printf("%d\n",S->Array[S->top]);
		S->top-=1;
	}
	else
		printf("-1\n");
}
