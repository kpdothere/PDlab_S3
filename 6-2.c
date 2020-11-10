#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
	int key;
	struct node *next;
};
struct linked_list
{
	struct node *head;
};
//function declarations
struct node* create_node(int k);
struct node* list_search(struct linked_list *L,int k);
void list_insert_front(struct linked_list *L, struct node* x);
void list_insert_tail(struct linked_list *L, struct node* x);
void list_insert_after(struct linked_list *L,struct node* x, struct node* y);
void list_insert_before(struct linked_list *L, struct node* x, struct node* y);
void list_delete(struct linked_list *L,struct node* x);
void list_delete_first(struct linked_list *L);
void list_delete_last(struct linked_list *L);


void main()
{

    char ch;
    int k,a,b;
    struct linked_list L;
    L.head=NULL;
    scanf("%c",&ch);
    while(ch!='e')
    {
        if(ch=='f') //add new node with key = k at front
        {
            scanf(" %d",&k);
            list_insert_front(&L,create_node(k));

        }
        if(ch=='t') //add new node with key = k at tail
        {
            scanf(" %d",&k);
            list_insert_tail(&L,create_node(k));
        }
        if(ch=='a') //insert key =a after key =b
        {
        	scanf("%d %d",&a,&b);
            struct node* temp;
            temp=list_search(&L,b);
            if(temp==NULL) //if node with key=b is not found
                printf("-1\n"); 
        	else
                list_insert_after(&L,create_node(a),temp);
        }

        if(ch=='b') //insert key =a before key =b
        {
        	scanf("%d %d",&a,&b);
            struct node* temp;
            temp=list_search(&L,b);
            if(temp==NULL) //if node with key=b is not found
                printf("-1\n");
            else 
        	   list_insert_before(&L,create_node(a),list_search(&L,b));
        }

        if(ch=='d') //delete node with key = k
        {
        	scanf(" %d",&k);
            struct node* temp;
            temp=list_search(&L,k);
            if(temp==NULL) //if element is not found
            {
                printf("-1\n");
            }
            else
            {
                list_delete(&L,temp);
                printf("%d\n",k);
            }
        }

        if(ch=='i') //delete first node
        {
            if(L.head==NULL)
                printf("-1\n"); //if list is empty
        	else
            {
                int first;
        	   first=L.head->key;
        	   list_delete_first(&L);
        	   printf("%d\n",first);
            }
        }

        if(ch=='l') //delete last node
        {
            if(L.head==NULL) //if list is empty
                printf("-1\n");
            else
            {
        	   struct node *temp;
        	   temp=L.head;
        	   while(temp->next!=NULL) //until last node
               {

				    temp=temp->next;
                }
        	   list_delete_last(&L);
        	   printf("%d\n",temp->key);
            }   
        }
        if(ch=='s') //search for element with key = k in the list
        {
        	scanf(" %d",&k);
        	if(list_search(&L,k)==NULL) //if not found
                printf("%d\n",-1);
            else
                printf("%d\n",1); // if found

        }
        if(ch=='p') //printing nodes
        {
        	struct node* temp;
			temp=L.head;
			// prev-node : until next of node is the one with data as k ie, we get previous node of node with data as k
			while(temp!=NULL)
			{
				printf("%d ",temp->key);
				temp=temp->next;
			}
            printf("\n");
        }
        


        scanf("%c",&ch);

    }
}
struct node* create_node(int k)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->key=k;
	new->next=NULL;
    new->prev=NULL;
	return new;
}
void list_insert_front(struct linked_list *L, struct node* x)
{
    
    
    x->next=L->head;
    L->head=x;
    
	
}
void list_insert_tail(struct linked_list *L, struct node* x)
{
    if(L->head==NULL)
        L->head=x;
	else
    {
       struct node* temp;
	   temp=L->head;
	   while((temp->next)!=NULL)
	   {
		  temp=temp->next;
	   }
	   temp->next=x;
       x->prev=temp;
    }
}
struct node* list_search(struct linked_list *L,int k)
{
	struct node* temp;
	temp=L->head;
	// until node is the last node or node is the one with data as k
	while(temp!=NULL && temp->key!=k)
	{
            temp=temp->next;
	}
	return temp;
}
void list_insert_after(struct linked_list *L,struct node* x, struct node* y)
{
	x->next=y->next;
    x->prev=y;
	y->next=x;
}
void list_insert_before(struct linked_list *L, struct node* x, struct node* y)
{
	struct node* temp;
	temp=L->head;
	// until next of node is the one with data as k ie, we get previous node of node with data as k
	while(temp->key!=y->key)
	{
		temp=temp->next;
	}
	x->next=temp;
    temp->prev->next=x;
    x->prev=temp->prev;
    temp->prev=x;
	
}
void list_delete(struct linked_list *L,struct node* x)
{
	
    if(x==L->head) //if element is first node
    {
        if(x->next==NULL) //single node
            L->head=NULL;
        else
        {
            L->head=x->next;
            x->next->prev=NULL;
        }
    }
    else
    {
            if(x->next==NULL) //last node
            { 
                x->prev->next=NULL;
            }
            else
            {
                struct node *temp;
                temp=x;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
    }
}
void list_delete_first(struct linked_list *L)
{
	L->head=L->head->next;
}
void list_delete_last(struct linked_list *L)
{
    if(L->head->next==NULL) //if only one node is there
    {
        L->head=NULL;
    }
    else
    {
	   struct node* temp;
	   temp=L->head;
	   while(temp->next!=NULL) //temp - 2nd last node
	   {
		  temp=temp->next;
	   }
	   temp->prev->next=NULL;
    } 
}
