#include<stdio.h>
struct complexnumber{
	float real;
	float imag;
};
typedef struct complexnumber complex;
complex sum(complex a,complex b){
	complex c;
	c.real=a.real+b.real;
	c.imag=a.imag+b.imag;
	return c;
}
main(){
	complex c1,c2;
	printf("Enter Complex Number-1:\n");
	printf("Enter real and imag part:");
	scanf("%f%f",&c1.real,&c1.imag);
	printf("Enter Complex Number-2:\n");
	printf("Enter real and imag part:");
	scanf("%f%f",&c2.real,&c2.imag);
	complex c=sum(c1,c2);
	printf("Resultant Complex Number:\n");
	printf("%.2f+i(%.2f)",c.real,c.imag);
}
