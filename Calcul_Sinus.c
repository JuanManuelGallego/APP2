/********
Fichier: Calcul_Sinus.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 25 septembre 2019
Description: Fonction qui calcule le sinus
********/

#include <stdio.h>
#define PI 3.14159265358979323846
#define nbTermes 5

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
float sinus(float val_sin)
{
	float retour_sin = 0;
	int n = 0;
	
	for(int i = 1 ; i <= nbTermes*2; i += 2)
	{
		retour_sin += (puissance(val_sin,i)/ factorielle(i)) * puissance(-1,n);
		n++;
	}
	return retour_sin;
}

int main(int argc, char **argv)
{
	printf("=============================================================\n");
	printf("Validation\n");
	printf("Valeur  Resultat\n");
	printf("1         %0.4f\n",sinus(1));
	printf("0         %0.0f\n",sinus(0));
	printf("PI/4      %0.4f\n",sinus(PI/4));
	printf("PI/2      %0.0f\n",sinus(PI/2));
	printf("=============================================================\n");

	printf("=============================================================\n");
	printf("Plan de test\n");
	printf("Valeur  Resultat\n");
	printf("0.5       %0.4f\n",sinus(0.5));
	printf("1         %0.4f\n",sinus(1));
	printf("0         %0.0f\n",sinus(0));
	printf("PI/6      %0.1f\n",sinus(PI/6));
	printf("=============================================================\n");
/*
	float val;
	printf("Quelle est la valeur du sin a calculer? (en radians)\n");
	scanf("%f",&val);
	while(val > 2*PI)
	{
		val -= 2*PI;
	}
	
	
	printf("Le sinus est de %f ", sinus(val));
	
*/	
	return 0;
}




