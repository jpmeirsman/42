#include "mm_graph.h"

t_cam				new_cam()
{
	t_cam			result;

	result.position = zero_vector3();
	result.target = zero_vector3();
	return (result);
}

t_cam				*set_cam(t_vector3 pos, t_vector3 target)
{
	t_cam			*camera;

	camera = malloc(sizeof(t_cam));
	camera->position.x = pos.x;
	camera->position.y = pos.y;
	camera->position.z = pos.z;
	camera->target.x = target.x;
	camera->target.y = target.y;
	camera->target.z = target.z;
	return (camera);
}

//t_vector2			project_device(t_device dev, t_vector3 coord, t_matrix tMat)
t_vector2			project_device(t_data *data, t_vector3 coord, t_matrix tMat)
{
	t_vector3		point;
	double			x;
	double			y;

	point = transform_coord_vector3(coord, tMat);
	//	x = round((point.x * device.workingWidth) + (device.workingWidth / 2.0)) >> 0;
	x = round((point.x * data->canvas_width) + (data->canvas_width / 2.0));
	y = round((point.y * data->canvas_height) + (data->canvas_height / 2.0));
//printf("x: %lf, y: %lf///\n",x,y);
	return (new_vector2(x, y));
}

void				draw_point_device(t_data *data, t_vector2 point)
{
	int			color;
	t_color4	color4;

	color4 = new_color4(0, 0xFF,0xFF, 0xFF);
	color = (((color4.a * 0xFF + color4.r) * 0xFF + color4.g) * 0xFF) 
		+ color4.b;
	if(point.x >= 0 && point.y >= 0 && point.x < data->canvas_width && point.y 
		< data->canvas_height) {
		mlx_pixel_put2(data, point.x, point.y, color);
	}
}

t_mesh				*new_cube(char *name)
{
	t_mesh			*my_cube;

	my_cube = new_mesh(name, 8, 12);
	my_cube->vertices[0] = set_vector3(-1,  1,  1);
	my_cube->vertices[1] = set_vector3( 1,  1,  1);
	my_cube->vertices[2] = set_vector3(-1, -1,  1);
	my_cube->vertices[3] = set_vector3( 1, -1,  1);
	my_cube->vertices[4] = set_vector3(-1,  1, -1);
	my_cube->vertices[5] = set_vector3( 1,  1, -1);
	my_cube->vertices[6] = set_vector3( 1, -1, -1);
	my_cube->vertices[7] = set_vector3(-1, -1, -1);
	my_cube->nb_vertices = 8;
	put_face(&my_cube->faces[0],  0, 1, 2);
	put_face(&my_cube->faces[1],  1, 2, 3);
	put_face(&my_cube->faces[2],  1, 3, 6);
	put_face(&my_cube->faces[3],  1, 5, 6);
	put_face(&my_cube->faces[4],  0, 1, 4);
	put_face(&my_cube->faces[5],  1, 4, 5);
	put_face(&my_cube->faces[6],  2, 3, 7);
	put_face(&my_cube->faces[7],  3, 6, 7);
	put_face(&my_cube->faces[8],  0, 2, 7);
	put_face(&my_cube->faces[9],  0, 4, 7);
	put_face(&my_cube->faces[10], 4, 5, 6);
	put_face(&my_cube->faces[11], 4, 6, 7);
	my_cube->nb_faces = 12;
	return my_cube;
}

void				printcube(t_mesh *my_cube)
{
	printf("Nom du cube : %s\n",my_cube->name);
	for(int i = 0 ; i < 8; i++)
		printf("Vertex n° %d : x=%f, y=%f, z=%f\n",i,my_cube->vertices[i].x,
				my_cube->vertices[i].y,my_cube->vertices[i].z);
	for(int i = 0 ; i < 12; i++)
		printf("Face n° %d : A=%d, B=%d, C=%d\n",i,my_cube->faces[i].a,
				my_cube->faces[i].b,my_cube->faces[i].c);
}

void 			render(t_data *data)
{
	t_matrix	viewMatrix;
	t_matrix	projectionMatrix;
	t_matrix	worldMatrix;
	t_matrix	transformMatrix;
	long long	index;
	long long	indexvertices;
	long long	indexfaces;
	t_mesh		*cMesh;
	t_vector2	projectedPoint;
	t_vector2	*tv;

	viewMatrix = look_at_lh_matrix(data->cam->position, data->cam->target, 
		up_vector3());
	projectionMatrix = perspective_fov_lh_matrix(0.78, 
		data->canvas_width / data->canvas_height, 0.01, 1);
	for (index = 0; index < data->my_meshes->length; index++)
	{
		cMesh = data->my_meshes->m[index];
		tv = malloc(sizeof(t_vector2) * cMesh->nb_vertices);
		worldMatrix = multiply_matrix(rot_yaw_pitch_roll_matrix(
			cMesh->rotation.y, cMesh->rotation.x, cMesh->rotation.z),
			translation_matrix(cMesh->position.x, cMesh->position.y, 
			cMesh->position.z));
			transformMatrix = multiply_matrix(worldMatrix,multiply_matrix(
				viewMatrix,projectionMatrix));
		for (indexvertices = 0; indexvertices < cMesh->nb_vertices; indexvertices++)
		{
			projectedPoint = project_device(data, 
				cMesh->vertices[indexvertices], transformMatrix);
//			draw_point_device (data, projectedPoint);
			tv[indexvertices] = projectedPoint;
		}
/*
		fdf_bline(data, tv[0].x, tv[0]. y,tv[1].x, tv[1].y, 0x00FFFFFF);
		fdf_bline(data, tv[1].x, tv[1]. y,tv[3].x, tv[3].y, 0x00FFFFFF);
		fdf_bline(data, tv[3].x, tv[3]. y,tv[2].x, tv[2].y, 0x00FFFFFF);
		fdf_bline(data, tv[2].x, tv[2]. y,tv[0].x, tv[0].y, 0x00FFFFFF);
		fdf_bline(data, tv[4].x, tv[4]. y,tv[5].x, tv[5].y, 0x00FFFFFF);
		fdf_bline(data, tv[5].x, tv[5]. y,tv[6].x, tv[6].y, 0x00FFFFFF);
		fdf_bline(data, tv[6].x, tv[6]. y,tv[7].x, tv[7].y, 0x00FFFFFF);
		fdf_bline(data, tv[7].x, tv[7]. y,tv[4].x, tv[4].y, 0x00FFFFFF);
		fdf_bline(data, tv[0].x, tv[0]. y,tv[4].x, tv[4].y, 0x00FFFFFF);
		fdf_bline(data, tv[1].x, tv[1]. y,tv[5].x, tv[5].y, 0x00FFFFFF);
		fdf_bline(data, tv[2].x, tv[2]. y,tv[7].x, tv[7].y, 0x00FFFFFF);
		fdf_bline(data, tv[3].x, tv[3]. y,tv[6].x, tv[6].y, 0x00FFFFFF);
*/

		for (indexfaces = 0; indexfaces < cMesh->nb_faces; indexfaces++)
		{
			fdf_bline(data,
				tv[cMesh->faces[indexfaces].a].x,
				tv[cMesh->faces[indexfaces].a].y,
				tv[cMesh->faces[indexfaces].b].x,
				tv[cMesh->faces[indexfaces].b].y, 0x00FFFFFF);
			fdf_bline(data,
				tv[cMesh->faces[indexfaces].b].x,
				tv[cMesh->faces[indexfaces].b].y,
				tv[cMesh->faces[indexfaces].c].x,
				tv[cMesh->faces[indexfaces].c].y, 0x00FFFFFF);
			fdf_bline(data,
				tv[cMesh->faces[indexfaces].c].x,
				tv[cMesh->faces[indexfaces].c].y,
				tv[cMesh->faces[indexfaces].a].x,
				tv[cMesh->faces[indexfaces].a].y, 0x00FFFFFF);
			
		}
	}
}

void fdf_bline(t_data *data,int xi,int yi,int xf,int yf, int color)
{
	double				dx;
	double				dy;
	double				sx;
	double				sy;
	double				err;
	double				e2;

	dx = abs(xf - xi);
	dy = abs(yf - yi);
	sx = (xi < xf) ? 1 : -1;
	sy = (yi < yf) ? 1 : -1;
	err = dx - dy;			
	while (true)
	{
		if (data->put_in_canvas)
			mlx_pixel_put2(data, xi, yi, color);
		else
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, xi, yi, color);
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

int				compute_color(t_data *data, double altitude)
{
	t_color4	start_color;
	t_color4	end_color;
	t_color4	final_color;
	int			color;
	double		proportion;
	double		diff_range;
	double		max_diff_range;

	int			i;
//	t_palette	*pal;

//	data->nb_palette = 2;
//	data->palette = malloc(sizeof(t_palette) * data->nb_palette);
//	data->palette[0].start_color = new_color4(0, 0x40, 0, 0);
//	data->palette[0].end_color = new_color4(0, 0x8F, 0, 0);
//	data->palette[0].start_range = 0;
//	data->palette[0].end_range = 0.333;
//	data->palette[1].start_color = new_color4(0, 0x8F, 0, 0);
//	data->palette[1].end_color = new_color4(0, 0x00, 0xFF, 0);
//	data->palette[1].start_range = 0.333;
//	data->palette[1].end_range = 2;
//	data->palette[2].start_color = new_color4(99, 59, 0xFF, 0);
//	data->palette[2].end_color = new_color4(0xFF, 0xFF, 0xFF, 0);
//	data->palette[2].start_range = 0.666;
//	data->palette[2].end_range = 1;

	max_diff_range = data->palette[data->nb_palette - 1].end_range - 
		data->palette[0].start_range;
	i = 0;
	while (i < data->nb_palette)
	{
		data->palette[i].start_range /= max_diff_range;
		data->palette[i].end_range /= max_diff_range;
		i++;
	}
	color = data->endian;
	proportion = (altitude - data->tf->min_elev) / (data->tf->max_elev - 
		data->tf->min_elev);

	i = 0;
	while (i < data->nb_palette)
	{
		if ((proportion >= data->palette[i].start_range) && 
			(proportion <= data->palette[i].end_range))
			break;
		i++;
	}
//	if (i == data->nb_palette) 
//		i = 0;

//	start_color = new_color4(0x40,0x40, 0x40, 0x00);
//	end_color = new_color4(0xFF, 0xFF, 0xFF, 0x00);
	start_color = data->palette[i].start_color;
	end_color = data->palette[i].end_color;;
	diff_range = data->palette[i].end_range - data->palette[i].start_range;
	proportion = (proportion - data->palette[i].start_range) / diff_range;

	final_color.r = start_color.r + (proportion * (end_color.r - start_color.r));
	final_color.g = start_color.g + (proportion * (end_color.g - start_color.g));
	final_color.b = start_color.b + (proportion * (end_color.b - start_color.b));
	final_color.a = 0x00;//start_color.a + (proportion * end_color.a);
	color = (((((final_color.a * 256) + final_color.r) * 256) + 
		final_color.g) * 256) + final_color.b;
//printf("p:%le %d == %x %x %x %x\n",proportion, i, final_color.r, final_color.g, final_color.b,final_color.a);
	return (color);
}

void fdf_bline_color(t_data *data,int xi,int yi,int xf,int yf,
	double altitude1, double altitude2)
{
	double				dx;
	double				dy;
	double				sx;
	double				sy;
	double				err;
	double				e2;
	double				altitude;
//	double				diff_alt;
	double				len_segment;
	double				len_progress;
	int					save_xi;
	int					save_yi;
	double				proportion;

//printf("DEBUT\n");
	save_xi = xi;
	save_yi = yi;
	dx = abs(xf - xi);
	dy = abs(yf - yi);
	sx = (xi < xf) ? 1 : -1;
	sy = (yi < yf) ? 1 : -1;
	err = dx - dy;
	len_segment = sqrt(pow((xf - xi),2) + pow((yf - yi),2));
	while (true)
	{
		len_progress = sqrt(pow((save_xi - xi),2) + pow((save_yi - yi),2));
		proportion = len_progress / len_segment;
		altitude = altitude1 + (altitude2 - altitude1) * proportion;

//printf("ALT : %le %le %le %le\n",altitude, proportion, altitude1, altitude2);

		if (data->put_in_canvas)
			mlx_pixel_put2(data, xi, yi, compute_color(data, altitude));
		else
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, xi, yi,
				compute_color(data, altitude));
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

void draw_square(t_data *data,int xi,int yi,int xf,int yf, int color)
{
	int			i;
	int			j;

	i = xi;
	while (i <= xf)
	{
		j = yi;
		while (j <= yf)
		{
			if (data->put_in_canvas)
				mlx_pixel_put2(data, i, j, color);
			else
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, i, j, color);
			j++;
		}
		i++;
	}
}

void			print_buffer(t_data *data)
{
	int			result;

	result = mlx_put_image_to_window (data->mlx_ptr, data->mlx_win,
		data->img[data->front_buffer], 1, 0);
}

int			clip_v2(t_data *data, t_vector2 *pj1, t_vector2 *pj2)
{
	short		pj1_in_canvas;
	short		pj2_in_canvas;
	int			result[4];
	t_vector2	intersect1;
	t_vector2	intersect2;
	short		nb_intersect;
	t_vector2	array_inters[8];
	int			i;

	if (((pj1->x >= 0) && (pj1->x <= data->canvas_width)) &&
	   ((pj1->y >= 0) && (pj1->y <= data->canvas_height)))
		pj1_in_canvas = 1;
		else
		pj1_in_canvas = 0;
	if (((pj2->x >= 0) && (pj2->x <= data->canvas_width)) &&
	   ((pj2->y >= 0) && (pj2->y <= data->canvas_height)))
		pj2_in_canvas = 1;
		else
		pj2_in_canvas = 0;
	if (pj1_in_canvas && pj2_in_canvas)
		return (1);

	result[0] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y, 0, 0,
		data->canvas_width, 0,  &array_inters[0].x, &array_inters[0].y);
	result[1] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y,
		data->canvas_width, 0, data->canvas_width, data->canvas_height,
		&array_inters[1].x, &array_inters[1].y);
	result[2] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y,
		data->canvas_width, data->canvas_height, 0, data->canvas_height,
		&array_inters[2].x, &array_inters[2].y);
	result[3] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y,
		0, data->canvas_height, 0, 0, &array_inters[3].x, &array_inters[3].y);
	nb_intersect = 0;
	i = 0;
	while (i <= 3)
	{
		if (result[i] == do_intersect)
		{
			if (nb_intersect == 0)
				intersect1 = array_inters[i];
				else
				intersect2 = array_inters[i];
			nb_intersect++;
		}
		i++;
	}
	if (nb_intersect == 2)
	{
		*pj1 = intersect1;
		*pj2 = intersect2;
		return (1);
	}
	else
	if (nb_intersect == 1)
	{
		if (pj1_in_canvas)
		{
			*pj2 = intersect1;
		}
		else
		{
			*pj1 = intersect1;
		}
		return (1);
	}
	return (0);
}

void			print_fdf2(t_data *data)
{
	int			i;
	int			j;
	t_vector3	tv1;
//	t_vector2	pj1;
	char		*s;

	printf("Table des vecteurs\n");
	for (i = 0; i < data->tf->nb_rows; i++)
	{
		for (j = 0; j < data->tf->nb_columns; j++)
		{
			tv1 = data->tf->tvect[i][j];
			s = dtoa(tv1.x, 2);
			printf("(%s ", s);
			s = dtoa(tv1.y, 2);
			printf("%s ", s);
			s = dtoa(tv1.z * data->coef_elev, 2);
			printf("%s)\t", s);
//			pj1 = project_device(data, tv1, *data->transform_matrix);
		}
		printf("\n");
	}
	printf("\n");
}

void			print_fdf(t_data *data)
{
	int			i;
	int			j;
	t_vector3	tv1;
	t_vector3	tv2;
	t_vector2	pj1;
	t_vector2	pj2;

//print_fdf2(data);
	for (i = 0; i < data->tf->nb_rows; i++)
	{
		for (j = 0; j < data->tf->nb_columns; j++)
		{
			if (j < data->tf->nb_columns - 1)
			{
				tv1 = data->tf->tvect[i][j];
				tv2 = data->tf->tvect[i][j+1];
				tv1.z *= data->coef_elev;
				tv2.z *= data->coef_elev;
				pj1 = project_device(data, tv1, *data->transform_matrix);
				pj2 = project_device(data, tv2, *data->transform_matrix);
				tv1.z /= data->coef_elev;
				tv2.z /= data->coef_elev;
				if ((clip_v2(data, &pj1, &pj2))
					&& ((data->cam->position.z >= data->scene_pos.z + tv1.z
					&& (data->cam->position.z >= data->scene_pos.z + tv2.z))))
				{
//					printf("i:%d j:%d %le %le %le %le\n", i, j, pj1.x, pj1.y, pj2.x, pj2.y);
//					printf("coef elev %le %le \n", tv1.z, tv2.z);
//					fdf_bline(data, pj1.x, pj1.y, pj2.x, pj2.y,0x00FFFFFF);
					fdf_bline_color(data, pj1.x, pj1.y, pj2.x, pj2.y,
						data->tf->tvect[i][j].z, data->tf->tvect[i][j+1].z);
				}
			}
			if (i < data->tf->nb_rows - 1)
			{
				tv1 = data->tf->tvect[i][j];
				tv2 = data->tf->tvect[i+1][j];
				tv1.z *= data->coef_elev;
				tv2.z *= data->coef_elev;
				pj1 = project_device(data, tv1, *data->transform_matrix);
				pj2 = project_device(data, tv2, *data->transform_matrix);
				tv1.z /= data->coef_elev;
				tv2.z /= data->coef_elev;
				if ((clip_v2(data, &pj1, &pj2))
					&& ((data->cam->position.z >= data->scene_pos.z + tv1.z
					&& (data->cam->position.z >= data->scene_pos.z + tv2.z))))
				{
//					printf("i:%d j:%d %le %le %le %le\n", i, j, pj1.x, pj1.y, pj2.x, pj2.y);
//					printf("coef elev %le %le \n", tv1.z, tv2.z);
//					fdf_bline(data, pj1.x, pj1.y, pj2.x, pj2.y,0x00FFFFFF);
					fdf_bline_color(data, pj1.x, pj1.y, pj2.x, pj2.y,
						data->tf->tvect[i][j].z, data->tf->tvect[i+1][j].z);
				}
			}
		}
	}
	printf("toto\n");
}

void			render_fdf(t_data *data)
{
	*data->view_matrix = look_at_lh_matrix(data->cam->position,
		data->cam->target, up_vector3());
	*data->projection_matrix = perspective_fov_lh_matrix(0.78,
		data->canvas_width / data->canvas_height, 0.01, 1);
	*data->world_matrix = multiply_matrix(rot_yaw_pitch_roll_matrix(
		data->scene_rot.y, data->scene_rot.x, data->scene_rot.z),
	translation_matrix(data->scene_pos.x, data->scene_pos.y, 
		data->scene_pos.z));
	*data->transform_matrix = multiply_matrix(*data->world_matrix,
		multiply_matrix(*data->view_matrix, *data->projection_matrix));
}
