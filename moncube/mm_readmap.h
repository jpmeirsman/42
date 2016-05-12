#ifndef					MM_READMAP_H
#define MM_READMAP_H

#include <stdio.h>
#include <unistd.h>
#include <libc.h>
#include "get_next_line.h"
#include "mm_math.h"
#include "mm_libx.h"

typedef struct			s_elem_int
{
	int				value;
	struct s_elem_int	*next;
} t_elem_int;

typedef struct			s_elem_pal
{
	t_palette			value;
	struct s_elem_pal	*next;
} t_elem_pal;

t_fic		*read_file(char *file_name);

#endif
