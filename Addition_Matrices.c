/********
Fichier: Addition_Matrices.c
Auteurs: Juan Manuel Gallego galj1704
Jean-Philippe Lemay lemj0601
Date: 26 septembre 2019
Description: Fonction qui aditionne deux matrices
********/


#include <stdio.h>

#define M 4 //nombre de lignes
#define N 3 //nombre de colonnes

void additionMatrices (int matriceA[][N], int matriceB[][N], int matriceR[][N]);

int main(int argc, char **argv)
{
	int mA[M][N] = {{-1,1,1},{2,2,2},{3,3,3},{4,4,4}};
	int mB[M][N] = {{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
	int mR[M][N];
	
	additionMatrices(mA, mB, mR);
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf("%d\t",mR[i][j]);
		}
		printf("\n");
	}
	
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
