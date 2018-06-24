
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
	while (1) {		// végig megyünk a fájlon
		c = fgetc(fp);	//Reading the file
		if (c == EOF)
			break;
		if (c == str[j]) {     //ha str elsõ karakterét megtalálta keresünk tovább
			while (c == str[j] && j != "\0") {		// addig amíg a karakterek egyeznek és nincs vége a source-nak
				i++;
				j++;
				c = fgetc(fp);	//Reading the file
				if (c == EOF)
					break;
			}
			if (j == len && str[j] == '\0') {		// ha vége az str-nek 
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
