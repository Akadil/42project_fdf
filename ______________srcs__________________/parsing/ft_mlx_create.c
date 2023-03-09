/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_mlx_creat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:58:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 15:10:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing_mlx_create.h"

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

/*
	This fuctions were done to shorten ft_parsing function
	------------------------------------------------------
	1. mlx_init  ->  mlx_init
	2 ...
*/
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
