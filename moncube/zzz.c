#include <stdio.h>

int is_prime(int nb)
{
	int		i;

	i = 2;

	while (nb > i)
	{
//		printf("%d %d %f %f\n", i, nb / i, (float) nb / i, (float) nb / i - (nb / i));
		if (((float) nb / i - (nb / i)) == 0)
			return (0);
//			printf("n'est pas premier\n");
		i++;
	}
	return nb;
}






int main()
{
int a, b;

for (b = 2; b<=100; b++)
{
	a = is_prime(b);
	if (a != 0)
		printf("%d - ",a);
}
printf("\n");
//printf("%d %f %f\n", 12 / 5, (float) 12 / 5, (float)12 / 5 - (12 / 5));
return 0;
}
