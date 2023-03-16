/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params_utilc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:55:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 12:00:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

int	ft_find_grid(t_data *my_data)
{
	float	returner;
	float	max;

	max = my_data->mtrx.height;
	if (max < my_data->mtrx.width)
		max = my_data->mtrx.width;
	returner = WINDOW_WIDTH / 2 / max;
	while (returner < 2 && my_data->param.x_offset > 120)
	{
		my_data->param.x_offset = my_data->param.x_offset / 2;
		returner = (WINDOW_WIDTH - my_data->param.x_offset * 2) / max;
	}
	return (returner);
}

int	ft_find_attitude(t_data *my_data)
{
	float	returner;
	float	z_max;
	float	z_min;
	int		i;
	int		j;

	z_min = 2147483647.0;
	z_max = -2147483648.0;
	i = 0;
	while (i < my_data->mtrx.height)
	{
		j = 0;
		while (j < my_data->mtrx.width)
		{
			if (my_data->mtrx.node[i][j].z > z_max)
				z_max = my_data->mtrx.node[i][j].z;
			if (my_data->mtrx.node[i][j].z < z_min)
				z_min = my_data->mtrx.node[i][j].z;
			j++;
		}
		i++;
	}
	returner = WINDOW_HEIGHT / 2 / (z_max - z_min);
	while (returner < 2 && my_data->param.y_offset > 70)
	{
		my_data->param.y_offset = my_data->param.y_offset / 2;
		returner = (WINDOW_HEIGHT - my_data->param.y_offset * 2) \
														/ (z_max - z_min);
	}
	return (returner);
}