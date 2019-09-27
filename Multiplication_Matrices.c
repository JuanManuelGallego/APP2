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
	int mA[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	int mB[N][N] = {{1,1,1},{2,2,2},{3,3,3}};
	int mR[N][N];
	
	multiplicationMatrices(mA, mB, mR);
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mR[i][j]);
		}
		printf("\n");
	}
	
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
