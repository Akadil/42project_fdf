/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 15:10:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include "ft_data.h"
# include "ft_error.h"
# include "ft_mlx.h"
# include <stdio.h>

void    ft_mlx_create(t_data *data);
void	ft_parse_matrix(t_data *my_data, char **argv);
void	ft_set_coefficients(t_data *my_data);
void	ft_set_colors(t_data *data);

#endif