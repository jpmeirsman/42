#ifndef LIBFDF_H
#define LIBFDF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"
#include "get_next_line.h"
#include "readmap.h"
//#include "mlibxtools.c"

#define true						1
#define false						0

#define KeyPressMask				(1L<<0)
#define KeyPress					2
#define ButtonPressMask				(1L<<2)
#define ButtonPress					4
#define Button1MotionMask			(1L<<8)
#define ButtonMotionMask			(1L<<13)
#define ButtonReleaseMask			(1L<<3)
#define Button1						1
#define Button2						2
#define Button3						3
#define Button4						4
#define Button5						5
#define ButtonRelease				5
#define PointerMotionMask			(1L<<6)
#define MotionNotify				6

typedef short boolean;

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
	boolean			anime;
	int				canvas_width;
	int				canvas_height;
	boolean			put_in_canvas;
} data_t;

void		fdf_line(data_t *data,int xi,int yi,int xf,int yf, int color);
void		fdf_bline(data_t *data,int xi,int yi,int xf,int yf, int color);
void		switch_buffer(data_t *data);
int			my_key_on_release_funct(int keycode, data_t *data);
int			my_key_on_maintain_funct(int keycode, data_t *data);
int 		my_expose_funct(data_t *data);
int 		my_loop_funct(data_t *data);
int 		my_mouse_on_move_funct(int x, int y, data_t *data);
int 		my_mouse_on_click_funct(int button, int x, int y, data_t *data);
int 		my_mouse_on_release_funct(int button, int x, int y, data_t *data);
int 		mlx_pixel_put2(data_t *data, int x, int y, int color);

int			**createTable(int nbRow, int nbCol);
void		printMap(List *myList, tfic *tf);
void		createMap(List *myList, tfic *tf);
void		chargeMap(List *myList, tfic *tf, int fd);


#endif
