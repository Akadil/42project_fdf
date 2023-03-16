/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:25:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 11:36:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_point.h"
#include "ft_data.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_set_colors_one(t_data *data, t_point *p1)
{
	int	num;

	if (data->mtrx.node[p1->i][p1->j].color != -1)
		p1->color = data->mtrx.node[p1->i][p1->j].color;
	else
	{
		if (data->mtrx.z_max - data->mtrx.z_min == 0)
			num = 255;
		else
			num = (float)(data->mtrx.node[p1->i][p1->j].z - data->mtrx.z_min)
				/ (float)(data->mtrx.z_max - data->mtrx.z_min) * 255;
		if (data->param.color % 3 == 1)
			p1->color = create_rgb(255, 255, num);
		else if (data->param.color % 3 == 2)
			p1->color = create_rgb(255, num, 255);
		else
			p1->color = create_rgb(num, 255, 255);
	}
}

void	ft_set_colors_two(t_data *data, t_point *p2)
{
	int	num;

	if (data->mtrx.node[p2->i][p2->j].color != -1)
		p2->color = data->mtrx.node[p2->i][p2->j].color;
	else
	{
		if (data->mtrx.z_max - data->mtrx.z_min == 0)
			num = 255;
		else
			num = (float)(data->mtrx.node[p2->i][p2->j].z - data->mtrx.z_min)
				/ (float)(data->mtrx.z_max - data->mtrx.z_min) * 255;
		if (data->param.color % 3 == 1)
			p2->color = create_rgb(255, 255, num);
		else if (data->param.color % 3 == 2)
			p2->color = create_rgb(255, num, 255);
		else
			p2->color = create_rgb(num, 255, 255);
	}
}
