/********
Fichier: Recherche_Caractere.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 25 septembre 2019
Description: Fonction qui recherche un caractère dans une liste de caractères
********/
#include <stdio.h>

int recherche(char *phrase, char lettre )
{
	int found = -1;
	int i = 0;

	do
	{
		if(phrase[i] == lettre)
		{
			found = i;
		}
		i++;	
	}while(phrase[i] != '\0' && found == -1);
	
	return found;
}


int main(int argc, char **argv)
{
	char lettre;
	char phrase[100];
	printf("Veuillez saisir une chaine de caracteres\n");
	scanf("%s", phrase);

	printf("Quel est le caractere recherche?\n");
	scanf("%c",&lettre);
	scanf("%c",&lettre);
	
	printf("Le caractere se trouve a la position %d\n", recherche(phrase, lettre));
}


