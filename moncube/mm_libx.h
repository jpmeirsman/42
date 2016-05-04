#ifndef				MM_LIBX_H
#define MM_LIBX_H
				
#include "mlx.h"
#include "mm_math.h"
//#include "mm_graph.h"

#define KeyPressMask			(1L<<0)
#define KeyPress				2
#define ButtonPRessMask			(1L<<2)
#define ButtonPress				4
#define Button1MotionMask		(1L<<8)
#define ButtonMotionMask		(1L<<13)
#define ButtonReleaseMask		(1L<<3)
#define Button1					1
#define Button2					2
#define Button3					3
#define Button4					4
#define Button5					5
#define ButtonRelease			5
#define PointerMotionMask		(1L<<6)
#define MotionNotify			6

typedef struct			s_cam
{
	t_vector3			position;
	t_vector3			target;
}						t_cam;

/*
typedef struct			s_canvas
{====
	long				width;
	long				height;
	char				*context;
	int					canvaslength;
	int					canvasheight;
}						t_canvas;

typedef struct			s_device
{
	t_canvas			workingCanvas;
	double				workingWidth;
	double				workingHeight;
	char				*workingContext;
}						t_device;

*/
typedef struct			s_fic
{
	long long			nb_rows;
	long long			nb_columns;
	int					**values;
	t_vector3			**tvect;
} t_fic;

typedef struct			s_data
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*mlx_display;
	int					screen_width;
	int					screen_height;
	int					*img[2];
	int					*canvas[2];
	short				front_buffer;
	short				back_buffer;
	int					endian;
	int					bpp;
	int					sizeline;
	short				anime;
	int					canvas_width;
	int					canvas_height;
	short				put_in_canvas;
	t_cam				*cam;
	double				ratio_init_cam;
	double				ratio_cam;
	double				step_cam;
	double				coef_elev;
	double				coef_init_elev;
	double				step_elev;
	t_meshes			*my_meshes;
	t_matrix			*view_matrix;
	t_matrix			*projection_matrix;
	t_matrix			*world_matrix;
	t_matrix			*transform_matrix;
	t_fic				*tf;
	t_vector3			scene_pos;
	t_vector3			scene_rot;
//t_canvascanvas2;
	////t_devicedevice;
	//
}						t_data;

//void		drawing_loop(t_data *data, t_meshes *arr_mesh);
void		switch_buffer(t_data *data);
/*
int 		my_key_on_release_funct(int keycode, t_data *data);
int 		my_key_on_maintain_funct(int keycode, t_data *data);
int 		my_key_on_click_funct(int keycode, t_data *data);

*/
//int 		my_expose_funct(t_data *data);
//int 		my_loop_funct(t_data *data);
int 		my_mouse_on_move_funct(int x, int y, t_data *data);
int 		my_mouse_on_click_funct(int button, int x, int y, t_data *data);
int 		my_mouse_on_release_funct(int button, int x, int y, t_data *data);
int 		mlx_pixel_put2(t_data *data, int x, int y, int	 color);

#endif
