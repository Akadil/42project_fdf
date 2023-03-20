/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:31:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/20 20:32:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
# include <X11/X.h>
# include <X11/keysym.h>

void	ft_handle_translation(int keysym, t_data *data)
{
	if (keysym == 'k')
		data->param.x_offset += 10;
	if (keysym == 'h')
		data->param.x_offset -= 10;
	if (keysym == 'u')
		data->param.y_offset -= 10;
	if (keysym == 'j')
		data->param.y_offset += 10;
}

void	ft_handle_rotation(int keysym, t_data *data)
{
	if (keysym == 'a')
		data->param.beta -= 5;
	if (keysym == 'd')
		data->param.beta += 5;
	if (keysym == 'w')
		data->param.alpha += 5;
	if (keysym == 's')
		data->param.alpha -= 5;
	if (keysym == 'q')
		data->param.theta += 5;
	if (keysym == 'e')
		data->param.theta -= 5;
}

void	ft_handle_zoom(int keysym, t_data *data)
{
	if (keysym == XK_equal)
		data->param.grid += 2;
	if (keysym == XK_minus)
		data->param.grid -= 2;
	if (keysym == 'x')
		data->param.attitude += 2;
	if (keysym == 'z')
		data->param.attitude -= 2;
}
