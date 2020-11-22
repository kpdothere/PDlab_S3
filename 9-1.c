#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *left;
    struct node *right;
    struct node *p;
    int key;
}NODE;
typedef struct top
{
    struct node *root;
}TOP;
NODE* create_node(int k)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->left=NULL;
    temp->right=NULL;
    temp->p=NULL;
    temp->key=k;
    return temp;
}
void insert(TOP *T,NODE *temp)
{
    if(T->root==NULL)
        T->root=temp;
    else
    {
        NODE *x=T->root;
        while(1)
        {
            if(temp->key<x->key)
            {
                if(x->left==NULL)
                    break;
                x=x->left;
            }
                
            else
            {
                if(x->right==NULL)
                    break;
                x=x->right;
            }
                
        } 
        if(temp->key<x->key)
        {
            x->left=temp;
            temp->p=x;
        } 
        else
        {
            x->right=temp;
            temp->p=x;
        }    
    }
    
}
NODE* search(TOP *T,int k)
{
    NODE *x=T->root;
    if(x==NULL)
        return NULL;
    else
    {
        while(1)
        {
            if(k==x->key)
                return x;
            if(k<x->key)
            {
                if(x->left==NULL)
                    return NULL;
                x=x->left;
            }
            else
            {
                if(x->right==NULL)
                    return NULL;
                x=x->right;
            }
                   
        }
    }  
}
void delete(TOP *T,int k) 
{
    void transplant(TOP *T, NODE *u, NODE *v)
    {
        if(u->p==NULL) // root node
            T->root=v;
        else
        {
            if(u==u->p->left)
                u->p->left=v;
            else
                u->p->right=v;
        }
        if(v!=NULL)
            v->p=u->p;  
    }
    NODE *x=search(T,k);
    if(x==NULL)
    {
        printf("-1\n");
    }  
    else
    {
        printf("%d\n",x->key);
        if(x->left==NULL) // no left child
        {
            transplant(T,x,x->right);
            if(x->right!=NULL)
                x->right->p=x->p;
        } 
        else
        {
            if(x->right==NULL) // no right child
            {
                transplant(T,x,x->left);
                if(x->left!=NULL)
                    x->left->p=x->p;
            }  
            else
            {
                NODE *t=x->right;
                while(t->left!=NULL) // t is the successor of x
                {
                    t=t->left;
                }
                if(t->p!=x) // successor is not the right child of x
                {
                    transplant(T,t,t->right);
                    t->right=x->right;
                    t->right->p=t;
                }
                transplant(T,x,t); // also when successor is the right child of x
                t->left=x->left;
                t->left->p=t;
            }
        }
    }
        
}
void preorder(NODE *x)
{
    if(x==NULL)
        return;
    printf("%d ",x->key);
    preorder(x->left);
    preorder(x->right);
}
void inorder(NODE *x)
{
    if(x==NULL)
        return;
    inorder(x->left);
    printf("%d ",x->key);
    inorder(x->right);
}
void postorder(NODE *x)
{
    if(x==NULL)
        return;
    postorder(x->left);
    postorder(x->right);
    printf("%d ",x->key);
}
void main()
{
    TOP *T=(TOP*)malloc(sizeof(TOP));
    T->root=NULL;
    char ch;
    do
    {
        scanf("%c",&ch);
        if(ch=='a')
        {
            int k;
            scanf("%d",&k);
            insert(T,create_node(k));
        }
        if(ch=='d')
        {
            int k;
            scanf("%d",&k);
            delete(T,k);
        }
        if(ch=='s')
        {
            int k;
            scanf("%d",&k);
            if(search(T,k)==NULL)
                printf("-1\n");
            else
                printf("1\n");
        }
        if(ch=='i')
        {
            inorder(T->root);
            printf("\n");
        }
        if(ch=='p')
        {
            preorder(T->root);
            printf("\n");
        }
        if(ch=='t')
        {
            postorder(T->root);
            printf("\n");
        }
    } while (ch!='e');
    
}