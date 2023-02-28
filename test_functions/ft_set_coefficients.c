/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_coefficients.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:24:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/27 21:11:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

void ft_set_coefficients(t_data *my_data)
{
    my_data->coef.alpha = 30;
    my_data->coef.beta = 30;
    my_data->coef.x_offset = 500;
    my_data->coef.y_offset = 250;
    my_data->coef.proj_model = 1;
    my_data->coef.grid = ft_find_grid(my_data);
    my_data->coef.attitude = ft_find_attitude(my_data);
}

static int ft_find_grid(t_data *my_data)
{
    int max_bw_row_col;

    max_bw_row_col = my_data->mtrx.mtrx_height;
    if (max_bw_row_col < my_data->mtrx.mtrx_length)
        max_bw_row_col = my_data->mtrx.mtrx_length;
    return ((WINDOW_WIDTH - my_data->coef.x_offset * 2 ) / max_bw_row_col / sqrt(2));
}

static int ft_find_attitude(t_data *my_data)
{
    int z_max;
    int i;
    int j;
    
    z_max = -2147483648;
    i = 0;
    while (i < my_data->mtrx.mtrx_height)
    {
        j = 0;
        while (i < my_data->mtrx.mtrx_length)
        {
            if (my_data->mtrx.matrix[i][j] > z_max)
                z_max = my_data->mtrx.matrix[i][j];
            j++;
        }
        i++;
    }
    return ((WINDOW_HEIGHT - my_data->coef.y_offset * 2 ) / z_max);
}