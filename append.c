#include<stdio.h>

#define SIZE 1000

int main()
{
	FILE *fp;
	char str[SIZE];
	if((fp=fopen("file1.txt","a"))==NULL)
	{
		printf("File is cannot opened Successfully\n");
	}
	else
	{
		printf("Enter a string: ");
		scanf("%[^\n]s",str);
		fprintf(fp,"%s",str);
		printf("Your string is appended to file1.txt file\n");
	}
	fclose(fp);
	return 0;
}
