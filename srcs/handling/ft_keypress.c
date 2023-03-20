/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:16:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/20 20:31:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_handle_keypress.h"

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
