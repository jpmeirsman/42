#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <libc.h>
#include "get_next_line.h"

typedef struct			typefic
{
	long long			nbrows;
	long long			nbcolumns;
	int					**values;
} tfic;

typedef struct			TElementInt
{
	int				value;
	struct TElementInt	*next;
} ElemInt;

int		**createTable(int nbRow, int nbCol){
	int **table1 = (int **)malloc(sizeof(int*)*nbRow);
	int *table2 = (int *)malloc(sizeof(int)*nbCol*nbRow);
	for(int i = 0 ; i < nbRow ; i++){
		table1[i] = &table2[i*nbCol];
	}
	return table1;
}

void freeTable(int **table1){
	free(table1[0]);
	free(table1);
}
void		printMap(List *myList, tfic *tf)
{
	ElemInt		*Curr;
	long long	i;
	long long	j;

	Curr = myList->first;
	i = 0;
	while (i < tf->nbrows)
	{
		j = 0;
		while (j < tf->nbcolumns)
		{
			printf("%d ",tf->values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

}

void		createMap(List *myList, tfic *tf)
{
	ElemInt		*Curr;
	long long	i;
	long long	j;

	Curr = myList->first;
	tf->values = createTable(tf->nbrows,tf->nbcolumns);
	i = tf->nbrows - 1;
	while (i >= 0)
	{
		j = tf->nbcolumns - 1;
		while (j >= 0)
		{
			tf->values[i][j] = Curr->value;
			Curr = Curr->next;
			j--;
		}
		i--;
	}
}

void		chargeMap(List *myList, tfic *tf, int fd)
{
	ElemInt		*Curr;
	char		*BUFF;
	char		**StrBuf;

	Curr = NULL;
	myList->first = Curr;
	tf->nbrows = 0;
	while ((get_next_line(fd, &BUFF) > 0))
	{
		StrBuf = ft_strsplit(BUFF, ' ');
		tf->nbcolumns = 0;
		while (StrBuf[tf->nbcolumns] != 0)
		{
			Curr = malloc(sizeof(ElemInt));
			Curr->value = ft_atoi(StrBuf[tf->nbcolumns]);
			Curr->next = myList->first;
			myList->first = Curr;
			tf->nbcolumns++;
		}
		tf->nbrows++;
	}
}

int main(int argc, char **argv)
{
	int			fd;
	tfic		tf;
	List		*myList;

	if ((argc != 2) || (fd = open(argv[1],O_RDONLY)) <= 0)
		return (-1);
	myList = initialisation();
	chargeMap(myList, &tf, fd);
	createMap(myList, &tf);
	printMap(myList, &tf);
	close(fd);
	return 0;
}
