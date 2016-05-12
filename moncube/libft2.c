#include "libft2.h"

void reverse(char *str, int len)
{
	int i=0, j=len-1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x%10) + '0';
		x = x/10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char *res, int afterpoint)
{
	int ipart = (int)n;
	float fpart = n - (float)ipart;
	int i = intToStr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';  // add dot
		fpart = fpart * pow(10, afterpoint);
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
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

void				itoa(int n, char s[])
{
	int				i;
	int				sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse2(s);
}

char				*dtoa(double f, short precision)
{
	char			*s;
	char			*s2;
	double			f3;
	double			f2;
	long long		z;
	int				i;

	s = ft_memalloc(sizeof(char) *30);

//	return (s);

	s = memset(s, '\0', 30);
	s2 = ft_memalloc(sizeof(char) *30);
	s2 = memset(s2, '\0', 30);
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
	z = (int) nearbyint(f2 * pow(10, precision));
	i = (int) ceil(log10(f2*pow(10, precision)));
	if (z == 0)
		i = 0;
	s2 = memset(s2, '0', precision - i);
	s2[precision - i] = '\0';
	s = strcat(s, s2);
	if (z != 0)
	{
		itoa(z, s2);
		s = strcat(s, s2);
	}
	return (s);
}

