#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* osszefuz(char* szoveg1, char* szoveg2) {
	unsigned int hossz = strlen(szoveg1) + strlen(szoveg2);
	char *celszoveg;
	celszoveg = (char*)malloc(hossz * sizeof(char)+1);

	unsigned int i;
	for (i = 0;i<hossz;i++)
	{
		if (i<strlen(szoveg1))
			celszoveg[i] = szoveg1[i];
		else
			celszoveg[i] = szoveg2[i - strlen(szoveg1)];
	}
	celszoveg[i] = '\0';

	return celszoveg;
}

void szetszed(char* forrasszoveg, int szoveg1hossz, int szoveg2hossz) {
	int hossz = strlen(forrasszoveg);
	char *ujszoveg1 = (char*) malloc(szoveg1hossz * sizeof(char)+1);
	char *ujszoveg2 = (char*) malloc(szoveg2hossz * sizeof(char)+1);
	
	int i,j=0;

	for (i=0; i < szoveg1hossz;i++) {
		ujszoveg1[i] = forrasszoveg[i];
	}
	ujszoveg1[i] = '\0';
	while (j < szoveg2hossz) {
		ujszoveg2[j] = forrasszoveg[i];
		i++;
		j++;
	}
	ujszoveg2[j] = '\0';

	printf("%s = %s + %s \n", forrasszoveg, ujszoveg1, ujszoveg2);

}

int main()
{
	char* szoveg1 = "sdfghsdgh";
	char* szoveg2 = "aaaaaa";

	char* forras = osszefuz(szoveg1, szoveg2);

	printf("%s + %s = %s\n", szoveg1, szoveg2, forras);

	szetszed(forras, strlen(szoveg1), strlen(szoveg2));

	free(forras);


	return 0;
}