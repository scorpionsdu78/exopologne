#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "./t.h"
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
	FILE *fichier = NULL, *fichier2 = NULL;
	char *n1, *n2;
	int caractereActuel = 0, comptage = -1;

	if (argc < 2)
	{
		printf("syntax error: exercice2.exe [file name]\n");
		exit(EXIT_FAILURE);
	} 

	n1 = argv[1];
	n2 = argv[2];
	timestart();
	fichier = fopen(n1, "r");
	fichier2 = fopen(n2, "w");
	if (fichier==NULL || NULL==fichier2)
	{
		printf ("Error in open: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		do

        {

            caractereActuel = fgetc(fichier);

            fputc(caractereActuel,fichier2);
            
            comptage ++;

        } while (caractereActuel != EOF);
        
 		printf("%i\n", comptage);

        fclose(fichier);
        fclose(fichier2);
        exit(EXIT_SUCCESS);
		
	}

	exit(EXIT_SUCCESS);
}
