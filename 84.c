#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int evaluate_postfix(char *ch)
{
    int A[10000]; //stack
    int top=-1;
    int i,j,k=0;
    while(k<strlen(ch)) //k is to traverse elements one by one
    {
        if(ch[k]>='0' && ch[k]<='9') //if starting character is digit
        {
            int num=0;
            for(i=k,j=0;ch[i]!=' ';i++,j++)
            {
                num=num*10 + (int)(ch[i]-'0'); //typecast char to int
            }
            A[++top]=num; //if number add to stack
            k=++i; //skip whitespace
        }
        else //if operator, pop the last 2 elements from stack and do operation
        {
            int t1,t2;
            t1=A[top--];
            t2=A[top--];
            switch(ch[k])
            {
                case '+':
                    A[++top]=t2+t1; //after operation add on top of stack
                    break;
                case '-':
                    A[++top]=t2-t1;
                    break;
                case '*':
                    A[++top]=t2*t1;
                    break;
                case '/':
                    A[++top]=t2/t1;
                    break;
            }
            k+=2; //skip whitespace
        }
    }
    return A[top];
}
void main()
{
    FILE *inp,*outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");
    char ch[10000]; 
    while(fgets(ch,10000,inp)!=NULL)
    {
        fscanf(file,"%[^\n]%*c",ch); //read until a newline is encountered
        fprintf(outp,"%d\n",evaluate_postfix(ch));
    }
    fclose(inp);
    fclose(outp);
}