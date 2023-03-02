/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/02 20:44:48 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void ft_print(t_data *data, char **argv)
{
    int i;
    int j;

    i = 0;
    printf("The map - %s\n\n", argv[1]);
    printf("Height: %d, Width: %d\n", data->mtrx.mtrx_height, data->mtrx.mtrx_length);
    while (i < data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < data->mtrx.mtrx_length)
        {
            printf("%d ", data->mtrx.matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    printf("Angles: alpha %d, beta %d\n", data->coef.alpha, data->coef.beta);
    printf("Coefficients: grid %d, att %d\n", data->coef.grid, data->coef.attitude);
    printf("Offsets: x %d, y %d\n", data->coef.x_offset, data->coef.y_offset);
    printf("\n");
}

int main(int argc, char **argv)
{
    t_data  *my_data;

    my_data = NULL;
    ft_init(&my_data);
    ft_prepare_data(argc, argv, my_data);
    
    ft_render(my_data);
	// mlx_loop_hook(my_data->mlx_ptr, &ft_render, &my_data);
	// //mlx_hook(my_data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &my_data);
	mlx_loop(my_data->mlx_ptr);
	
	ft_print(my_data, argv);
    ft_clean(my_data);
    return (0);
}