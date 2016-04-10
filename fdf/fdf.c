#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>


typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
} data_t;

int my_key_funct(int keycode, data_t *data)
{

mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
printf("%i\n",keycode);
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
	mlx_key_hook(data.mlx_win, my_key_funct, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
