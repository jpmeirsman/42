#include "moncube.h"

void		print_menu(t_data *data)
{
	int			increment;
	int			pas;

	increment = 1;
	pas = 12;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, "   M E N U    ");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, "Quitter  : Esc");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, "Camera");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " Zoom+   : Q");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " Zoom-   : S");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " Default : D");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, "Scene");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " x+      : 7");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " x-      : 8");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " x0      : 9");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " y+      : 4");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " y-      : 5");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " y0      : 6");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " z+      : 1");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " z-      : 2");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " z0      : 3");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, "Elevation");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " +       : W");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " -       : X");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 90,
		pas * increment++, 0X00FFFFFF, " Default : C");
}

void			print_fdf(t_data *data, tfic *tf)
{
	int			i;
	int			j;
	int			margin;
	int			marginw;
	int			marginh;
	float		avg;
	float		avg1;
	float		avg2;
	int			elev;
	int			elev2;
	int			max;
	int			max2;
	float		coef;
	float		anglez;
	float		pi;

	if (data->canvas_width < data->canvas_height)
		max = data->canvas_height;
	else
		max = data->canvas_width;
	if (tf->nbcolumns < tf->nbrows)
		max2 = tf->nbrows;
	else
		max2 = tf->nbcolumns;
	margin = 10;
	marginw = margin;
	marginh = margin;
	elev = 0;
	coef = 0.5;
	pi = 3.14159265359;
	anglez = (0/180) * pi;
	avg = (max - 2 * margin) / (max2 - 1);
	avg1 = (float) (data->canvas_width - 2 * margin) / (tf->nbcolumns - 1);
	avg2 = (float) (data->canvas_height - 2 * margin) / (tf->nbrows - 1);
	avg = avg1 < avg2 ? avg1 : avg2;
	if (avg1 < avg2)
		marginh = margin + (data->canvas_height - margin * 2 - (tf->nbrows * avg))/2;
		else
		marginw = margin + (data->canvas_width - margin * 2 - (tf->nbcolumns * avg))/2;
	data->put_in_canvas = true;
	printf("c: %llu, l: %llu\n",tf->nbcolumns,tf->nbrows);
printf("angle:%f cos:%f sin:%f\n",anglez, cos(anglez), sin(anglez));
	for (j = 0; j < tf->nbrows; j++)
	{
		for (i = 0; i < tf->nbcolumns; i++)
		{
//			elev = (int) (tf->values[j][i] * coef);
			if (j < tf->nbrows - 1)
			{
				elev2 = (int) (tf->values[j + 1][i] * coef);
				fdf_bline(data,
					(marginw + i * avg),
					(marginh + j * avg - elev),
					(marginw + i * avg),
					(marginh + (j + 1) * avg - elev2),
					0x00FFFFFF);
			}
			elev = (int) (tf->values[j][i] * coef);
			if (i < tf->nbcolumns - 1)
			{
				elev2 = (int) (tf->values[j][i + 1] * coef);
				fdf_bline(data,
					(marginw + i * avg),
					(marginh + j * avg - elev),
					(marginw + (i + 1) * avg),
					(marginh + j * avg - elev2),
					0x00FFFFFF);
			}
		}
	}
}

void		drawing_loop(t_data *data, t_meshes *arr_mesh)
{
//	device.clear; //mise à zero
	arr_mesh->m[0]->rotation.x += 0.01;
	arr_mesh->m[0]->rotation.y += 0.01;
	render(data, arr_mesh);
//	device.present(); // affichage du buffer
}

void		print_my_cube(t_data *data)
{
	float			center_x;
	float			center_y;
	t_meshes		*my_meshes;

	center_x = (float) data->canvas_width / 2;
	center_y = (float) data->canvas_height / 2;
//	my_meshes = malloc(sizeof(t_meshes));
	my_meshes = new_meshes(1);
	my_meshes->m[0] = new_cube("Mon Cube");
	data->cam = set_cam(zero_vector3(), zero_vector3());
	data->cam->position = set_vector3(0, 0 ,10);
	data->cam->target = set_vector3(0, 0 ,10);
	drawing_loop(data, my_meshes);
}

int main(void)
//int main(int argc, char **argv)
//int win_start()
{
	int retour;
	t_data data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
	{
		printf("I can't open the display\n");
		return (EXIT_FAILURE);
	}
	data.screen_width = 1024;
	data.screen_height = 768;
	data.canvas_width = data.screen_width - 100;
	data.canvas_height = data.screen_height;
	data.back_buffer = 1;
	data.front_buffer = 0;
	data.anime = 1;
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.screen_width,
		data.screen_height, "MonCube")) == NULL)
		return (EXIT_FAILURE);
	retour = mlx_key_hook(data.mlx_win, my_key_on_release_funct, &data);
	retour = mlx_loop_hook(data.mlx_ptr, my_loop_funct, &data);
	retour = mlx_mouse_hook(data.mlx_win,my_mouse_on_click_funct, &data);
	retour = mlx_expose_hook(data.mlx_win, my_expose_funct, &data);
	retour = mlx_hook(data.mlx_win, KeyPress, KeyPressMask,
		my_key_on_maintain_funct, &data);
	retour = mlx_hook(data.mlx_win, MotionNotify, PointerMotionMask,
		my_mouse_on_move_funct, &data);
	retour = mlx_hook(data.mlx_win, ButtonRelease, ButtonReleaseMask,
		my_mouse_on_release_funct, &data);

	print_menu(&data);
	data.put_in_canvas = false;
	fdf_bline(&data,data.canvas_width,0,data.canvas_width,data.screen_height
		- 1,0x00FFFFFF);
	data.put_in_canvas = true;

	data.img[data.back_buffer] = mlx_new_image(data.mlx_ptr, data.canvas_width
		, data.canvas_height);
	data.canvas[data.back_buffer] = (int *) mlx_get_data_addr(
		data.img[data.back_buffer], &data.bpp, &data.sizeline, &data.endian);
	data.img[data.front_buffer] = mlx_new_image(data.mlx_ptr, data.canvas_width
		, data.canvas_height);
	data.canvas[data.front_buffer] = (int *) mlx_get_data_addr(
		data.img[data.front_buffer], &data.bpp, &data.sizeline, &data.endian);

//	print_fdf(&data, tf);
	print_my_cube(&data);

	switch_buffer(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
		data.img[data.front_buffer], 0, 0);

	if (retour == 1)
		return 0;
	retour = mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}

