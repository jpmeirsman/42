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
