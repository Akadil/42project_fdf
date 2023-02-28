/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/27 20:28:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <stdlib.h>

void    ft_clean(t_data *trash)
{
    if (trash->mlx_ptr)
        free (trash->mlx_ptr);
    if (trash->win_ptr)
        free (trash->win_ptr);
    if (trash->img.mlx_img)
        free (trash->img.mlx_img);
    if (trash->img.addr)
        free (trash->img.addr);
    free (trash);
}