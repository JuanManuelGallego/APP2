/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1] = {0};
    char nom[MAX_CHAINE] = "test2.pgm";
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

	// LIRE FICHIER
    retour = pgm_lire(nom, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);

	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR");
	printf("\n");
	
	
	
	// TROUVER COULEUR PRÉPONDÉRANTE
	retour = pgm_couleur_preponderante(image1, lignes1, colonnes1);
	printf("Couleur prépondérante : %i\n",retour);
	
	
	// CRÉER HISTOGRAME
	retour = pgm_creer_histogramme(image1, lignes1, colonnes1, histogramme);
	
	for (int i=1; i <= maxval ; i++)
	{
		printf("%i : %i\n",i,histogramme[i]);
	}
	
	// ÉLCAIRCIR OU NORCIR

	//retour = pgm_eclaircir_noircir(image1,lignes1, colonnes1, maxval, -2);
	
	

	
	retour = pgm_extraire(image1, 1, 1, 2, 1, &lignes1, &colonnes1);
	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR");
	printf("\n");
	
	// COPIER IMAGE
	retour = pgm_copier(image1, lignes1, colonnes1, image2, &lignes2, &colonnes2);
	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR");
	printf("\n");
	
	// CRÉER LE NÉGATIF
	/*retour = pgm_creer_negatif(image1,lignes1, colonnes1, maxval);
	printf("-> Retour (Créer le négatif) : ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR");
	printf("\n");*/

	// PIVOTER
	//retour = pgm_pivoter90(image2, &lignes2, &colonnes2,0);
	
	
	
	// SONT IDENTIQUES ?
	retour = pgm_sont_identiques(image1, lignes1, colonnes1, image2, lignes2, colonnes2);
	
	printf("-> Retour (identiques) : ");
	if (retour == 0)
		printf("-> INDENTIQUES");
	else
		printf("-> DIFFÉRENTES");
	printf("\n");
	

	// ERCIRE FICHIER
	char nom2[MAX_CHAINE] = "test.pgm";
    pgm_ecrire(nom2, image2, 
               lignes2, colonnes2, 
               maxval, metadonnees);            

    printf("-> Fin!\n");

    return 0;
}
