#include<stdio.h>
#include<conio.h>
void swap(int *a, int*b);

void swap(int *a, int *b)
{
	int y;
	y=*a;
	*a=*b;
	*b=y;
}

void main()
{
	int c,d;
	clrscr();
	printf("Enter two numbers: ");
	scanf("%d %d" ,&c ,&d);
	swap(&c, &d);
	printf("After swapping the numbers are %d and %d" ,c,d);
	getch();
}