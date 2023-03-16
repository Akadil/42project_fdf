/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:58:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 20:34:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_mlx_create.h"

/*
	Goal: Create the mlx instances
*/
void	ft_mlx_create(t_data *data)
{
	data->mlx_ptr = my_mlx_init(data);
	data->win_ptr = my_mlx_new_window(data, "Fil de Fer (FdF)");
	data->img.mlx_img = my_mlx_new_image(data);
	data->img.addr = my_mlx_get_data_addr(data);
}
