/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:16:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/20 14:37:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

void	ft_handle_translation(int keysym, t_data *data);
void	ft_handle_rotation(int keysym, t_data *data);
void	ft_handle_zoom(int keysym, t_data *data);

int	ft_handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == 'u' || keysym == 'h' || keysym == 'j' || keysym == 'k')
		ft_handle_translation(keysym, data);
	if (keysym == 'w' || keysym == 'a' || keysym == 's' || keysym == 'd')
		ft_handle_rotation(keysym, data);
	if (keysym == 'q' || keysym == 'e')
		ft_handle_rotation(keysym, data);
	if (keysym == XK_equal || keysym == XK_minus)
		ft_handle_zoom(keysym, data);
	if (keysym == 'x' || keysym == 'z')
		ft_handle_zoom(keysym, data);
	if (keysym == XK_space)
		data->param.color += 1;
	return (0);
}

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
