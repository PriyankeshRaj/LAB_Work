#include<stdio.h>
struct salary{
int bs;
int hra;
};
typedef struct employee
{
char name[25];
int age;
struct salary gross_salary;
}employee;

int main()
{
employee emp1;
printf("Enter the Name: ");
scanf("%[^\n]%*c",emp1.name);
printf("Enter the age: ");
scanf("%d",&emp1.age);
printf("Enter the Basic Salary: ");
scanf("%d",&emp1.gross_salary.bs);
printf("Enter the H.R.A: ");
scanf("%d",&emp1.gross_salary.hra);
printf("\nName of the employee: %s",emp1.name);
printf("\nAge of the employee: %d",emp1.age);
printf("\nGross Salary of the employee: %d",emp1.gross_salary.bs+emp1.gross_salary.hra);
return 0;
}
