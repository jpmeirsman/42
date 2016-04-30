#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libc.h>
#include "get_next_line.h"
#include "mm_readmap.h"

int			**create_table(int nb_row, int nb_col){
	int		**table1;
	int		*table2;

	table1 = (int **) malloc(sizeof(int*) * nb_row);
	table2 = (int *) malloc(sizeof(int) * nb_col*nb_row);
	for(int i = 0 ; i < nb_row ; i++){
		table1[i] = &table2[i*nb_col];
	}
	return table1;
}

void		free_table(int **table1)
{
	free(table1[0]);
	free(table1);
}

void		print_map(t_list2 *myList, t_fic *tf)
{
	t_elem_int		*curr;
	long long		i;
	long long		j;

	curr = myList->first;
	i = 0;
	while (i < tf->nb_rows)
	{
		j = 0;
		while (j < tf->nb_columns)
		{
			printf("%d ", tf->values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

}

void		create_map(t_list2 *myList, t_fic *tf)
{
	t_elem_int		*curr;
	long long		i;
	long long		j;

	curr = myList->first;
	tf->values = create_table(tf->nb_rows,tf->nb_columns);
	i = tf->nb_rows - 1;
	while (i >= 0)
	{
		j = tf->nb_columns - 1;
		while (j >= 0)
		{
			tf->values[i][j] = curr->value;
			curr = curr->next;
			j--;
		}
		i--;
	}
}

void		charge_map(t_list2 *myList, t_fic *tf, int fd)
{
	t_elem_int		*curr;
	char		*buff;
	char		**str_buf;

	curr = NULL;
	myList->first = curr;
	tf->nb_rows = 0;
	while ((get_next_line(fd, &buff) > 0))
	{
		str_buf = ft_strsplit(buff, ' ');
		tf->nb_columns = 0;
		while (str_buf[tf->nb_columns] != 0)
		{
			curr = malloc(sizeof(t_elem_int));
			curr->value = ft_atoi(str_buf[tf->nb_columns]);
			curr->next = myList->first;
			myList->first = curr;
			tf->nb_columns++;
		}
		tf->nb_rows++;
	}
}
