/********
Fichier: Addition_Matrices.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 26 septembre 2019
Description: Fonction qui aditionne deux matrices
********/


#include <stdio.h>

#define M 3 //nombre de lignes
#define N 2 //nombre de colonnes

void additionMatrices (int matriceA[][N], int matriceB[][N], int matriceR[][N]);

int main(int argc, char **argv)
{
	printf("=============================================================\n");
	printf("Validation\n");
	printf("Matrice A       Matrice B       Resultat\n");
	
	int mA[M][N] = {{1,2},{3,4},{5,6}};
	int mB[M][N] = {{6,5},{4,3},{2,1}};
	int mR[M][N];
	
	additionMatrices(mA, mB, mR);
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mA[i][j]);
		}
		
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mB[i][j]);
		}
		
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mR[i][j]);
		}
		printf("\n");
	}
	printf("=============================================================\n");
	
	
	printf("=============================================================\n");
	printf("Plan de test\n");
	printf("Matrice A       Matrice B       Resultat\n");
	
	int mAT[M][N] = {{5,2},{9,4},{7,6}};
	int mBT[M][N] = {{6,3},{4,6},{2,7}};
	int mRT[M][N];
	
	additionMatrices(mAT, mBT, mRT);
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mAT[i][j]);
		}
		
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mBT[i][j]);
		}
		
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mRT[i][j]);
		}
		printf("\n\n");
	}
	
	
	printf("Matrice C       Matrice D       Resultat\n");
	
	int mCT[M][N] = {{5,-7},{-9,5},{7,1}};
	int mDT[M][N] = {{-9,3},{-5,6},{8,7}};
	
	additionMatrices(mCT, mDT, mRT);
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mCT[i][j]);
		}
		
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mDT[i][j]);
		}
		
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mRT[i][j]);
		}
		printf("\n");
	}

	printf("=============================================================\n");

	return 0;
}

void additionMatrices (int matriceA[][N], int matriceB[][N], int matriceR[][N])
{
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			matriceR[i][j] = matriceA[i][j] + matriceB[i][j];
		}
	}
}
