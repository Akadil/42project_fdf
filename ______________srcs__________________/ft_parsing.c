/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 15:13:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

/*
	Goal:	(1) To parse the data from argc, and argv
			(2) To set needed coefficients
	
	ft_mlx_create()			- Creates the instances of mlx like: windows, image
	ft_parse_matrix()		- Parse the matrix into struct
	ft_set_coefficients()	- Set the coefficients like alpha angle, offset on
								x, y axes. And many more
	ft_set_color()			- Set the color
*/
void	ft_parsing(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_merror_clean_exit(data, "Wrong arguments", NULL);
	ft_mlx_create(data);
	ft_parse_matrix(data, argv);
	ft_set_coefficients(data);
	ft_set_colors(data);
}

