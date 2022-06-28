/***********************Simple example for array of function pointer***********************/

#include <stdio.h>
void add(int a, int b)
{
	printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
	printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
	printf("Multiplication is %d\n", a*b);
}

int main()
{
	void (*ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch, a, b ;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);

	printf("Enter Choice:\n");
	printf("1.add\n2.subtract\n3.multiply\n");
	scanf("%d", &ch);

	if(ch > 0 && ch <= 3) 
	{
		(*ptr_arr[ch-1])(a, b);
	}
	else
	{
		printf("Invalid option\n");
	}

	return 0;
}
