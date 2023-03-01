/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:58:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 14:27:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "ft_data.h"
# include "ft_clean.h"
# include "ft_mlx.h"
# include <stdio.h>

void    ft_init(t_data **data);
void    ft_prepare_data(int argc, char **argv, t_data *my_data);

#endif