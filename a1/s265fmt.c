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
		t = strtok(line ,'?');
		while (t != NULL) {
			strncpy(words[num_words], t, MAX_WORD_LEN);
			t = strtok(NULL, " ");	
	
			// fxn? void update_options (fmt_options *options, char* word))
			if (words[num_words][0] == '?') {
				//printf("FORMAT ME!\n");
				if (strncmp(words[num_words], "?pgwdth", 7) == 0) {
					printf("FOUND PGWDTH\n");
					// Temp value
					options.pgwdth = 30;
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
			} else {

				if (options.fmt == 1) {
					num_chars += strlen(words[num_words]);
					if (num_chars >= options.pgwdth) {
						printf("\n");
						num_chars = 0;
					}
					printf("%s ", words[num_words]);
				} else if (options.fmt == 0) {
					// Implement me!
					printf("FORMATTING IS OFF!\n");
				}
			}
			
			num_words++;
		} /* end of tokenization loop */			
		
		printf("%s", line);

		/* reset words array before end of loop */
		num_words = 0; 
		
	}

	fclose(fp);
	return 0;
}


