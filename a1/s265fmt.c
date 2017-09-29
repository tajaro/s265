/* 
s265fmt.c
Taylor Eby
September 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

/*
This struct records current options.
-1 indicates no option is selected 
*/
typedef struct fmt_options {
	/* 0 indicates feature is off */
	int pgwdth;
	/* Default is 0 */
	int mrgn;
	/* "off" == 0
	   "on == 1 */
	int fmt;
} fmt_options;

int main(int argc, char* argv[]) {
	char line[MAX_LINE_LEN];
	int num_chars;
	fmt_options options = {0, 0, 0};

	if (argc != 2) {
		printf("Input file not specified\n");
		exit(1);
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Input file doesn't exist\n");
		exit(1);
	}

	while (fgets(line, sizeof(char)*MAX_LINE_LEN, fp)) {
	
		/* Need to tokenize to remove whitespace, improve '?' searching and
		make formatting easier*/
		// fxn? void tokenize_line(char *line, char *words))
		char *t;
		t = strtok(line ," ");
		while (t != NULL) {
			if (*t == '?') {
				if (strncmp(t, "?pgwdth", 7) == 0) {
					t = strtok(NULL, " ");	
					options.pgwdth = atoi(t);
					options.fmt = 1;
					//printf("FOUND PGWDTH\n");
					//printf("%s %d", t, options.pgwdth);
				} else if (strncmp(t, "?mrgn", 5) == 0) {
					t = strtok(NULL, " ");	
					options.mrgn = atoi(t);
					//printf("FOUND MRGN\n");
				} else if (strncmp(t, "?fmt on", 7) == 0) {
					options.fmt = 1;
					//printf("FOUND FMT ON\n");
				} else if (strncmp(t, "?fmt off", 8) == 0) {
					options.fmt = 0;
					//printf("FOUND FMT OFF\n");
				}
			} else {
				if (options.fmt == 1) {
					num_chars += strlen(t) + 1;
					if (num_chars >= options.pgwdth) {
						//printf("%d %d", num_chars, options.pgwdth);
						printf("\n");
						num_chars = strlen(t);
					}
					if (*(t + sizeof(char)*(strlen(t)-1)) == '\n') {
						*(t + sizeof(char)*(strlen(t)-1)) = '\0';
					}
					printf("%s ", t);
					//t = strtok(NULL, " ");	
				} else if (options.fmt == 0) {
					// Implement me!
					printf("FORMATTING IS OFF!\n");
				}
			}
			
			t = strtok(NULL, " ");	
		} /* end of tokenization loop */			
		
		/* reset words array before end of loop */
		
	}

	fclose(fp);
	return 0;
}


