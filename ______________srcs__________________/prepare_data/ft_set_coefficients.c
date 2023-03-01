/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_coefficients.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:24:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 14:21:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <math.h>

static int ft_find_attitude(t_data *my_data);
static int ft_find_grid(t_data *my_data);

void ft_set_coefficients(t_data *my_data)
{
    my_data->coef.alpha = 30;
    my_data->coef.beta = 30;
    my_data->coef.x_offset = WINDOW_WIDTH / 4;
    my_data->coef.y_offset = WINDOW_HEIGHT / 4;
    my_data->coef.proj_model = 1;
    my_data->coef.grid = ft_find_grid(my_data);
    my_data->coef.attitude = ft_find_attitude(my_data);
}

static int ft_find_grid(t_data *my_data)
{
    int returner;
    int max;

    max = my_data->mtrx.mtrx_height;
    if (max < my_data->mtrx.mtrx_length)
        max = my_data->mtrx.mtrx_length;
    returner = WINDOW_WIDTH / 2 / max / sqrt(2);
    while (returner < 2 && my_data->coef.x_offset > 120)
    {
        my_data->coef.x_offset = my_data->coef.x_offset / 2;
        returner = (WINDOW_WIDTH - my_data->coef.x_offset * 2) / max / sqrt(2);
    }
    return (returner);
}

static int ft_find_attitude(t_data *my_data)
{
    int returner;
    int z_max;
    int i;
    int j;
    
    z_max = -2147483648;
    i = 0;
    while (i < my_data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < my_data->mtrx.mtrx_length)
        {
            if (my_data->mtrx.matrix[i][j] > z_max)
                z_max = my_data->mtrx.matrix[i][j];
            j++;
        }
        i++;
    }
    returner = WINDOW_HEIGHT / 2 / z_max;
    while (returner < 2 && my_data->coef.y_offset > 70)
    {
        my_data->coef.y_offset = my_data->coef.y_offset / 2;
        returner = (WINDOW_HEIGHT - my_data->coef.y_offset * 2) / z_max;
    }
    return (returner);
}