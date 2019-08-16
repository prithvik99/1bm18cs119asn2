#include<stdio.h>
#include<conio.h>
void swap(int *x, int*y);

void swap(int *x, int *y)
{
	int p;
	p=*x;
	*x=*y;
	*y=p;
}

void main()
{
	int c,d;
	clrscr();
	printf("Enter two integers: ");
	scanf("%d %d" ,&c ,&d);
	swap(&c, &d);
	printf("After swapping the integers are %d and %d" ,c,d);
	getch();
}
