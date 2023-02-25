/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:01:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/25 19:06:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_data.h"
#include "mlx.h"

void    ft_init(t_data **my_data)
{
    t_data  *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        exit (-1);
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        free (data);
        exit(-1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de Fer (FdF)");
    if (!data->win_ptr)
    {
        free (data->mlx_ptr);
        free (data);
        exit (-1);
    }
    data->coef.color = RED_PIXEL;
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
    *my_data = data;
}