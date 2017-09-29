/* 
s265fmt.c
Taylor Eby
September 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_WORD_LEN 20
#define MAX_WORDS 100

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
	char words[MAX_WORDS][MAX_WORD_LEN];
	int num_words = 0;
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
			num_words++;
			strncpy(words[num_words], t, MAX_WORD_LEN);
			t = strtok(NULL, " ");
			
			// fxn? void update_options (fmt_options *options, char* word))
			if (words[num_words][0] == '?') {
				//printf("FORMAT ME!\n");
				if (strncmp(words[num_words], "?pgwdth", 7) == 0) {
					printf("FOUND PGWDTH\n");
					// Temp value
					options.pgwdth = 20;
					options.fmt = 1;
				} else if (strncmp(words[num_words], "?mrgn", 5) == 0) {
					printf("FOUND MRGN\n");
					// Temp value
					options.mrgn = 20;
				} else if (strncmp(words[num_words], "?fmt on", 7) == 0) {
					printf("FOUND FMT ON\n");
					// Temp value
					options.fmt = 1;
				} else if (strncmp(words[num_words], "?fmt off", 8) == 0) {
					printf("FOUND FMT OFF\n");
					// Temp value
					options.fmt = 0;
				}
			}
		}			

		/*
		// fxn? void update_options (fmt_options *options, char* line))
		if (word[0] == '?') {
			//printf("FORMAT ME!\n");
			if (strncmp(buffer, "?pgwdth", 7) == 0) {
				printf("FOUND PGWDTH\n");
				// Temp value
				options.pgwdth = 20;
				options.fmt = 1;
			} else if (strncmp(buffer, "?mrgn", 5) == 0) {
				printf("FOUND MRGN\n");
				// Temp value
				options.mrgn = 20;
			} else if (strncmp(buffer, "?fmt on", 7) == 0) {
				printf("FOUND FMT ON\n");
				// Temp value
				options.fmt = 1;
			} else if (strncmp(buffer, "?fmt off", 8) == 0) {
				printf("FOUND FMT OFF\n");
				// Temp value
				options.fmt = 0;
			}
		}
		*/

		// fxn? void format_line (fmt_options *options, char *buffer)
		if (options.fmt = 1) {
			if (options.pgwdth != 0) {
				// Implement me!
			} else if (options.mrgn != 0) {
				// Implement me!
			}
		}
		/* reset words array before end of loop */
		num_words = 0; 
	}

	fclose(fp);
	return 0;
}


