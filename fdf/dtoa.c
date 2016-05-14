#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

short		bit_value(unsigned long long l, short pos)
{
	short		r;
	r = (l & (1 <<  pos)) >> pos;
	return (r);

}

void		print_bits(unsigned long long l)
{
	int i;

	i = 127;
	while (i>=0)
	{
		printf("%d-",bit_value(l,i));
		i--;
	}
	printf("\n");;
}
void reverse2(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse2(s);
}

char		*dtoa(double f, short precision)
{
	char		*s;
	char		*s2;
	double		f3;
	double		f2;
	long long	z;
	int			i;

	s = malloc(sizeof(char) *20);
	s = memset(s, '\0', 20);
	s2 = malloc(sizeof(char) *20);
	s2 = memset(s2, '\0', 20);
	if (f < 0)
	{
		s=strcat(s,"-");
		f = -f;
	}
	f2 = modf(f, &f3);
	z = (int) f3;
	itoa(z, s2);
	s = strcat(s, s2);
	if (precision > 0)
		s = strcat(s, ".");
//	printf("%d %d %s %le %llu\n",precision,i,s,f2,z);
	z = (int) nearbyint(f2 * pow(10, precision));
	i = (int) ceil(log10(f2*pow(10, precision)));
//	printf("%d %d %s %le %llu\n",precision,i,s,f2,z);
//	return (s);
	if (z == 0)
		i = 0;
	s2 = memset(s2, '0', precision - i);
	s2[precision - i] = '\0';
	s = strcat(s, s2);
//	return (s);
	if (z != 0)
	{
	itoa(z, s2);
	s = strcat(s, s2);
	}
	return (s);
}

int main()
{
printf("%s\n", dtoa(12.018471, 4));
printf("%s\n", dtoa(-12.018471, 4));
printf("%s\n", dtoa(12.018471-02, 4));
printf("%s\n", dtoa(12.018471+02, 4));
printf("%s\n", dtoa(-0.000000e-00, 4));
printf("%s\n", dtoa(-0.0000005e-00, 8));
return 0;
}


