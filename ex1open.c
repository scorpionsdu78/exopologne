#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "./t.h"
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
	int f1, c;
	char b[BUFSIZE], *n1;

	c = 10;
	n1 = argv[1];
	timestart();
	f1 = open (n1, O_RDONLY);
	if(f1==-1)
	{
	printf ("Error in open: %s\n",strerror(errno));
	exit(EXIT_FAILURE);
	}
	else
	{
		if(read (f1, b, c)==-1)
		{
			printf ("Error in read: %s\n",strerror(errno));
			close(f1);
			exit(EXIT_FAILURE);	
		}
		else
		{
			printf("%s: Read %d characters from file %s: \"%s\"\n",argv[0], c, n1, b);
			close(f1);
			timestop(argv[0]);
			exit(EXIT_SUCCESS);
		}
	}

	exit(EXIT_SUCCESS);
}
