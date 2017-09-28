/* 
s265fmt.c
Taylor Eby
September 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if( argc != 2 ) {
		printf("Input file not specified\n");
		exit(1);
	}

	FILE *fp = fopen(argv[1], "r");
	if( fp == NULL ) {
		printf("Input file doesn't exist\n");
		exit(1);
	}

	fclose(fp);

	printf("Hello World\n");
	return 0;
}


