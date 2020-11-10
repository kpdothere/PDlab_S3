#include <stdio.h>
#include<string.h>
struct employee
{
	char name[20];
	int salary;
	int hrs;
	int cl;
	int lop;
};
void work(struct employee emp[], int n,int h){
	for(int j=0;j<n;j++){
		if (emp[j].hrs==h){
			printf("%s ",emp[j].name);
			printf("%d ",emp[j].salary);
			printf("\n");
		}
	}
}
void print_finalsalary(struct employee emp[],int n){
	for(int k=0;k<n;k++){
		printf("%s ",emp[k].name);
		printf("%d ",emp[k].salary);
		printf("\n");
	}
}
void print_nonincrement(struct employee emp[],int n){
	for(int j=0;j<n;j++){
		if(emp[j].hrs>10 ||(emp[j].hrs!=8 && emp[j].hrs!=10)){
			printf("%s ",emp[j].name);
			printf("%d ",emp[j].salary);
			printf("%d",emp[j].hrs);
		}
	}
}
void insert(struct employee emp[],int n){
	scanf("%s",emp[n].name);
	scanf("%d",&emp[n].salary);
	scanf("%d",&emp[n].hrs);
	scanf("%d",&emp[n].lop); //asks to input the lop already taken by the employee
	scanf("%d",&emp[n].cl);  //asks to input the total casual leaves taken by the employee
	if(emp[n].hrs==8)
		emp[n].salary+=50;
	if (emp[n].hrs==10)
		emp[n].salary+=100;
	if (emp[n].hrs>10)
		emp[n].salary+=150;
}
int COMPUTEDEDUCTIONS(struct employee emp[],char ename[],int n){ //function to compute and return the deductions in salary due to employee's leave
	int ded=0,total_deduction;
	for(int i=0;i<n;i++){
		if(strcmp(emp[i].name,ename)==0){
			if(emp[i].cl>5)
				ded=(emp[i].lop+emp[i].cl-5);
			else
				ded=emp[i].lop;
		}	
		total_deduction=ded*1000;
	}
	return total_deduction;
}
void main(){
	char c;
	char ename[20];
	struct employee emp[10];
	int n=0,h;
	scanf("%c",&c);
	while(c!='t'){
		if(c=='r'){
			insert(emp,n);
			n++;
		}
		if(c=='i'){
			print_nonincrement(emp,n);
		}
		if (c=='f'){
			print_finalsalary(emp,n);
		}
		if(c=='w'){
			scanf("%d",&h);
			work(emp,n,h);
		}
		if(c=='d'){ //for character d it will print the deduction in salary for the employee
			scanf("%s",ename);
			printf("%d",COMPUTEDEDUCTIONS(emp,ename,n));
		}	
		scanf("%c",&c);
	}

}