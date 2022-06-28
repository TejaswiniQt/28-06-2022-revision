#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	int character=0,word=0,lines=0;
	if((fp=fopen("file1.txt","r"))==NULL)
	{
		printf("File is cannot opened Successfully\n");
		exit(1);
	}
	else
	{
		printf("File opened successfully\n");
		while((ch=fgetc(fp))!=EOF)
		{
			character++;
			if(ch=='\n' || ch=='\0')
				lines++;
			if(ch=='\n' || ch=='\0'||ch==' ' || ch=='\t')
				word++;
		}
	}
	printf("Count no of charcters in a file: %d\n",character);
	printf("Count no of word in a file: %d\n",word);
	printf("Count no of lines in a file: %d\n",lines);
	fclose(fp);
	return 0;
}
