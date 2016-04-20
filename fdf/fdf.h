#ifndef LIBFDF_H
#define LIBFDF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"
#define true 1
#define false 0
typedef short boolean;

typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_display;
	int				screen_width;
	int				screen_height;
	void			*canvas[2];
	short			front_buffer;
	short			back_buffer;

} data_t;

void fdf_line(data_t *data,int xi,int yi,int xf,int yf, int color);
void fdf_bline(data_t *data,int xi,int yi,int xf,int yf, int color);

#endif
