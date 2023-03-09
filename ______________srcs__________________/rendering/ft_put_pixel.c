/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:48:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/02 20:32:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *pixel;
	int		i;

    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
        return ;
    i = data->img.bpp - 8;
    pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (data->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (data->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}