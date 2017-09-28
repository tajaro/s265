/* 
s265fmt.c
Taylor Eby
September 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 100

/*
This struct records current options.
-1 indicates no option is selected 
*/
typedef struct fmt_options {
	/* -1 indicates feature is off */
	int pgwdth;
	/* Default is 0 */
	int mrgn;
	/* "on" == 0
	   "off == -1 */
	int fmt;
} fmt_options;

int main(int argc, char* argv[]) {
	char buffer[BUFLEN];
	char *p = buffer;
	fmt_options options = {-1, 0, -1};

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
		/* May not cover cases of ?fmt embedded in text */
		if (*p == '?') {
			//printf("FORMAT ME!\n");
			if (strncmp(buffer, "?pgwdth", 7) == 0) {
				// Temp value
				options.pgwdth = 20;
				options.fmt = 0;
				printf("FOUND PGWDTH\n");
			} else if (strncmp(buffer, "?mrgn", 5) == 0) {
				printf("FOUND MRGN\n");
				// Implement Me!
			} else if (strncmp(buffer, "?fmt", 4) == 0) {
				printf("FOUND FMT\n");
				// Implement Me!
			}
		}
		printf("%s", buffer);
	}

	fclose(fp);
	return 0;
}


