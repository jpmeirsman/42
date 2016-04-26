#ifndef LIBFDF_H
# define LIBFDF_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
} data_t;

void fdf_line(data_t *data,int xi,int yi,int xf,int yf, int color);

#endif
