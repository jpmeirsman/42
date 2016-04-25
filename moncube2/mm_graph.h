#ifndef				MM_GRAPH_H
#define MM_GRAPH_H

#include <math.h>
#include "mm_math.h"
#include "mm_libx.h"

/*
#define KeyPressMask		(1L<<0)
#define KeyPress			2
#define ButtonPressMask		(1L<<2)
#define ButtonPress			4
#define Button1MotionMask	(1L<<8)
#define ButtonMotionMask	(1L<<13)
#define ButtonReleaseMask	(1L<<3)
#define Button1				1
#define Button2				2
#define Button3				3
#define Button4				4
#define Button5				5
#define ButtonRelease		5
#define PointerMotionMask	(1L<<6)
#define MotionNotify		6


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


typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_display;
	int				screen_width;
	int				screen_height;
	int				*img[2];
	int				*canvas[2];
	short			front_buffer;
	short			back_buffer;
	int				endian;
	int				bpp;
	int				sizeline;
	short			anime;
	int				canvas_width;
	int				canvas_height;
	short			put_in_canvas;
	t_cam			cam;
//	t_canvas		canvas2;
//	t_device		device;

}					data_t;
*/

t_cam				new_cam();
t_cam				set_cam(t_vector3 pos, t_vector3 target);
t_device			set_device(t_canvas canvas);
void				clear_device(t_device *device);
void				present_device(t_device *device);
void				put_pixel(t_device *device, long x, long y, t_color4 color);
t_vector2			project_device(t_device dev, t_vector3 coord, t_matrix tMat);
void				draw_point_device(t_device device, t_vector2 point);
t_mesh				*new_cube(char *name);
void				printcube(t_mesh *my_cube);
void 			render(t_device device, t_cam camera, t_array_mesh *meshes);
void fdf_bline(data_t *data,int xi,int yi,int xf,int yf, int color);
#endif

