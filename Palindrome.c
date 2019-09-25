/********
Fichier: Palindrome.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 25 septembre 2019
Description: Fonction détermine si un mot est un palindrome
********/

#include <stdio.h>

int palindrome (char *mot);

int main()
{
	char motATester[] = "kayak";

	if(palindrome(motATester))
	{
		printf("OUI");
	}
	else
	{
		printf("NON");
	}
		
	return 0;
}

int palindrome (char *mot)
{	
	int resultat = 1; //0 si le mot n'est pas un palindrome, 1 si oui
	int nbLettres=0; 
	int nbComparaisons;
	char caractere = mot[0]; // Variable tempon pour compter le nombre de lettres
	
	// Déterminer le nombre de lettres
	while (caractere !='\0')
	{
		nbLettres++;
		caractere = mot[nbLettres];
	}

	// Déterminer le nombre de comparaisons à faire
	if(nbLettres%2==0)
	{
		nbComparaisons = nbLettres/2;
	}
	else
	{
		nbComparaisons = (nbLettres-1)/2;
	}

	// Comparer les caractères
	for (int i=0; i< nbComparaisons; i++)
	{
		if (mot[i] != mot[nbLettres-1-i])
		{
			resultat = 0; // Pas un palindrome
		}
	}
	
	return resultat;
	
}
