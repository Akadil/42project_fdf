/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:32:01 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 20:00:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rendering.h"

int	ft_rendering(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	ft_render_background(data, 0);
	ft_render_projection(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, \
																			0);
	return (0);
}
