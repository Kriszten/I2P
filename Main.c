
#include <stdio.h>
#include <string.h>

int search(char* str) {
	FILE* fp;
	printf("Opening the file in read mode. \n");
	fp = fopen("i2ptest01.txt", "r");
	if (fp == NULL) {
		printf("Could not open the file. \n");
		return 1;
	}
	printf("Reading the file. \n");
	char c;
	int wherelaststr = -1;
	int i = 0;
	int j = 0;
	int len = strlen(str);      // str hossza
	while (1) {		// v�gig megy�nk a f�jlon
		c = fgetc(fp);	//Reading the file
		if (c == EOF)
			break;
		if (c == str[j]) {     //ha str els� karakter�t megtal�lta keres�nk tov�bb
			while (c == str[j] && j != "\0") {		// addig am�g a karakterek egyeznek �s nincs v�ge a source-nak
				i++;
				j++;
				c = fgetc(fp);	//Reading the file
				if (c == EOF)
					break;
			}
			if (j == len && str[j] == '\0') {		// ha v�ge az str-nek 
				// BINGO!! we find our search string.
				wherelaststr = i;
			}
		}
		i++;
		j = 0;
	}
	if (wherelaststr != -1) {
		printf("\n '%s' appears last at %d. character.\n", str, wherelaststr);
	}
	else {
		printf("\n '%s' does not appear.\n", str);
	}
	return wherelaststr;
}



int main()
{
	char *str = "aa";
	int appears=search(str);
	

	return 0;

}
