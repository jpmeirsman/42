#ifndef				MM_LIBX_H
#define MM_LIBX_H
				
#include "mlx.h"
#include "mm_math.h"

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
	t_vector3			Position;
	t_vector3			Target;
}						t_cam;

typedef struct			s_canvas
{
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


typedef struct			data_s
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
	t_cam				cam;
	//t_canvascanvas2;
	////t_devicedevice;
	//
}						data_t;

void		switch_buffer(data_t *data);
int 		my_key_on_release_funct(int keycode, data_t *data);
int 		my_key_on_maintain_funct(int keycode, data_t *data);
int 		my_key_on_click_funct(int keycode, data_t *data);
int 		my_expose_funct(data_t *data);
int 		my_loop_funct(data_t *data);
int 		my_mouse_on_move_funct(int x, int y, data_t *data);
int 		my_mouse_on_click_funct(int button, int x, int y, data_t *data);
int 		my_mouse_on_release_funct(int button, int x, int y, data_t *data);
int 		mlx_pixel_put2(data_t *data, int x, int y, int	 color);

#endif
