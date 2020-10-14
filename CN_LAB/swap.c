#include<stdio.h>
void swap(int *a,int *b)
{
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}
int main()
{
int a,b;
printf("\nEnter the two Numbers: ");
scanf("%d %d",&a,&b);
printf("\nBefore Swap:Value of a & b: %d,%d",a,b);
swap(&a,&b);
printf("\nAfter Swap:Value of a & b: %d,%d",a,b);
}
