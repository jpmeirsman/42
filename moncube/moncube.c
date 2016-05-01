#include "moncube.h"
#include "mm_libx2.h"

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

void			start_fdf(t_data *data, t_fic *tf)
{
	int			i;
	int			j;
	t_mesh		*mesh;
	double		min_z;
	double		max_z;
//	double		coef_elev;
	double		z;
	double		pi;

	data->tf = tf;
	pi = 3.14159265359;
	if (tf->nb_columns < tf->nb_rows)
		data->ratio_init_cam = tf->nb_rows * -3;
		else
		data->ratio_init_cam = tf->nb_columns * -3;
	data->ratio_cam = data->ratio_init_cam;
	data->step_cam = data->ratio_init_cam / 20;
	data->cam = set_cam(zero_vector3(), zero_vector3());
	data->cam->position = set_vector3(0, 0 , data->ratio_cam);
	data->cam->target = set_vector3(0, 0 , 0);
	mesh = malloc(sizeof(t_mesh));
	mesh->position = set_vector3(0, 0, 0);
	mesh->rotation = set_vector3(-60 / 180 * pi, 0, 0);

	data->view_matrix = malloc(sizeof(t_matrix));
//	*data->view_matrix = look_at_lh_matrix(data->cam->position,
//		data->cam->target, up_vector3());
	data->projection_matrix= malloc(sizeof(t_matrix));
//	*data->projection_matrix = perspective_fov_lh_matrix(0.78,
//		data->canvas_width / data->canvas_height, 0.01, 1);
	data->world_matrix = malloc(sizeof(t_matrix));
//	*data->world_matrix = multiply_matrix(rot_yaw_pitch_roll_matrix(
//		mesh->rotation.y, mesh->rotation.x, mesh->rotation.z),
//		translation_matrix(mesh->position.x, mesh->position.y, 
//		mesh->position.z));
	data->transform_matrix = malloc(sizeof(t_matrix));
//	*data->transform_matrix = multiply_matrix(*data->world_matrix,
//		multiply_matrix(*data->view_matrix, *data->projection_matrix));
	render_fdf(data);
	data->put_in_canvas = true;

	printf("c: %llu, l: %llu\n",tf->nb_columns,tf->nb_rows);
printf("nbrow : %llu, nbcol : %llu\n",tf->nb_rows, tf->nb_columns);
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
printf("Z : min = %le, max = %le\n",min_z,max_z);
	data->coef_elev = 10 / (max_z - min_z);
	data->coef_init_elev = data->coef_elev;
	data->step_elev = data->coef_elev / 20;
	print_fdf(data);
/*
	for (i = 0; i < tf->nb_rows; i++)
	{
		for (j = 0; j < tf->nb_columns; j++)
		{
			if (j < tf->nb_columns - 1)
			{
				tv1 = tf->tvect[i][j];
				tv2 = tf->tvect[i][j+1];
				tv1.z *= data->coef_elev;
				tv2.z *= data->coef_elev;
				pj1 = project_device(data, tv1, *data->transform_matrix);
				pj2 = project_device(data, tv2, *data->transform_matrix);
				fdf_bline(data, pj1.x, pj1.y, pj2.x, pj2.y,0x00FFFFFF);
			}
			if (i < tf->nb_rows - 1)
			{
				tv1 = tf->tvect[i][j];
				tv2 = tf->tvect[i+1][j];
				tv1.z *= data->coef_elev;
				tv2.z *= data->coef_elev;
				pj1 = project_device(data, tv1, *data->transform_matrix);
				pj2 = project_device(data, tv2, *data->transform_matrix);
				fdf_bline(data, pj1.x, pj1.y, pj2.x, pj2.y,0x00FFFFFF);
			}
		}
	}
*/
//printf("tv1.x : %le, tv1.y : %le, tv2.x : %le, tv2.y : %le\n",tv1.x,tv1.y,tv2.x,tv2.y);
}
/*
void		drawing_loop(t_data *data, t_meshes *arr_mesh)
{
//	device.clear; //mise à zero
//	arr_mesh->m[0]->rotation.x += 0.01;
//	arr_mesh->m[0]->rotation.y += 0.01;
	render(data, arr_mesh);
//	device.present(); // affichage du buffer
}
*/
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
//	drawing_loop(data, my_meshes);
}

//int main(void)
int main(int argc, char **argv)
//int win_start()
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

	start_fdf(&data, read_file(argv[1]));
//	print_my_cube(&data);

	switch_buffer(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
		data.img[data.front_buffer], 0, 0);

	if (retour == 1)
		return 0;
	retour = mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}

