#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* infix_to_postfix(char ch[]);
void main()
{
    char str[10000]; 
    scanf("%s",str);
    printf("%s",infix_to_postfix(str));
}
char* infix_to_postfix(char ch[])
{
    char A[10000]; //stack
    int k=-1,top=-1;
    int prec(char c) //precedence of character
    {
        if(c=='+' || c=='-')
            return 1;
        if(c=='*' || c=='/')
            return 2;
        if(c=='^')
            return 3;
        return -1; //assume "(" has least precedence
    }
    for(int i=0;i<strlen(ch);i++) //traversing characters one by one
    {
        if(ch[i]>='a' && ch[i]<='z' || ch[i]>='A' && ch[i]<='Z') //if operand
        {
            ch[++k]=ch[i];
        }
        else
        {
            if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]=='/') //if operator
            {
                while(top>=0 && prec(ch[i])<=prec(A[top])) //precedence checking - if character has lesser presedence than top, pop top
                {
                    ch[++k]=A[top--]; //store top to string and pop 
                }
                A[++top]=ch[i];
            }
            if(ch[i]=='(')
                A[++top]=ch[i];
            if(ch[i]==')') //if paranthesis close
            {
                while(top>=0 && A[top]!='(') //reach until last paranthesis open
                {
                    ch[++k]=A[top--];
                }
                // after for loop A[top] is ')'
                top--;

            }
        }
    }
    while(top>=0)
    {
        ch[++k]=A[top--];
    }
    ch[++k]='\0';
    return ch;
}