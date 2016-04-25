#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminedoublon(char *s)
{
	int i;
	int j;
	unsigned long n;

	n = strlen(s);
	i = 0;
	while (i < (n - 1))
	{
		j = i + 1;
		while (j < n)
		{
			s[j] = (s[i] == s[j]) ? '\0' : s[j];
			j++;
		}
		i++;
	}
	i = j = 0;
	while (i < n)
	{
		if (s[i] != '\0')
			s[j++] = s[i];
		i++;
	}
	s[j]='\0';
}

int main(int argc, char **argv)
{
	char	*s;
	int		i;
	int		j;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	eliminedoublon(argv[1]);
	eliminedoublon(argv[2]);
	i = 0;
	while (i < strlen(argv[1]))
	{
		j = 0;
		while (j < strlen(argv[2]))
		{
			if (argv[1][i] == argv[2][j])
				printf("%c",argv[1][i]);
			j++;
		}
		i++;
	}
	printf("\n");
	return 0;
}
