//"C:\Users\galj1704\Documents\test.txt"


#include <stdio.h>

void Lecture()
{
	FILE *fr;
	char ch;
	
	fr = fopen("C:\\Users\\galj1704\\Documents\\test.txt", "r");
	while((ch = fgetc(fr)) != EOF){
	printf("%c",ch); }
}

void Ecriture()
{
 	FILE *fw = fopen("C:\\Users\\galj1704\\Documents\\test.txt","w");
 	const char *text = "Test";
 	fprintf(fw, "%s\n", text);
}

void Copier()
{
	FILE *fr = fopen("C:\\Users\\galj1704\\Documents\\test.txt", "r");
	
	FILE *fw = fopen("C:\\Users\\galj1704\\Documents\\test2.txt","w");
 	
	char ch;
	while((ch = fgetc(fr)) != EOF)
	{
		fprintf(fw, "%c	", ch);
	}
}

void LectureMatrice()
{
	FILE *fr = fopen("C:\\Users\\galj1704\\Documents\\test.txt", "r");
	char ch;
	int type, lignes, colones;
	fscanf(fr, "%c %d %d %d",&ch,&type,&lignes,&colones); 
	//printf("%c %d %d %d",ch,type,lignes,colones); 
	int matrice[lignes][colones]; 
	int val = 0;
	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colones; j++)
		{
			fscanf(fr,"%d", &val);	
			matrice[i][j] = val;
			printf("%d", matrice[i][j]);
		}
		printf("%c", '\n');
	}
	//void EcritureMatrice()
	FILE *fw = fopen("C:\\Users\\galj1704\\Documents\\test2.txt","w");
 	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colones; j++)
		{
			fprintf(fw, "%d", matrice[i][j]);
		}
		fprintf(fw,"%c",'\n');
	}
}

void EcritureMatrice()
{
	int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int lignes = 3;
	int colones = 3;
	FILE *fw = fopen("C:\\Users\\galj1704\\Documents\\test2.txt","w");
 	for(int i = 0; i < lignes; i++)
	{
		for(int j = 0; j < colones; j++)
		{
			fprintf(fw, "%d ", matrice[i][j]);
		}
		fprintf(fw,"%c",'\n');
	}
}
int main()
 {
	 EcritureMatrice();
	 return 0;
 }


