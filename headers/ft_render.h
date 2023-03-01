/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:52:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 15:00:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include "ft_mlx.h"
# include "ft_data.h"
# include <stdio.h>

void	ft_img_pix_put(t_data *data, int x, int y, int color);
void	ft_render_background(t_data *data, int color);

#endif