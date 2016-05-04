#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libc.h>
//#include "get_next_line.h"
#include "mm_readmap.h"
//#include "mm_math.h"
//#include "mm_libx.h"

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

t_vector3				**create_table_v3(int nb_row, int nb_col){
	t_vector3			**table1;
	t_vector3		*table2;

	table1 = (t_vector3 **) malloc(sizeof(void *) * nb_row);
	table2 = (t_vector3 *) malloc(sizeof(t_vector3) * nb_col*nb_row);
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

void		print_map(t_list2 *my_list, t_fic *tf)
{
	t_elem_int		*curr;
	long long		i;
	long long		j;

	curr = my_list->first;
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

void		create_map(t_list2 *my_list, t_fic *tf)
{
	t_elem_int		*curr;
	long long		i;
	long long		j;
	double			center_x;
	double			center_y;

	curr = my_list->first;
	tf->values = create_table(tf->nb_rows,tf->nb_columns);
	tf->tvect = create_table_v3(tf->nb_rows,tf->nb_columns);
	center_x = (float) (tf->nb_columns - 1) / 2;
	center_y = (float) (tf->nb_rows - 1) / 2;

	i = tf->nb_rows - 1;
	while (i >= 0)
	{
		j = tf->nb_columns - 1;
		while (j >= 0)
		{
			tf->values[i][j] = curr->value;
			tf->tvect[i][j] = set_vector3( j - center_x, i - center_y, 
				curr->value);
			curr = curr->next;
			j--;
		}
		i--;
	}
}

void		charge_map(t_list2 *my_list, t_fic *tf, int fd)
{
	t_elem_int		*curr;
	char		*buff;
	char		**str_buf;

	curr = NULL;
	my_list->first = curr;
	tf->nb_rows = 0;
	while ((get_next_line(fd, &buff) > 0))
	{
		str_buf = ft_strsplit(buff, ' ');
		tf->nb_columns = 0;
		while (str_buf[tf->nb_columns] != 0)
		{
			curr = malloc(sizeof(t_elem_int));
			curr->value = ft_atoi(str_buf[tf->nb_columns]);
			curr->next = my_list->first;
			my_list->first = curr;
			tf->nb_columns++;
		}
		tf->nb_rows++;
	}
}

t_fic		*read_file(char *file_name)
{
	int			fd;
	t_fic		*tf;
	t_list2		*my_list;

	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (NULL);
	my_list = initialisation();
	tf = malloc(sizeof(t_fic));
	charge_map(my_list, tf, fd);
	create_map(my_list, tf);
	return (tf);
}

