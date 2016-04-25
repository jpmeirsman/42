#include <stdio.h>
#include "math.c"

int main(void)
{
	int i,j,k;
	int N,M,P;
	double mat[3][2];
	double mat1[3][3];
	double mat2[3][2];

/*
	printf ("Donner le nombre de lignes de la premiere matrice : ");
        flushall(); scanf ("%d",&N);
	printf ("\nDonner la dimension commune aux 2 matrices : ");
	scanf ("%d",&M);
	printf ("\nDonner le nombre de colonnes de la deuxieme matrice : ");
	scanf ("%d",&P);
//i lignes premiere dimension du tableau, j colonnes
//Remplissage de la premiere matrice--------------------------------------------

	printf ("\nDonner les elements de la premiere matrice :\n");
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
			{
			printf ("ligne %d, colonne %d : ",i+1,j+1);
			scanf ("%d",&mat1[i][j]);
			}
	}

//Remplissage de la seconde matrice---------------------------------------------

	printf ("\nDonner les elements de la seconde matrice :\n");
	for (i=0;i<M;i++)
	{
		for (j=0;j<P;j++)
			{
			printf ("ligne %d, colonne %d : ",i+1,j+1);
			scanf ("%d",&mat2[i][j]);
			}
	}
*/

N=3;
M=3;
P=2;
mat1[0][0]=2;mat1[0][1]=5;mat1[0][2]=0;
mat1[1][0]=3;mat1[1][1]=6;mat1[1][2]=3;
mat1[2][0]=4;mat1[2][1]=1;mat1[2][2]=2;

mat2[0][0]=1;mat2[0][1]=-1;
mat2[1][0]=2;mat2[1][1]=0;
mat2[2][0]=3;mat2[2][1]=5;
printf("start\n");

MatrixMult(N, M, P, mat1, mat2, mat);

//Affichage de la matrice résultante--------------------------------------------

	printf ("\nProduit matriciel :\n");
	for (i=0;i<N;i++)
	{
		for (j=0;j<P;j++)
			{
				printf ("ligne %d,colonne %d : ",i+1,j+1);
				printf ("%f\n",mat[i][j]);
			}
	}
return 0;
}

