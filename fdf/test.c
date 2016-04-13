#include <stdio.h>

void MatrixMult(int N, int M, int P, void *m1, void *m2, void *m3)
{
int                     i;
int                     j;
int                     k;
double          (*mat1) [N][M];
double          (*mat2) [M][P];
double          (*matRes) [N][P];

mat1 = m1;
mat2 = m2;
matRes = m3;

for (int i=0; i<N; i++)
	for (int j=0; j<M; j++)
		printf("%f ",mat1[0][i][j] );
//*(B[0][0])=123;



}

int main()
{
        double mat[30][30]
	double mat1[3][3:qqqq], mat2[30][30];
        int N,M,P;
	double T[3][4] = {{30, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9,10,11,12}};
N=3;
M=3;
P=2;
mat1[0][0]=2;mat1[0][1]=5;mat1[0][2]=0;
mat1[1][0]=3;mat1[1][1]=6;mat1[1][2]=3;
mat1[2][0]=4;mat1[2][1]=1;mat1[2][2]=2;

mat2[0][0]=1;mat2[0][1]=-1;
mat2[1][0]=2;mat2[1][1]=0;
mat2[2][0]=3;mat2[2][1]=5;

MatrixMult(3, 4, 0,T, NULL, NULL);
printf("%f\n",T[0][0]);
return 0;
}
