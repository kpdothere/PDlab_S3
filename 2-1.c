#include <stdio.h>
#include <stdlib.h>
int gcd(int n1, int n2);
int main(){
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	if(n1==0 && n2==0)
		printf("%d", -1);
	else
		printf("%d", gcd(n1, n2));
}
int gcd(int n1, int n2){
	if (n2!=0)
		return gcd(n2, n1%n2);
	else
		return n1;

}