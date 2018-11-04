#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "./t.h"
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
	FILE *fichier = NULL;
	char *n1;
	int caractereActuel = 0, comptage = -1;

	if (argc < 2)
	{
		printf("syntax error: exercice2.exe [file name]\n");
		exit(EXIT_FAILURE);
	} 

	n1 = argv[1];
	timestart();
	fichier = fopen(n1, "r");
	if (fichier==NULL)
	{
		printf ("Error in open: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		do

        {

            caractereActuel = fgetc(fichier);
            
            comptage ++;

        } while (caractereActuel != EOF);
        
 		printf("%i\n", comptage);

        fclose(fichier);
        exit(EXIT_SUCCESS);
		
	}

	exit(EXIT_SUCCESS);
}
