/********
Fichier: Multiplication_Matrices.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 26 septembre 2019
Description: Fonction qui multiplie deux matrices
********/


#include <stdio.h>

#define N 3 //nombre de lignes et colonnes

void multiplicationMatrices (int matriceA[][N], int matriceB[][N], int matriceR[][N]);

int main(int argc, char **argv)
{
	printf("==================================================================================\n");
	printf("Plan de test\n");
	printf("    Matrice A                       Matrice B                       Resultat\n");

	int mA[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	int mB[N][N] = {{1,1,1},{2,2,2},{3,3,3}};
	int mR[N][N];
	
	multiplicationMatrices(mA, mB, mR);
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mA[i][j]);
		}
		printf("\t");
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mB[i][j]);
		}
		printf("\t");
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mR[i][j]);
		}
		printf("\n\n");
	}
	
	printf("    Matrice C                       Matrice D                       Resultat\n");
	
	int mCT[N][N] = {{-1,-2,-3},{0,0,0},{7,8,9}};
	int mDT[N][N] = {{5,10,18},{99,56,45},{-58,-48,3}};
	
	multiplicationMatrices(mCT, mDT, mR);
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mCT[i][j]);
		}
				printf("\t");

		for (int j=0; j<N; j++)
		{
			printf("%d\t",mDT[i][j]);
		}
				printf("\t");

		for (int j=0; j<N; j++)
		{
			printf("%d\t",mR[i][j]);
		}
		printf("\n\n");
	}


	printf("==================================================================================\n");

	
	return 0;
}

void multiplicationMatrices (int matriceA[][N], int matriceB[][N], int matriceR[][N])
{
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			matriceR[i][j] = 0;
			for(int k=0; k<N; k++)
			{
				matriceR[i][j] += matriceA[i][k] * matriceB[k][j] ;
			}
			
		}
	}
}
