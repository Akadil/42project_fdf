/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 14:09:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prepare_data.h"

void	ft_prepare_data(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_merror_clean_exit(data, "Wrong arguments", NULL);
	data->mlx_ptr = my_mlx_init(data);
	data->win_ptr = my_mlx_new_window(data, "Fil de Fer (FdF)");
	data->img.mlx_img = my_mlx_new_image(data);
	data->img.addr = my_mlx_get_data_addr(data);
	ft_parse_matrix(data, argv);
	ft_set_coefficients(data);
}

static void	*my_mlx_init(t_data *data)
{
	void	*returner;

	returner = mlx_init();
	if (!returner)
		ft_merror_clean_exit(data, "mlx_init failed", NULL);
	return (returner);
}

static void	*my_mlx_new_window(t_data *data, char *name)
{
	void	*returner;

	returner = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
		name);
	if (!returner)
		ft_merror_clean_exit(data, "mlx_new_window failed", NULL);
	return (returner);
}

static void	*my_mlx_new_image(t_data *data)
{
	void	*returner;

	returner = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!returner)
		ft_merror_clean_exit(data, "mlx_new_image failed", NULL);
	return (returner);
}

static char	*my_mlx_get_data_addr(t_data *data)
{
	char	*returner;

	returner = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
		&data->img.line_len, &data->img.endian);
	if (!returner)
		ft_merror_clean_exit(data, "mlx_get_addr failed", NULL);
	return (returner);
}
