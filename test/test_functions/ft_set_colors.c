/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:51:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 12:54:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

static void    ft_find_z_extrimas(t_data *data, int z[2]);

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

#include <stdio.h>
void    ft_set_colors(t_data *data)
{
    int i;
    int j;
    int z[2];
    float   container;

    printf("I was here!");
    z[0] = 0;
    z[1] = 0;
    ft_find_z_extrimas(data, z);
    i = 0;
    while (i < data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < data->mtrx.mtrx_length)
        {
            if (data->mtrx.colors[i][j] == -1 && z[1] == z[0])
                data->mtrx.colors[i][j] = z[0];
            else if (data->mtrx.colors[i][j] == -1) 
            {
                container = (data->mtrx.matrix[i][j] - z[0]);
                container /= z[1] - z[0];
                container *= 255;
                if (data->coef.color % 3 == 0)
                    data->mtrx.colors[i][j] = create_rgb(255, 255, 255 - (int)container);
                if (data->coef.color % 3 == 1)
                    data->mtrx.colors[i][j] = create_rgb(255, 255 - (int)container, 255);
                if (data->coef.color % 3 == 2)
                    data->mtrx.colors[i][j] = create_rgb(255 - (int)container, 255, 255);
            }
            j++;
        }
        i++;
    }
    printf(" -> Color is %d\n", data->mtrx.colors[1][1]);
}

static void    ft_find_z_extrimas(t_data *data, int z[2])
{
    int z_min;
    int z_max;
    int i;
    int j;

    z_min = 2147483647;
    z_max = -2147483648;
    i = 0;
    while (i < data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < data->mtrx.mtrx_length)
        {
            if (data->mtrx.matrix[i][j] < z_min)
                z_min = data->mtrx.matrix[i][j];
            if (data->mtrx.matrix[i][j] > z_max)
                z_max = data->mtrx.matrix[i][j];
            j++;
        }
        i++;
    }
    z[0] = z_min;
    z[1] = z_max;
}
