#include <mlx.h>
#include <stdio.h>

int       main()
{
  void  *mlx_init();
  int   bpp;
  int   sizeline;
  int   endian;
  int   *img;
  int   *data;
  void  *mlx_ptr;
  void  *win_ptr;
  int   pixel_nbr;

  pixel_nbr = 0;
  mlx_ptr = mlx_init();
  img = mlx_new_image(mlx_ptr, 300, 300);
  data = (int *) mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  printf("%d, %d, %d\n", bpp, sizeline, endian);
  while (pixel_nbr < 90000)
    {
      data[pixel_nbr] = 0x000000FF;
      pixel_nbr++;
    }
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Fenetre de Astaroth");
  mlx_put_image_to_window(mlx_ptr, win_ptr, img, 100, 100);
  mlx_loop(mlx_ptr);
}
