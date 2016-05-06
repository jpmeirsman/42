#ifndef				MM_GRAPH_H
#define MM_GRAPH_H

#include <math.h>
#include "mm_math.h"
#include "mm_libx.h"
#include "mm_intersects.h"

t_cam				new_cam();
t_cam				*set_cam(t_vector3 pos, t_vector3 target);
//t_device			set_device(t_canvas canvas);
//void				clear_device(t_device *device);
//void				present_device(t_device *device);
//void				put_pixel(t_device *device, long x, long y, t_color4 color);
t_vector2			project_device(t_data *data, t_vector3 coord, t_matrix tMat);
void				draw_point_device(t_data *data, t_vector2 point);
t_mesh				*new_cube(char *name);
void				printcube(t_mesh *my_cube);
//void 			render(t_device device, t_cam camera, t_meshes *meshes);
void			print_buffer(t_data *data);
void 			render(t_data *data, t_meshes *meshes);
void			fdf_bline(t_data *data,int xi,int yi,int xf,int yf, int color);
void draw_square(t_data *data,int xi,int yi,int xf,int yf, int color);
void			print_fdf(t_data *data);

#endif

