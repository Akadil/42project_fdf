/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_create_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:52:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:13:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"
#include "ft_mlx.h"
#include <stdio.h>

void	*my_mlx_init(t_data *data)
{
	void	*returner;

	returner = mlx_init();
	if (!returner)
		ft_merror_clean_exit(data, "mlx_init failed", NULL);
	return (returner);
}

void	*my_mlx_new_window(t_data *data, char *name)
{
	void	*returner;

	returner = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
																	name);
	if (!returner)
		ft_merror_clean_exit(data, "mlx_new_window failed", NULL);
	return (returner);
}

void	*my_mlx_new_image(t_data *data)
{
	void	*returner;

	returner = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!returner)
		ft_merror_clean_exit(data, "mlx_new_image failed", NULL);
	return (returner);
}

char	*my_mlx_get_data_addr(t_data *data)
{
	char	*returner;

	returner = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
									&data->img.line_len, &data->img.endian);
	if (!returner)
		ft_merror_clean_exit(data, "mlx_get_addr failed", NULL);
	return (returner);
}
