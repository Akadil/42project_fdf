/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:45:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/22 16:46:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"

/*int main(void)
{
    void    *mlx;
    //void    *mlx_wind;
    void    *mlx_img;

    mlx = mlx_init(); // Unprotected
    mlx_img = mlx_new_image(mlx, 1920, 1080);
    //mlx_wind = mlx_new_window(mlx, 1920, 1080, "hello world!"); // Unprotected 
    //mlx_loop(mlx);

    return (0);
}*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

	printf("---------------%d %d %d %d --------------\n", x0, x1, y0, y1);
    while (x0 != x1 || y0 != y1) {
		//printf("I was here %d %d\n", x0, y0);
        my_mlx_pixel_put(img, x0, y0, 0x00FF00);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    my_mlx_pixel_put(img, x0, y0, 0x00FF00);
}

int *ft_apply_matrix(t_data *img, int x, int y, int z, int alpha, int beta)
{
	int	returner[2];
	float	alpha_rad;
	float	beta_rad;
	float	pi;

	pi = 3.142857;
	alpha_rad = alpha * (pi / 180.0);
	beta_rad = beta * (pi / 180.0);

    returner[0] = x * cos(alpha_rad) - z * sin(beta_rad);
	returner[1] = x * sin(alpha_rad) * sin(beta_rad) + y * cos(alpha_rad) + z * sin (alpha_rad) * cos (beta_rad);
	//my_mlx_pixel_put(img, new_x, new_y, 0x00FF00);
	return (returner);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int x;
	int y;
	// int a;
	// int b;
	// int c;
	// int	d;
	// {0, 200, 200, 0}
	int	matrix[4][4] = {{0, 0, 0, 0}, {0, 10, 10, 0}, {0, 10, 10, 0}, {0, 0, 0, 0}};
	// int	matrix[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	float cos;
	float sin;

	sin = 1 / 2;
	cos = sqrt(3) / 2;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			ft_apply_matrix(&img, x * 100 + 500, y * 100, matrix[x][y], 30, 45);
			if (y != 3)
			// (x * 100 + 500 - y * 100) * sqrt(3) / 2,
			// -1 * matrix[x][y] + (x * 100 + 500 + y * 100) / 2
				draw_line(&img, (x * 100 + 500 - y * 100) * cos, -1 * matrix[x][y] + (x * 100 + 500 + y * 100) * sin, 
								(x * 100 + 500 - (y + 1) * 100) * cos, -1 * matrix[x][y + 1] + (x * 100 + 500 + (y + 1) * 100) * sin);
			if (x != 3)
				draw_line(&img, (x * 100 + 500 - y * 100) * cos, -1 * matrix[x][y] + (x * 100 + 500 + y * 100) * sin, 
								((x + 1) * 100 + 500 - y * 100) * cos, -1 * matrix[x + 1][y] + ((x + 1) * 100 + 500 + y * 100) * sin);
			y++;
		}
		x++;
	}

	// x = 0;
    // while (x < 1920)
    // {
	// 	y = 0;
	// 	while (y < 1080)
	// 	{
	// 		if (pow((x - 100), 2) + pow((y - 100), 2) < 10000) // For making a circle
	// 		// if (x == 0 || y == 0 || x == 1919 || y == 1079) // draw a rectangle
	// 		{
	// 			a = x * sqrt(3) / 2 + y * 1 / 2;
	// 			b = -1 * 1 / 2 * x + y * sqrt(3) / 2;
	// 			/*
	// 			x' = (x - y) * cos(30°)
	// 			y' = -z + (x + y) * sin(30°)
	// 			*/
	// 			c = (x - y) * sqrt(3) / 2;
	// 			d = -10 + (x + y) * 1 / 2;
	//  	       	my_mlx_pixel_put(&img, a + 500, b, 0x00FF00);
	// 			my_mlx_pixel_put(&img, c + 1000, d, 0x0000FF);
	// 			my_mlx_pixel_put(&img, x, y, 0xFF0000);
	// 		}
	// 		y++;
	// 	}
	// 	x++;
    // }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}