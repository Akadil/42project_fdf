/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:58:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 14:51:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include "ft_data.h"
# include "ft_clean.h"
# include "ft_mlx.h"
# include <stdio.h>

void    ft_init(t_data **data);
void    ft_prepare_data(int argc, char **argv, t_data *my_data);
int     ft_render(t_data *data);
void    ft_set_colors(t_data *data);

#endif