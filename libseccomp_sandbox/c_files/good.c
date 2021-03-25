#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	FILE *fp;
	char buff[256];

	fp = fopen("/home/shirbu/Documents/empty.txt", "w");
	fputs("not empty anymore...", fp);
	fclose(fp);

	system("touch newnew.txt");
	fp = fopen("/home/shirbu/Documents/newnew.txt", "w");
	fputs("some text in newnew", fp);
	fclose(fp);

	fp = fopen("/home/shirbu/Documents/newnew.txt", "r");
	fgets(buff, 255, (FILE*)fp);
	fclose(fp);	
	
	system("touch newnew1.txt");
	system("rm newnew1.txt");

	printf("good\n");

	return 0;
}
