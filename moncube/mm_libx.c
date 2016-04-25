#include "mm_libx.h"

void		switch_buffer(data_t *data)
{
	short		temp;
	int			result;

	temp = data->front_buffer;
	data->front_buffer = data->back_buffer;
	data->back_buffer = temp;
	result = mlx_put_image_to_window (data->mlx_ptr, data->mlx_win,
		data->img[data->front_buffer], 0, 0);
}

int my_key_on_release_funct(int keycode, data_t *data)
{
	printf("Key Released: %d\n",keycode);
//	switch_buffer(data);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr,data->mlx_win);
//		printf("Fin du programme\n");
		exit(0);
	}
	return (0);
}

int my_key_on_maintain_funct(int keycode, data_t *data)
{
	printf("Key Maintained: %d\n",keycode);
	switch_buffer(data);
	return (0);
}

int my_key_on_click_funct(int keycode, data_t *data)
{
	printf("Key Clicked: %d\n",keycode);
	switch_buffer(data);
	return (0);
}

int my_expose_funct(data_t *data)
{
// cette fonction est appelée lorsque l'on replie la fenêtre puis
// lorsque l'on la réactive et que l'on génère un évènement clavier 
// ou souris sur mac sinon osx gère corrextement cela pour nous.
data_t *data2;
data2 = data;
printf("*");
	return (0);
}

int my_loop_funct(data_t *data)
{
//	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
//	printf("*%llu",compteur);
//	compteur++;
data_t *data2;
data2 = data;
	return (0);
}

int my_mouse_on_move_funct(int x, int y, data_t *data)
{
data_t *data2;
data2 = data;
	printf("x: %d y: %d\n", x ,y);
	return (0);
}

int my_mouse_on_click_funct(int button, int x, int y, data_t *data)
{
data_t *data2;
data2 = data;
	printf("Clicked Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}

int my_mouse_on_release_funct(int button, int x, int y, data_t *data)
{
data_t *data2;
data2 = data;
	printf("Released Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}

int mlx_pixel_put2(data_t *data, int x, int y, int	 color)
{
	if ((x >= 0) && (y >= 0) && (x < data->canvas_width) && (y< data->canvas_height))
	{
		if (data->anime == true)
			data->canvas[data->back_buffer][y * data->canvas_width + x] = color;
			else
			data->canvas[data->front_buffer][y * data->canvas_width + x] = color;
	}
	return (0);
}
