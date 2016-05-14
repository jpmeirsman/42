#include "mm_libx.h"

void			switch_buffer(t_data *data)
{
	short		temp;
	int			result;

	temp = data->front_buffer;
	data->front_buffer = data->back_buffer;
	data->back_buffer = temp;
	result = mlx_put_image_to_window (data->mlx_ptr, data->mlx_win,
		data->img[data->front_buffer], 1, 0);
}

int				mlx_pixel_put2(t_data *data, int x, int y, int	 color)
{
	if ((x >= 0) && (y >= 0) && (x < data->canvas_width) && 
		(y< data->canvas_height))
	{
		if (data->anime == true)
			data->canvas[data->back_buffer][y * data->canvas_width + x] = color;
			else
			data->canvas[data->front_buffer][y * data->canvas_width + x] = color;
	}
	return (0);
}
