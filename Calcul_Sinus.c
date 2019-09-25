/********
Fichier: Calcul_Sinus.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 25 septembre 2019
Description: Fonction qui calcule le sinus
********/

#include <stdio.h>
#define PI 3.14159265358979323846
#define nbTermes 10

int factorielle(int facto)
{
	int retour_fac = 1;

	while(facto >= 2)
	{
		retour_fac *= facto;
		facto--; 
	}
	return retour_fac;
}

float puissance(float base, int exp)
{
	float retour_pui = 1;
	for(int i = 1; i <= exp; i++)
	{
		retour_pui *= base;
	}
	return retour_pui;
}
float sinus(int val_sin)
{
	float retour_sin = 0;
	int n = 0;
	
	for(int i = 1 ; i <= nbTermes; i += 2)
	{
		retour_sin += (puissance(val_sin,i)/ factorielle(i)) * puissance(-1,n);
		n++;
	}
	return retour_sin;
}

int main(int argc, char **argv)
{
	float val;
	printf("Quelle est la valeur du sin a calculer? (en radiants)\n");
	scanf("%f",&val);
	while(val > 2*PI)
	{
		val -= 2*PI;
	}
	
	
	printf("Le sinus est de %f ", sinus(val));
	
	
	return 0;
}




