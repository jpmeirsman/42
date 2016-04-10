#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
} data_t;

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

int my_key_funct(int keycode, data_t *data)
{

	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
	printf("%i\n",keycode);
	if (keycode == 65307)
		return 1;
	return (0);
}

int main(void)
{
	int retour;
	data_t data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	retour = mlx_key_hook(data.mlx_win, my_key_funct, &data);
	fdf_line(&data,1,1,300,300,0x00FF00FF);
	if (retour == 1)
		return 0;
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
