#include "mm_libx2.h"
#include "mm_graph.h"

void			print_menu(t_data *data)
{
	int			increment;
	int			pas;
//	char		s[20];

	increment = 1;
	pas = 12;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
	pas * increment++, 0X00FFFFFF, "   M E N U    ");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Quit    : Esc");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Camera");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " Zoom+   : Q");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " Zoom-   : S");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " Default : D");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Scene rotation");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " x+      : 7");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " x-      : 8");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " x0      : 9");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " y+      : 4");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " y-      : 5");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " y0      : 6");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " z+      : 1");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " z-      : 2");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " z0      : 3");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Scene position");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " x+      : R");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " x-      : T");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " x0      : Y");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " y+      : F");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " y-      : G");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " y0      : H");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " z+      : V");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " z-      : B");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " z0      : N");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Elevation");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " +       : W");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " -       : X");
		
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, " Default : C");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Mouse");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "X:    0 Y:    0");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Camera");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Elev:    0");
	increment++;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "Scene");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "RotX:    0");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "RotY:    0");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "RotZ:    0");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "PosX:    0");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "PosY:    0");
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, "PosZ:    0");
//	print_info(data);
}






void		clear_canvas(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->canvas_height)
	{
		j = 0;
		while (j < data->canvas_width)
		{
			mlx_pixel_put2(data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void		drawing_loop(t_data *data, t_meshes *arr_mesh)
{
return ;
arr_mesh->m[0]->rotation.x += 0.01;
arr_mesh->m[0]->rotation.y += 0.01;
printf("===%le\n",arr_mesh->m[0]->rotation.y);
render(data, arr_mesh);
}
/*
void		switch_buffer(t_data *data)
{
	short		temp;
	int			result;

	temp = data->front_buffer;
	data->front_buffer = data->back_buffer;
	data->back_buffer = temp;
	result = mlx_put_image_to_window (data->mlx_ptr, data->mlx_win,
		data->img[data->front_buffer], 0, 0);
}
*/
int my_key_on_release_funct(int keycode, t_data *data)
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

void			print_sub_info(t_data *data, int increment, char *s1, 
					double value)
{
	int			pas;
	char		*s;
	char		*s2;

	s2 = malloc(20);
	pas = 12;
	s = s1;
	s2 = ft_strcat(s2, s);
	s = dtoa(value, 3);
	s2 = ft_strcat(s2, s);
	data->put_in_canvas = false;
	draw_square(data, data->screen_width - 95, pas * (increment - 1),
		data->screen_width - 2, pas * (increment - 1) + 12, 0x00000000);
	data->put_in_canvas = true;
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment, 0X00FFFFFF, s2);
}

void			print_info(t_data *data)
{
	print_sub_info(data, 41, "Elev: ", data->ratio_cam);
	print_sub_info(data, 43, "RotX: ", data->scene_rot.x);
	print_sub_info(data, 44, "RotY: ", data->scene_rot.y);
	print_sub_info(data, 45, "RotZ: ", data->scene_rot.z);
	print_sub_info(data, 46, "PosX: ", data->scene_pos.x);
	print_sub_info(data, 47, "PosY: ", data->scene_pos.y);
	print_sub_info(data, 48, "PosZ: ", data->scene_pos.z);
}

int my_key_on_maintain_funct(int keycode, t_data *data)
{
	if (keycode == 115)
	{
		clear_canvas(data);
		data->ratio_cam += data->step_cam;
		if (data->ratio_cam >0)
			data->ratio_cam = 0;
		data->cam->position = set_vector3(0, 0, data->ratio_cam);
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 113)
	{
		clear_canvas(data);
		data->ratio_cam -= data->step_cam;
		if (data->ratio_cam >0)
			data->ratio_cam = 0;
		data->cam->position = set_vector3(0, 0, data->ratio_cam);
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 100)
	{
		clear_canvas(data);
		data->ratio_cam = data->ratio_init_cam;
		data->cam->position = set_vector3(0, 0, data->ratio_cam);
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 232)
	{
		clear_canvas(data);
		data->scene_rot.x += 0.01 ;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 95)
	{
		clear_canvas(data);
		data->scene_rot.x -= 0.01 ;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 231)
	{
		clear_canvas(data);
		data->scene_rot.x = 0;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 39)
	{
		clear_canvas(data);
		data->scene_rot.y += 0.01;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 40)
	{
		clear_canvas(data);
		data->scene_rot.y -= 0.01;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 45)
	{
		clear_canvas(data);
		data->scene_rot.y = 0;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 38)
	{
		clear_canvas(data);
		data->scene_rot.z += 0.01;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 233)
	{
		clear_canvas(data);
		data->scene_rot.z -= 0.01;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 34)
	{
		clear_canvas(data);
		data->scene_rot.z = 0;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 114)
	{
		clear_canvas(data);
		data->scene_pos.x += 0.1 ;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 116)
	{
		clear_canvas(data);
		data->scene_pos.x -= 0.1 ;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 121)
	{
		clear_canvas(data);
		data->scene_pos.x = 0;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 102)
	{
		clear_canvas(data);
		data->scene_pos.y += 0.1;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 103)
	{
		clear_canvas(data);
		data->scene_pos.y -= 0.1;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 104)
	{
		clear_canvas(data);
		data->scene_pos.y = 0;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 118)
	{
		clear_canvas(data);
		data->scene_pos.z += 0.1;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 98)
	{
		clear_canvas(data);
		data->scene_pos.z -= 0.1;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 110)
		print_info(data);
	{
		clear_canvas(data);
		data->scene_pos.z = 0;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 119)
	{
		clear_canvas(data);
		data->coef_elev += data->step_elev;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 120)
	{
		clear_canvas(data);
		data->coef_elev -= data->step_elev;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	if (keycode == 99)
	{
		clear_canvas(data);
		data->coef_elev = data->coef_init_elev;
		render_fdf(data);
		print_fdf(data);
		switch_buffer(data);
		print_info(data);
	}
	return (0);
}

int my_key_on_click_funct(int keycode, t_data *data)
{
//	printf("Key Clicked: %d\n",keycode);
keycode = data->coef_elev;
//	switch_buffer(data);
	return (0);
}

int my_expose_funct(t_data *data)
{
// cette fonction est appelée lorsque l'on replie la fenêtre puis
// lorsque l'on la réactive et que l'on génère un évènement clavier 
// ou souris sur mac sinon osx gère corrextement cela pour nous.
	print_menu(data);
	print_buffer(data);
	return (0);
}

int my_loop_funct(t_data *data)
{
//	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
//	printf("*%llu",compteur);
//	compteur++;
return (0);
clear_canvas(data);
data->my_meshes->m[0]->rotation.x += 0.01;
data->my_meshes->m[0]->rotation.y += 0.01;
render(data, data->my_meshes);
switch_buffer(data);
	return (0);
}

int my_mouse_on_move_funct(int x, int y, t_data *data)
{
	int			increment;
	int			pas;
	char		s[20];
	char		*s2;
	int			i;
	int			len;

	s2 = malloc(20);
	increment = 38;
	pas = 12;
	s2 = ft_strcat(s2, "X:");
	itoa(x, s);
	len = 4 - ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		s2 = ft_strcat(s2, " ");
		i++;
	}
	s2 = ft_strcat(s2, s);
	s2 = ft_strcat(s2, " Y:");
	itoa(y, s);
	len = 4 - ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		s2 = ft_strcat(s2, " ");
		i++;
	}
	s2 = ft_strcat(s2, s);
	data->put_in_canvas = false;
	draw_square(data, data->screen_width - 91, pas * (increment - 1),
		data->screen_width - 2, pas * (increment - 1) + 12, 0x00000000);
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->screen_width - 95,
		pas * increment++, 0X00FFFFFF, s2);
	data->put_in_canvas = true;

	return (0);
}

int my_mouse_on_click_funct(int button, int x, int y, t_data *data)
{
t_data *data2;
data2 = data;
	printf("Clicked Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}

int my_mouse_on_release_funct(int button, int x, int y, t_data *data)
{
t_data *data2;
data2 = data;
	printf("Released Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}
/*
int mlx_pixel_put2(t_data *data, int x, int y, int	 color)
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
*/
