#ifndef				MM_LIBX2_H
#define MM_LIBX2_H
				
#include "mlx.h"
#include "mm_math.h"
#include "mm_libx.h"
#include "libft2.h"
#include "mm_graph.h"

void		print_menu(t_data *data);
void		print_info(t_data *data);
void		drawing_loop(t_data *data);
/*
void		switch_buffer(t_data *data);
*/
int 		my_key_on_release_funct(int keycode, t_data *data);
int 		my_key_on_maintain_funct(int keycode, t_data *data);
int 		my_key_on_click_funct(int keycode, t_data *data);
int 		my_expose_funct(t_data *data);

int 		my_loop_funct(t_data *data);
int 		my_mouse_on_move_funct(int x, int y, t_data *data);
int 		my_mouse_on_click_funct(int button, int x, int y, t_data *data);
int 		my_mouse_on_release_funct(int button, int x, int y, t_data *data);
/*int 		mlx_pixel_put2(t_data *data, int x, int y, int	 color);
*/
void		render_fdf(t_data *data);

#endif
