#include <stdio.h>

int main(int argc, char **argv)
{
	int found = -1;
	int i = 0;
	char lettre;
	char str[100];
	printf("Veuillez saisir une chaine de caracteres\n");
	scanf("%s", str);

	printf("Quel est le caractere recherche?\n");
	scanf("%c",&lettre);
	scanf("%c",&lettre);

	do
	{
		if(str[i] == lettre)
		{
			found = i;
		}
		i++;	
	}while(str[i] != '\0' && found == -1);
	printf("Le caractere se trouve a la position %d\n", found);
	//if(found == -1) printf("Le caractere n'a pas ete trouve : -1");
	return 0;
}

