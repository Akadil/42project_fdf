/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:31:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:21:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
    Goal: Render the background. 

    I have seperate file for future extensions like chanind the color, or 
    adding some data behind
*/
void	ft_render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}
