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

int update_options(char* line) {
	
	char* t;
	t = strtok(line, " ");	

	if (strncmp(line, "?pgwdth", 6) == 0){
		t = strtok(NULL, " ");	
		pgwdth = atoi(t);
		fmt = 1;
	} else if (strncmp(line, "?mrgn", 4) == 0) {
		t = strtok(NULL, " ");	
		mrgn = atoi(t);
	} else if (strncmp(line, "?fmt", 4) == 0) {
		t = strtok(NULL, " ");	
		if (strncmp(t, "on", 2) == 0) {
			fmt = 1;
		} else if (strncmp(t, "off", 3) == 0) {
			fmt = 0;
		}
	} else {
		return 0;
	}
	/*printf("UPDATE: %d %d %d\n", pgwdth, mrgn, fmt);*/
	return 0;
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
		
		if (fmt == 0)
		{
			if (*line == '?')
			{
				update_options(line);
			}
			else
			{
				printf("%s", line);
			}
		}
		else
		{
			if (*line == '?')
			{
				update_options(line);
			}
			else if (*line == '\n')
			{
				if (num_chars != 0) {
					printf("\n");
					num_chars = 0;
				}
				printf("\n");
			}
			else
			{
				t = strtok(line, " \n");
				while (t != NULL)
				{
					/* if over page width, newline and word*/
					if ((num_chars + strlen(t) + 1) > pgwdth)
					{
						printf("\n");
						num_chars = 0;
					} 
					/* if not start of line*/
					else if (num_chars != 0)
					{
						printf(" ");
						num_chars++;
					}

					/* if start of line*/
					if (num_chars == 0)
					{
						/* add margin */
						for( ;num_chars < mrgn; num_chars++)
						{
							printf(" ");
						}
					}
					printf("%s", t);
					num_chars += strlen(t);
					t = strtok(NULL, " \n");	
				}	
			}		
		}
	}
	
	if(fmt == 1) {
		printf("\n");
	}

	fclose(fp);
	return 0;
}

