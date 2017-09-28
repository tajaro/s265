/* 
s265fmt.c
Taylor Eby
September 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 100

int main(int argc, char* argv[]) {
	char buffer[BUFLEN];

	if (argc != 2) {
		printf("Input file not specified\n");
		exit(1);
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Input file doesn't exist\n");
		exit(1);
	}

	while (fgets(buffer, sizeof(char)*BUFLEN, fp)) {
		printf("%s", buffer);
	}

	fclose(fp);
	return 0;
}


