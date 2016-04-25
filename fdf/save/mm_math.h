#ifndef				MM_MATH_H
#define MM_MATH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "itoa.c"
#include "math.c"
#include "ftoa.c"

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef struct		s_vector2
{
	double			x;
	double			y;
}					t_vector2;

typedef struct		s_face
{
	double			a;
	double			b;
	double			c;
}					t_face;

typedef struct		s_matrix
{
	double			m[16];
}					t_matrix;

typedef struct		s_mesh
{
	char			*name;
	t_vector3		*vertices;
	t_face			*faces;
	t_vector3		Rotation;
	t_vector3		Position;
	long long		length;
}					t_mesh;

typedef struct		s_array_mesh
{
	long long		length;
	t_mesh			*m;
}					t_array_mesh;

typedef struct		s_cam
{
	t_vector3		Position;
	t_vector3		Target;
}					t_cam;

typedef struct		s_canvas
{
	long			width;
	long			height;
	char			*context;
	int				canvaslength;
	int				canvasheight;
}					t_canvas;

typedef struct		s_device
{
	t_canvas		workingCanvas;
	double			workingWidth;
	double			workingHeight;
	char			*workingContext;
}					t_device;

typedef struct		s_color4
{
	short			r;
	short			g;
	short			b;
	short			a;
}					t_color4;

t_color4			new_color4(short r, short g, short b, short a);
char				*color4_to_string(t_color4 tc);
t_vector2			new_vector2(double x, double y);
char				*vector2_to_string(t_vector2 tv);
t_vector2			add_vector2(t_vector2 myvector, t_vector2 other);
t_vector2			subtract_vector2(t_vector2 myvector, t_vector2 other);
t_vector2			negate_vector2(t_vector2 myvector);
t_vector2			scale_vector2(t_vector2 myvector, double scale);
bool				equals_vector2(t_vector2 myvector, t_vector2 other);
double				length_vector2(t_vector2 myvector);
double				len_squared_vector2(t_vector2 myvector);
t_vector2			normalize_vector2(t_vector2 myvector);
t_vector2			zero_vector2();
t_vector2			copy_vector2(t_vector2 source);
t_vector2			normalize2_vector2(t_vector2 source);
t_vector2			minimize_vector2(t_vector2 left, t_vector2 right);
t_vector2			maximize_vector2(t_vector2 left, t_vector2 right);
t_vector2			transform_vector2(t_vector2 vector, t_matrix transform);
double				dist_squared_vector2(t_vector2 value1, t_vector2 value2);
double				dist_vector2(t_vector2 value1, t_vector2 value2);
char				*vector3_to_string(t_vector3 tv);
t_vector3			add_vector3(t_vector3 myvector, t_vector3 other);
t_vector3			subtract_vector3(t_vector3 myvector, t_vector3 other);
t_vector3			negate_vector3(t_vector3 myvector);
t_vector3			scale_vector3(t_vector3 myvector, double scale);
bool				equals_vector3(t_vector3 myvector, t_vector3 other);
t_vector3			multiply_vector3(t_vector3 myvector, t_vector3 other);
t_vector3			divide_vector3(t_vector3 myvector, t_vector3 other);
double				length_vector3(t_vector3 myvector);
double				len_squared_vector3(t_vector3 myvector);
t_vector3			normalize_vector3(t_vector3 myvector);
t_vector3			from_array_vector3(double *array, long offset);
t_vector3			set_vector3(double X, double Y, double Z);
t_vector3			zero_vector3();
t_vector3			up_vector3();
t_vector3			copy_vector3(t_vector3 source);
t_vector3			transform_coord_vector3(t_vector3 vect, t_matrix t);
t_vector3			transform_normal_vector3(t_vector3 vector, t_matrix t);
double				dot_vector3(t_vector3 left, t_vector3 right);
t_vector3			cross_vector3(t_vector3 left, t_vector3 right);
t_vector3			normalize2_vector3(t_vector3 vector);
double				dist_squared_vector3(t_vector3 value1, t_vector3 value2);
double				dist_vector3(t_vector3 value1, t_vector3 value2);
void				put_face(t_face *face, double a, double b, double c);
t_cam				new_cam();
t_cam				set_cam(t_vector3 pos, t_vector3 target);
t_mesh				*new_mesh(char *name, long long vertCount, long long nbface);
t_device			set_device(t_canvas canvas);
void				clear_device(t_device *device);
void				present_device(t_device *device);
void				put_pixel(t_device *device, long x, long y, t_color4 color);
t_vector2			project_device(t_device dev, t_vector3 coord, t_matrix tMat);
void				draw_point_device(t_device device, t_vector2 point);
t_mesh				*new_cube(char *name);
void				printcube(t_mesh *my_cube);
bool				matrix_is_identity(t_matrix matrix);
double				determinant_matrix(t_matrix matrix);
t_matrix			to_array_matrix(t_matrix matrix);
t_matrix			multiply_matrix(t_matrix matrix, t_matrix other);
int				equals_matrix(t_matrix value, t_matrix matrix);
t_matrix		from_values_matrix(double initialM11, double initialM12,
				double initialM13, double initialM14, double initialM21,
				double initialM22, double initialM23, double initialM24,
				double initialM31, double initialM32, double initialM33,
				double initialM34, double initialM41, double initialM42,
				double initialM43, double initialM44);
t_matrix		identity_matrix();
t_matrix		zero_matrix();
t_matrix		copy_matrix(t_matrix source);
t_matrix		rot_x_matrix(double angle);
t_matrix		rot_y_matrix(double angle);
t_matrix		rot_z_matrix(double angle);
t_matrix		rot_axis_matatrix(t_vector3 axis, double angle);
t_matrix		rot_yaw_pitch_roll_matrix(double y, double p, double r);
t_matrix		scaling_matrix(double x, double y, double z);
t_matrix		translation_matrix(double x, double y, double z);
t_matrix		look_at_lh_matrix(t_vector3 eye, t_vector3 targt, t_vector3 up);
t_matrix		perspective_lh_matrix(double width, double height,
				double znear, double zfar);
t_matrix		perspective_fov_lh_matrix(double fov, double aspect, double znear, double zfar);
t_matrix		transpose_matrix(t_matrix matrix);
void 			render(t_device device, t_cam camera, t_array_mesh *meshes);

#endif

