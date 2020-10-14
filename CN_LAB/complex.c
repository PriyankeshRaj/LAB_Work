#include<stdio.h>
struct complex{
int real,imag;
};

int main()
{
struct complex a,b,c;
printf("Enter the real and imaginary part of first number: ");
scanf("%d %d",&a.real,&a.imag);
printf("Enter the real and imaginary part of second number: ");
scanf("%d %d",&b.real,&b.imag);

c.real=a.real+b.real;
c.imag=a.imag+b.imag;

printf("Sum of the two complex numbers is: %d+%di",c.real,c.imag);
return 0;
}
