#include <string.h>
#include <stdio.h>

main(int argc , char *argv[])
{
	void count(FILE *);
	FILE *fp;

	fp=fopen(argv[1],"r");
	if(argc == 1)
	{
		count(stdin);
		
	}
	if(fp==NULL)
	{
		printf("No File Was Inputed or No Permission Allowed\n");
		return(0);
	}
	else
	{
		count(fp);
	}
	printf("%s \n", argv[1]);
	return(0);
}
void count(FILE *fp)
{
	int ch;
	int character=0,totalChar=0;
	int newLine=0;
	int word=0,totalWord=0;
	int i=0;

	while((ch=fgetc(fp))!=EOF)
	{
		if(ch == ' ')
		{
			if(i>0)
			{
				word++;
			}
			i=0;
		}
		if (ch == '\n')
		{
			newLine++;
			if(i>0)
			{
				word++;
			}
			i=0;
		}
		if(ch != '\n' && ch != ' ')
		{
			i++;
		}
		character++;
	}
	if(i>0)
	{
		word++;
	}
	totalChar += character;
	totalWord += word;
	
	printf(" %d %d %d ", newLine, totalWord, totalChar);
	fclose(fp);

}
