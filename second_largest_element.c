/************Program to find second largest element in the array,use macro and function pointer*****************************/

#include <stdio.h>
#define largest(max1,max2) ((max1<max2)?max1:max2)

int largest_num(int *a,int n);

int main()
{
	int a[50];
	int n,i;
	printf("Enter array size: ");
	scanf("%d",&n);
	printf("Enter elements of array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int (*ptr)(int *,int)=largest_num;
	int res=(*ptr)(a,n);
	printf("Second largest=%d\n",res);

	return 0;
}


int largest_num(int *a,int n)
{
	int max1,max2,i;
	max1=max2=0;

	for(i=0;i<n;i++)
	{
		if(a[i]>max1)
		{
			max2=max1;
			max1=a[i];
		}
		else if(a[i]>max2 &&a[i]<max1)
		{
			max2=a[i];
		}
	}
	int res=largest(max1,max2);
	return res;
}


