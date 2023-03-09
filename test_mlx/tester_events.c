/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:25:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/25 18:43:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

typedef struct	s_data {
    void	*mlx;
    void    *win;
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

int	handle_keyboard(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
    	mlx_destroy_window(data->mlx, data->win);

    }
    else
        printf("Your key is %d\n", keycode);
    return (0);
}

int handle_mouse(int button, int x, int y, t_data *data)
{
    int i;
    int j;

    i = x - 5;
    while (i < x + 5)
    {
        j = y - 5;
        while (j < y + 5)
        {
            if (pow((i - x), 2) + pow((j - y), 2) < 16)
            {
                if (i > 0 && j > 0)
                {
                    if (button == 1)
                        my_mlx_pixel_put(data, i, j, 0xFF0000);
                    else
                        my_mlx_pixel_put(data, i, j, 0x0000FF);
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}

int handle_mouse_mv(int x, int y, t_data *data)
{
    // printf("x - %d, y - %d\n", x, y);
    
    my_mlx_pixel_put(data, x, y, 0x00FF00);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int handle_enter(t_data *vars)
{
    (void)vars;
    printf("Mouse entered!\n");
    return (0);
}

int handle_exit(t_data *vars)
{
    (void)vars;
    printf("Mouse exited!\n");
    return (0);
}

// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

int main(void)
{
    t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Hello world!");
    data.img =  mlx_new_image(data.mlx, 500, 500);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L<<0, handle_keyboard, &data);
    mlx_hook(data.win, 4, 1L<<2, handle_mouse, &data);
    mlx_hook(data.win, 6, 1L<<4, handle_mouse_mv, &data);
    mlx_hook(data.win, 7, 1L<<5, handle_enter, NULL);
    mlx_hook(data.win, 8, 1L<<6, handle_exit, NULL);
    
	mlx_loop(data.mlx);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
    return (0);
}