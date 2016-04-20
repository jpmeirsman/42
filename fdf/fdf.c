#include "fdf.h"
//#include "readmap.c"

#define KeyPressMask		(1L<<0)
#define KeyPress			2
#define ButtonPressMask		(1L<<2)
#define ButtonPress			4
#define Button1MotionMask	(1L<<8)
#define ButtonMotionMask	(1L<<13)
#define Button1				1
#define Button2				2
#define Button3				3
#define Button4				4
#define Button5				5
#define PointerMotionMask	(1L<<6)
#define MotionNotify		6

void		switch_buffer(data_t *data)
{
	short		temp;
	int			result;

printf("fb: %d, bb: %d\n", data->front_buffer, data->back_buffer);
	temp = data->front_buffer;
	data->front_buffer = data->back_buffer;
	data->back_buffer = temp;
	result = mlx_put_image_to_window (data->mlx_ptr, data->mlx_win, data->canvas[data->front_buffer], 0, 0);
}

int my_key_funct(int keycode, data_t *data)
{
	int retour;

	retour = mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 100, 30, 0x00FFFFFF);
	printf("%i\n",keycode);
printf("pointeur: %p\n",data->canvas[data->front_buffer]);
	switch_buffer(data);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr,data->mlx_win);
		printf("Fin du programme\n");
		exit(0);
	}
	return (0);
}

int mouvement(int keycode, data_t *data)
{
	int retour;

//	printf("*****%i\n",keycode);
	return (0);
}

int my_expose_funct(data_t *data)
{
// cette fonction est appelée lorsque l'on replie la fenêtre puis
// lorsque l'on la réactive et que l'on génère un évènement clavier 
// ou souris sur mac sinon osx gère corrextement cela pour nous.
	printf("*");
	return (0);
}

int my_loop_funct(data_t *data)
{
//	mlx_pixel_put(data->mlx_ptr ,data->mlx_win, 300, 300, 0x00FF00FF);
//	printf("*%llu",compteur);
//	compteur++;
	return (0);
}

int mouse(int button, int x, int y, data_t *data)
{
	printf("Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}

int my_mouse_funct(int button, int x, int y, data_t *data)
{
//	printf("Button: %d x: %d y: %d\n",button, x ,y);
	return (0);
}

void printarr(data_t *data)
{
int i,j,k,*b;

b=data->canvas[data->front_buffer];
i=0;
for (i=0;i<10;i++)
{
	for(j=0;j<10;j++)
	{
		k=b[i*10+j];
		printf("%x-",k);
	}
	printf("\n");
}
}

int main(void)
{
	int retour;
	int retour2;
	data_t data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
	{
		printf("I can't open the display\n");
		return (EXIT_FAILURE);
	}
	data.screen_width = 10;
	data.screen_height = 10;
	data.back_buffer = 1;
	data.front_buffer = 0;
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.screen_width, data.screen_height, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	retour = mlx_key_hook(data.mlx_win, my_key_funct, &data);
	retour = mlx_loop_hook(data.mlx_ptr, my_loop_funct, &data);
	retour = mlx_mouse_hook(data.mlx_win,my_mouse_funct, &data);
	retour = mlx_expose_hook(data.mlx_win, my_expose_funct, &data);
	fdf_line(&data,1,1,300,300,0x00FF00FF);
	data.canvas[data.front_buffer] = mlx_new_image(data.mlx_ptr, data.screen_width, data.screen_height);
//	fdf_line(&data,1,1,300,300,0x00FF00FF);
	fdf_bline(&data,0,0,9,9,0x00FF00FF);
	data.canvas[data.back_buffer] = mlx_new_image(data.mlx_ptr, data.screen_width, data.screen_height);

printarr(&data);
return 0;





	mlx_string_put(data.mlx_ptr, data.mlx_win, 30, 30, 0X00FFFFFF, "Coucou");
	if (retour == 1)
		return 0;
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, mouvement, &data);
	mlx_hook(data.mlx_win, MotionNotify, PointerMotionMask, mouse, &data);
	retour = mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
