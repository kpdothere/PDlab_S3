#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char c;
    struct node *left;
    struct node *right;
}NODE;

NODE* construct_tree(char *s);
void inorder(NODE *x);
void preorder(NODE *x);
void postorder(NODE *x);
void main()
{
    NODE *T=(NODE*)malloc(sizeof(NODE));
    char str[10000];
    char ch;
    do
    {
        scanf("%c",&ch);
        if(ch=='e')
        {
            scanf("%s",str);  
            T=construct_tree(str);
        }
        if(ch=='i')
        {
            inorder(T);
            printf("\n");
        }
        if(ch=='p')
        {
            preorder(T);
            printf("\n");
        }
        if(ch=='s')
        {
            postorder(T);
            printf("\n");
        }
    }
    while(ch!='t');
}

NODE* construct_tree(char *s)
{

    NODE *Array[10000]; //stack of array of pointer to NODE
    int top=-1;
    NODE* create_node(char a)
    {
        NODE *temp=malloc(sizeof(NODE));
        temp->c=a;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }

    for(int i=0;i<strlen(s);i++) //do per each character of string 
    {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
        {
            Array[++top]=create_node(s[i]);
        }
        else
        {
            NODE *t1=Array[top-- ];
            NODE *t2=Array[top--];
            NODE *x=create_node(s[i]);
            x->left=t2;
            x->right=t1;
            Array[++top]=x;
            // free(t1);
            // free(t2);      
        }   
    }
    return Array[top];
}
void inorder(NODE *x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        printf("%c",x->c);
        inorder(x->right);
    }
    
}
void preorder(NODE *x)
{
    if(x!=NULL)
    {
        printf("%c",x->c);
        preorder(x->left);
        preorder(x->right);
    }  
    
}
void postorder(NODE *x)
{
    if(x!=NULL)
    {
        postorder(x->left);
        postorder(x->right);
        printf("%c",x->c);
    } 
    
}