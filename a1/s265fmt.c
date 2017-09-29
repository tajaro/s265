/* 
s265fmt.c
Taylor Eby
September 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

/* 0 indicates feature is off */
int pgwdth = 0;
/* Default is 0 */
int mrgn = 0;
/* "off" == 0. "on" == 1 */
int fmt = 0;

/* 	int update_operations (char*, char*)
	Takes current token and checks the formatting operation. Updates global
	variables pgwdth, mrgn, fmt accordingly. Returns 1 is successful, 0
	otherwise.
	Preconditions:
		- Current token must start with a ?
*/
int update_options(char* line, char* t) {
	if (strncmp(t, "?pgwdth", 6) == 0){
		t = strtok(NULL, " \n");	
		pgwdth = atoi(t);
		fmt = 1;
	} else if (strncmp(t, "?mrgn", 4) == 0) {
		t = strtok(NULL, " \n");	
		mrgn = atoi(t);
	} else if (strncmp(t, "?fmt", 3) == 0) {
		t = strtok(NULL, " \n");	
		if (strncmp(t, "on", 2) == 0) {
			fmt = 1;
		} else if (strncmp(t, "off", 3) == 0) {
			fmt = 0;
		} else {
			printf("Something is very wrong\n");
		}
	} else {
		return 0;
	}
	return 1;
}

int main(int argc, char* argv[]) {
	char line[MAX_LINE_LEN];
	int num_chars = 0;
	char *t;
	char *val;

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
		t = strtok(line, " \n");
		while (t != NULL) {
			if (fmt == 0) {
				if (*t == '?') {
					update_options(line, t);
					t = strtok(NULL, " \n");
					continue;
				}
				printf("%s", t);
				t = strtok(NULL, "\n");
			} else if (fmt == 1) {
				if (*t == '?') {
					update_options(line, t);
					t = strtok(NULL, " \n");
					continue;
				}

				/* if over page width, newline and word*/
				if ((num_chars + strlen(t) + 1) > pgwdth) {
					printf("\n%s", t);
					num_chars = strlen(t);
				/* if not start of line*/
				} else if (num_chars != 0) {
					printf(" %s", t);
					num_chars += strlen(t) + 1;
				/* if start of line*/
				} else if (num_chars == 0) {
					printf("%s", t);
					num_chars = strlen(t);
				} else {
					printf("Something is very wrong\n");
				}
				t = strtok(NULL, " \n");	
			}
				
		} /* end of tokenization loop */			
		if (fmt == 0) {
			printf("\n");
		}
	}
	

	if(fmt == 1) {
		printf("\n");
	}

	fclose(fp);
	return 0;
}


