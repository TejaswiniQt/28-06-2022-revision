#include<stdio.h>

int main()
{
	FILE *fp1,*fp2;
	char ch1,ch2;
	if((fp1=fopen("file1.txt","r"))==NULL)
	{
		printf("file is not opened successfully\n");
	}
	else if((fp2=fopen("file3.txt","r"))==NULL)
	{
		printf("file is not opened successfully\n");
	}
	else
	{
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
	}
	
	while((ch1!=EOF) && (ch2!=EOF) && (ch1==ch2))
	{
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
	}
	
	if(ch1==ch2)
	{
		printf("file1 and file2 are both same\n");
	}
	else if(ch1!=ch2)
	{
		printf("file1 and file2 are not same\n");
	}
	return 0;
}
