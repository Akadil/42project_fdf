/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/14 17:31:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include <X11/X.h>
#include <X11/keysym.h>

// void ft_print(t_data *data, char **argv)
// {
//     int i;
//     int j;

//     i = 0;
//     printf("The map - %s\n\n", argv[1]);
//     printf("Height: %d, Width: %d\n", data->mtrx.mtrx_height, data->mtrx.mtrx_length);
//     while (i < data->mtrx.mtrx_height)
//     {
//         j = 0;
//         while (j < data->mtrx.mtrx_length)
//         {
//             printf("[%d,%d] ", data->mtrx.matrix[i][j], data->mtrx.colors[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
//     printf("\n");
//     printf("Angles: alpha %d, beta %d\n", data->coef.alpha, data->coef.beta);
//     printf("Coefficients: grid %d, att %d\n", data->coef.grid, data->coef.attitude);
//     printf("Offsets: x %d, y %d\n", data->coef.x_offset, data->coef.y_offset);
//     printf("\n");
// }

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == 'a')
	{
		if (data->param.beta == 359)
			data->param.beta = 0;
		else
			data->param.beta += 5;
	}
    if (keysym == 'd')
	{
		if (data->param.beta == 0)
			data->param.beta = 359;
		else
			data->param.beta -= 5;
	}
    if (keysym == 'w')
	{
		data->param.alpha -= 5;
	}
    if (keysym == 's')
	{
		data->param.alpha += 5;
	}
    if (keysym == 'q')
	{
		data->param.theta -= 5;
	}
    if (keysym == 'e')
	{
		data->param.theta += 5;
	}
    if (keysym == 'u')
	{
		data->param.x_offset += 10;
	}
    if (keysym == 'j')
	{
		data->param.x_offset -= 10;
	}
    if (keysym == 'k')
	{
		data->param.y_offset -= 10;
	}
    if (keysym == 'h')
	{
		data->param.y_offset += 10;
	}
    if (keysym == XK_space)
    {
        data->param.color += 1;
    }
    if (keysym == XK_equal)
	{
		data->param.grid += 2;
	}
    if (keysym == XK_minus)
    {
        data->param.grid -= 2;
    }
    if (keysym == 'x')
	{
		data->param.attitude += 2;
	}
    if (keysym == 'z')
    {
        data->param.attitude -= 2;
    }
	return (0);
}

int main(int argc, char **argv)
{
    t_data  *my_data;

    my_data = NULL;
    ft_init(&my_data);
    ft_parsing(argc, argv, my_data);
    //ft_print(my_data, argv);
    
    // ft_rendering(my_data);
	mlx_loop_hook(my_data->mlx_ptr, &ft_rendering, my_data);
	mlx_hook(my_data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, my_data);
	mlx_loop(my_data->mlx_ptr);
	
    ft_clean(my_data);
    return (0);
}