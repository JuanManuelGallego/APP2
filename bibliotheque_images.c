/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"
#include <stdio.h>
#include <string.h>

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
	FILE *flot_entree = fopen(nom_fichier, "r");
	
	if(flot_entree != NULL)
	{
		char temp[MAX_CHAINE];
		fgets(temp, MAX_CHAINE,flot_entree); 
		if(temp[0] == '#') 
		{
			char *meta = strtok(temp+1,";");
			strcpy(p_metadonnees->auteur,meta);
			meta = strtok(NULL,";");
			strcpy(p_metadonnees->dateCreation, meta);
			meta = strtok(NULL,";");
			strcpy(p_metadonnees->lieuCreation,meta);
			printf("auteur: %s\ndate: %s\nlieu: %s\n",p_metadonnees->auteur, p_metadonnees->dateCreation,p_metadonnees->lieuCreation);
			
			fscanf(flot_entree, "%s", temp);
		} 
		else
		{
			strcpy(p_metadonnees->auteur,"");
			strcpy(p_metadonnees->dateCreation,"");
			strcpy(p_metadonnees->lieuCreation,"");
		}
		
		if(strncmp(temp,"P2",2) == 0)
		{
			fscanf(flot_entree, "%i", p_colonnes);
			fscanf(flot_entree, "%i", p_lignes);
			fscanf(flot_entree, "%i", p_maxval);
			
			if(*p_colonnes > MAX_LARGEUR || *p_lignes > MAX_HAUTEUR) return -2;
			
			for(int i=0; i < *p_lignes ; i++)
			{
				for(int j=0; j < *p_colonnes ; j++)
				{
					fscanf(flot_entree, "%i", &matrice[i][j]);
					printf("%d ",matrice[i][j]);
				}
				printf("\n");
			}
		}	
		else return -3;
	}
	else
	{
		printf("Erreur d'ouverture de fichier.\n");
		return -1;
	}
	
	
	fclose(flot_entree);
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
	FILE *flot_sortie = fopen(nom_fichier, "w");
	
	if(flot_sortie != NULL)
	{
		if(strncmp(metadonnees.auteur,"",MAX_CHAINE) != 0) 
		{
			fprintf(flot_sortie, "# %s; %s; %s", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
		}
		fprintf(flot_sortie, "P2\n%d %d\n%d\n",colonnes,lignes,maxval);
		
		for(int i=0; i < lignes ; i++)
		{
			for(int j=0; j < colonnes ; j++)
			{
				fprintf(flot_sortie,"%d ", matrice[i][j]);
			}
			fprintf(flot_sortie, "\n");
		}	
	}
	else
	{
		printf("Erreur d'ouverture de fichier.\n");
	}
	
	fclose(flot_sortie);
    return OK;
}

int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, 
			   int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
{
	*p_lignes2 = lignes1;
	*p_colonnes2 = colonnes1;
	
	for(int i = 0; i < lignes1; i++)
	{
		for(int j = 0; j < colonnes1; j++)
		{
			matrice2[i][j] = matrice1[i][j]; 
		}
	}
	//Retourner -1 si il y a une erreur????
	return 0; 
}

int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1])
{
	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colonnes; j++)
		{
			histogramme[matrice[i][j]] += 1; 
		}
	}
	//Retourner -1 si il y a une erreur????
	return 0;
}

int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes)
{
	int histogramme[MAX_VALEUR+1] = {0};
	int couleurPrep;
	int valCouleur = 0;
	
	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colonnes; j++)
		{
			histogramme[matrice[i][j]] += 1; 
		}
	}
	
	for (int i =1 ; i<= MAX_VALEUR ;i++)
	{
		if( histogramme[i] > valCouleur)
		{
			couleurPrep = i;
			valCouleur = histogramme[i];
		}
	}
	//Retourner -1 si il y a une erreur????
	return couleurPrep;
}

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur)
{
	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colonnes; j++)
		{
			matrice[i][j] += valeur;
			if(matrice[i][j] > maxval) matrice[i][j] = maxval;
			else if(matrice[i][j] < 0) matrice[i][j] = 0;
		}
	}
	//Retourner -1 si il y a une erreur????
	return 0;
}

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval)
{
	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colonnes; j++)
		{
			matrice[i][j] = maxval - matrice[i][j] ;
		}
	}
	//Retourner -1 si il y a une erreur????
	return 0;
}

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1,
				 int lignes2, int colonnes2, int *p_lignes, int *p_colonnes)
{
	if(lignes2 < lignes1 || colonnes2 < colonnes1 || lignes2 >= *p_lignes || colonnes2 >= *p_colonnes) return -1;
	
	for(int i = lignes1; i <= lignes2; i++)
	{
		for(int j = colonnes1; j <= colonnes2; j++)
		{
			matrice[i-lignes1][j-colonnes1] = matrice[i][j];
		}
	}
	
	*p_lignes = lignes2 - lignes1 + 1;
	*p_colonnes = colonnes2 - colonnes1 + 1;
	
	return 0;
}

int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1,
						int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	if(lignes1 != lignes2 || colonnes1 != colonnes2) return 1;
	
	for(int i = 0; i < lignes1; i++)
	{
		for(int j = 0; j < colonnes1; j++)
		{
			if (matrice1[i][j] != matrice2[i][j]) return 1;
		}
	}
	
	return 0;
}

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)
{
	int matriceTemp[MAX_HAUTEUR][MAX_LARGEUR];
	for(int i = 0; i < *p_lignes; i++)
	{
		for(int j = 0; j < *p_colonnes; j++)
		{
			matriceTemp[i][j] = matrice[i][j];
		}
	}
	
	int temp = *p_colonnes;
	*p_colonnes = *p_lignes;
	*p_lignes = temp;
	
	for(int i = 0; i < *p_lignes; i++)
	{
		for(int j = 0; j < *p_colonnes; j++)
		{
			if(sens == 0) matrice[i][j] = matriceTemp[j][*p_lignes - 1 - i];
			else  matrice[i][j] = matriceTemp[*p_colonnes -1 - j][i];
		}
	}
	
	return 0;
	
}
	
