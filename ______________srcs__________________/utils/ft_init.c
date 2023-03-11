/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:01:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 18:00:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

void    ft_init(t_data **my_data)
{
    t_data  *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        ft_strerror_exit("t_data failed");
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;    
    ft_init_img(data);
    ft_init_coef(data);
    ft_init_matrix(data);
    *my_data = data;
}

static void    ft_init_img(t_data *_data)
{
    _data->img.mlx_img = NULL;
    _data->img.addr = NULL;
    _data->img.bpp = 0;
    _data->img.line_len = 0;
    _data->img.endian = 0;
}

static void    ft_init_coef(t_data *_data)
{
    _data->param.alpha = -1;
    _data->param.attitude = 0;
    _data->param.beta = -1;
    _data->param.grid = 0;
    _data->param.proj_model = -1;
    _data->param.x_offset = -1;
    _data->param.y_offset = -1;
    _data->param.color = 1;
}

static void    ft_init_matrix(t_data *_data)
{
    _data->mtrx.node = NULL;
    _data->mtrx.height = 0;
    _data->mtrx.width = 0;
    _data->mtrx.z_max = -2147483648;
    _data->mtrx.z_min = 2147483647;
}

