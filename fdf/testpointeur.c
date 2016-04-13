#include <stdio.h>

void SOMME(void *A, int N, int M)
{
char (*B)[N][M];
printf("adresse de A : %p\n",A);
B = A;

printf("adresse de B : %p\n",B);

printf("contenu de B : %d\n",(char) *(B[0][0]));
printf("contenu de B[0][0] : %d\n",(*B)[0][0]);
printf("contenu de B[0][0] : %d\n",***B);
printf("contenu de B[0][0] : %d\n",B[0][0][0]);
printf("contenu de B[0][0] : %d\n",*B[0][0]);



*(B[0][0])=123;



}

int main()
{
 char T[3][4] = {{30, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9,10,11,12}};

printf("valeur : %d\n",T[0][0]);
printf("adresse de T : %p\n",&T);
printf("adresse de T : %p\n",T);
printf("adresse de T[0][0] : %p\n",&T[0][0]);
printf("adresse de T[0][0] : %p\n",&(T[0][0]));

printf("contenu  de T[0][0] : %d\n",*(&T[0][0]));

SOMME(T, 3, 4);
printf("%d\n",T[0][0]);
return 0;
}
