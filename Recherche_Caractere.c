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
	printf("=============================================================\n");
	printf("Validation\n");
	printf("Chaine                     Caractere    Resultat\n");
	printf("anticonstitutionnellement       n           %d\n",recherche("anticonstitutionnellement", 'n'));
	printf("bonjour                         e          %d\n",recherche("bonjour", 'e'));
	printf("bonjour                         r           %d\n",recherche("bonjour", 'r'));
	printf("allocommentcava                 a           %d\n",recherche("allocommentcava", 'a'));
	printf("=============================================================\n");
	
	printf("=============================================================\n");
	printf("Plan de test\n");
	printf("Chaine                     Caractere    Resultat\n");
	printf("allo                            l           %d\n",recherche("allo", 'l'));
	printf("parametre                       e           %d\n",recherche("parametre", 'e'));
	printf("olympique                       e           %d\n",recherche("olympique", 'e'));
	printf("clavier                         j          %d\n",recherche("clavier", 'j'));
	printf("=============================================================\n");

	/*
	char lettre;
	char phrase[100];
	printf("Veuillez saisir une chaine de caracteres\n");
	scanf("%s", phrase);

	printf("Quel est le caractere recherche?\n");
	scanf("%c",&lettre);
	scanf("%c",&lettre);
	
	printf("Le caractere se trouve a la position %d\n", recherche(phrase, lettre));
	*/
}


