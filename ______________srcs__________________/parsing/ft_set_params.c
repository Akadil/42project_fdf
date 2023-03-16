/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:24:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 11:57:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_set_params.h"

void	ft_set_params(t_data *my_data)
{
	my_data->param.alpha = 0;
	my_data->param.beta = 180;
	my_data->param.theta = 90;
	my_data->param.proj_model = 1;
	my_data->param.x_offset = WINDOW_WIDTH / 2;
	my_data->param.y_offset = WINDOW_HEIGHT / 2;
	my_data->param.grid = ft_find_grid(my_data);
	my_data->param.attitude = ft_find_attitude(my_data);
}
