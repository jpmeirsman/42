#include "fdf.h"

void fdf_line(data_t *data,int xi,int yi,int xf,int yf, int color)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a =(double) (yf-yi)/(xf-xi);
	b = yi - a * xi;
	for ( x = xi ; x <= xf ; x++ )
	{
		y =(int) (a * x + b);
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, color);
	}
}

void fdf_bline(data_t *data,int xi,int yi,int xf,int yf, int color)
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;
	double	e2;

//printf("----%p\n",data);
	dx = abs(xf - xi);
	dy = abs(yf - yi);
	sx = (xi < xf) ? 1 : -1;
	sy = (yi < yf) ? 1 : -1;
	err = dx - dy;
printf("??? %d\n",data->put_in_canvas);
	while (true) {
		if (data->put_in_canvas)
			mlx_pixel_put2(data, xi, yi, color);
			else
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, xi, yi, color);
//		mlx_pixel_put2(data, xi, yi, color);
		if ((xi == xf) && (yi == yf)) break;
			e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			xi += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			yi += sy;
		}
	}
}
