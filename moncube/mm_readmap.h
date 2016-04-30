#ifndef					MM_READMAP_H
#define MM_READMAP_H

#include <stdio.h>
#include <unistd.h>
#include <libc.h>
#include "get_next_line.h"

typedef struct			s_fic
{
	long long			nb_rows;
	long long			nb_columns;
	int					**values;
} t_fic;

typedef struct			s_elem_int
{
	int				value;
	struct s_elem_int	*next;
} t_elem_int;

#endif
