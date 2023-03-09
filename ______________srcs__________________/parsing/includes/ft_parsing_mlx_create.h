/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_mlx_create.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:05:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 15:07:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_MLX_CREATE_H
# define FT_PARSING_MLX_CREATE_H

# include "ft_data.h"
# include "ft_mlx.h"
# include <stdio.h>

static void	*my_mlx_init(t_data *data);
static void	*my_mlx_new_window(t_data *data, char *name);
static void	*my_mlx_new_image(t_data *data);
static char	*my_mlx_get_data_addr(t_data *data);

#endif