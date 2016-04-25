#include <stdio.h>

#define bool short
#define true 1
#define false 0

int		MatrixMult(int N, int M, int P, void *m1, void *m2, void *m3)
{
	int			i;
	int			j;
	int			k;
	double		(*mat1) [N][M];
	double		(*mat2) [M][P];
	double		(*matRes) [N][P];

	mat1 = m1;
	mat2 = m2;
	matRes = m3;
	for (i = 0; i < N; i++)
		for ( j = 0; j < P; j++)
			matRes[0][i][j] = 0;
	for (i = 0; i < N; i++)
		for ( j = 0; j < P; j++)
			for (k = 0; k < M; k++)
				matRes[0][i][j] = mat1[0][i][k] * mat2[0][k][j] + matRes[0][i][j];
return (0);
}

