#include <stdio.h>
int fact(int n);
int main(){
	int numb;
	scanf("%d",&numb);
	printf("%d",fact(numb));
}
int fact(int n){
	if (n>0)
		return n*fact(n-1);
	else
		return 1;
}