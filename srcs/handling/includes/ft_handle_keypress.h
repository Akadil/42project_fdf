/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keypress.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:30:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/20 20:31:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_KEYPRESS_H
# define FT_HANDLE_KEYPRESS_H

# include "ft_data.h"
# include "ft_mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

void	ft_handle_translation(int keysym, t_data *data);
void	ft_handle_rotation(int keysym, t_data *data);
void	ft_handle_zoom(int keysym, t_data *data);

#endif