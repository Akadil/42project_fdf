/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/27 21:10:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPARE_DATA_H
# define FT_PREPARE_DATA_H

# include "ft_data.h"
# include "ft_error.h"
# include "ft_mlx.h"
# include <stdio.h>

static void *my_mlx_init(t_data *data);
static void *my_mlx_new_window(t_data *data, char *name);
static void *my_mlx_new_image(t_data *data);
static char *my_mlx_get_data_addr(t_data *data);
void        ft_parse_matrix(t_data *my_data, char **argv);

#endif