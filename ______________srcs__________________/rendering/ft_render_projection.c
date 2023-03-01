/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 15:30:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

void    ft_render_projection(t_data *data)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < data->mtrx.mtrx_length)
        {
            ft_apply_coefficients(data, i, j);
            if (j != 0)
                ft_draw_line_i_i+1();
            if (i != 0)
                ft_draw_line_j_j+1();
            j++;
        }
        i ++;
    }
}

// The first way of doing this rendering is by matrix
// But another way is doing by recursion

/*

def     before_rendering():
    ft_rendering(data, 0, 0, NULL);

def     ft_rendering(data, int x, int y):
    
    if (x or y is bad)
        continue ;
    if (x == 0)
        
*/