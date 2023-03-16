/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:26:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 11:34:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "ft_data.h"
# include "ft_point.h"

void	ft_set_colors_one(t_data *data, t_point *p1);
void	ft_set_colors_two(t_data *data, t_point *p2);
int		create_rgb(int r, int g, int b);

#endif
