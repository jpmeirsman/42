#include "moncube.h"
//#include "mm_libx2.h"

void			start_fdf(t_data *data, t_fic *tf)
{
	int			i;
	int			j;
	t_mesh		*mesh;
	double		min_z;
	double		max_z;
	double		z;
	double		pi;

	data->tf = tf;
	pi = 3.14159265359;
	if (tf->nb_columns < tf->nb_rows)
		data->ratio_init_cam = tf->nb_rows * -3;
		else
		data->ratio_init_cam = tf->nb_columns * -3;
	data->ratio_cam = data->ratio_init_cam;
	data->step_cam = data->ratio_init_cam / 5;
	data->cam = set_cam(zero_vector3(), zero_vector3());
	data->cam->position = set_vector3(0, 0 , data->ratio_cam);
//	data->cam->position = set_vector3(0, 0, 0);
	data->cam->target = set_vector3(0, 0, 0);
	mesh = malloc(sizeof(t_mesh));
	data->scene_pos = set_vector3(0, 0, 0);
	data->scene_rot = set_vector3(0, 0, 0);
	data->view_matrix = malloc(sizeof(t_matrix));
	data->projection_matrix= malloc(sizeof(t_matrix));
	data->world_matrix = malloc(sizeof(t_matrix));
	data->transform_matrix = malloc(sizeof(t_matrix));
	data->put_in_canvas = true;

//printf("nbrow : %llu, nbcol : %llu\n",tf->nb_rows, tf->nb_columns);
	min_z = 0;
	max_z = 0;
	for (i = 0; i < tf->nb_rows; i++)
	{
		for (j = 0; j < tf->nb_columns; j++)
		{
			z = tf->tvect[i][j].z;
			if (min_z > z)
				min_z = z;
			if (max_z < z)
				max_z = z;
		}
	}
//printf("Z : min = %le, max = %le\n",min_z,max_z);
	data->coef_elev = -2 / (max_z - min_z);
	data->coef_init_elev = data->coef_elev;
	data->step_elev = data->coef_elev / 10;
	render_fdf(data);
	print_fdf(data);
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
	data->my_meshes = my_meshes;
	my_meshes->m[0] = new_cube("Mon Cube");
	data->cam = set_cam(zero_vector3(), zero_vector3());
	data->cam->position = set_vector3(0, 0 ,10);
	data->cam->target = set_vector3(0, 0 ,0);
	my_meshes->m[0]->rotation.x += 0.01;
	my_meshes->m[0]->rotation.y += 0.01;

//	render(data, arr_mesh);
	drawing_loop(data, my_meshes);
}

int main(int argc, char **argv)
{
	int retour;
	t_data data;

	if (argc != 2)
		return (-1);
	if ((data.mlx_ptr = mlx_init()) == NULL)
	{
		printf("I can't open the display\n");
		return (EXIT_FAILURE);
	}
	data.screen_width = 1024;
	data.screen_height = 768;
	data.canvas_width = data.screen_width - 100 - 1;
	data.canvas_height = data.screen_height - 2;
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
	fdf_bline(&data, data.canvas_width + 1, 0, data.canvas_width + 1, data.screen_height
		- 1, 0x00CFCFCF);
	fdf_bline(&data,data.screen_width - 1, 0, data.screen_width - 1,
		data.screen_height - 1, 0x00CFCFCF);
	fdf_bline(&data, 0, 0, 0, data.screen_height - 1, 0x00CFCFCF);
	fdf_bline(&data, 0, data.screen_height - 1, data.screen_width - 1,
		data.screen_height - 1, 0x00CFCFCF);
//	draw_square(&data, data.canvas_width + 2, 0, data.screen_width - 2, 
//		data.screen_height - 2, 0x00CFCFCF);
	data.put_in_canvas = true;

	data.img[data.back_buffer] = mlx_new_image(data.mlx_ptr, data.canvas_width
		, data.canvas_height);
	data.canvas[data.back_buffer] = (int *) mlx_get_data_addr(
		data.img[data.back_buffer], &data.bpp, &data.sizeline, &data.endian);
	data.img[data.front_buffer] = mlx_new_image(data.mlx_ptr, data.canvas_width
		, data.canvas_height);
	data.canvas[data.front_buffer] = (int *) mlx_get_data_addr(
		data.img[data.front_buffer], &data.bpp, &data.sizeline, &data.endian);

	start_fdf(&data, read_file(argv[1]));
//	print_my_cube(&data);

	switch_buffer(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
		data.img[data.front_buffer], 1, 1);

	if (retour == 1)
		return 0;
	retour = mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}

