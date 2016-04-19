#include "fdf.h"
//#include "mlx_int.h"

/*
typedef struct s_xvar
{
	Display*display;
	Windowro			ot;
	intscreen;
	intdepth;
	Visual*visual;
	Colormapcmap;
	i						ntprivate_cmap;
	t_win_list*win_list;
	int(*loop_hook)();
	void							*loop_param;
	intuse_xshm;
	intpshm_format;
	intdo_flush;
	intdecrgb[6];
} t_xvar;
*/
/*
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
*/


int my_key_funct(int keycode, data_t *data)
{
	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
	printf("%i\n",keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr,data->mlx_win);
		printf("Fin du programme\n");
		exit(0);
	}
	return (0);
}

int my_loop_funct(data_t *data)
{
//	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
	printf("*");
	return (0);
}

int my_mouse_funct(int button, int x, int y, data_t *data)
{
//	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
	printf("Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}

int main(void)
{
	int retour;
	int retour2;
	data_t data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
	{
		printf("I can't open the display\n");
		return (EXIT_FAILURE);
	}
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
//	retour = mlx_do_key_autorepeaton(data.mlx_ptr);
	retour = mlx_key_hook(data.mlx_win, my_key_funct, &data);
	retour = mlx_loop_hook(data.mlx_win, my_loop_funct, &data);
	retour = mlx_mouse_hook(data.mlx_win,my_mouse_funct, &data);
//	fdf_line(&data,1,1,300,300,0x00FF00FF);
	mlx_string_put(data.mlx_ptr, data.mlx_win, 30, 30, 0X000000FF, "Coucou");
	if (retour == 1)
		return 0;
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
