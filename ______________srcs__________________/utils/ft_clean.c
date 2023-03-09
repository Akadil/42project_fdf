/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 11:34:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <stdlib.h>
#include "ft_mlx.h"

/*
        Note:   
            1. I have to know the proper size of matrix, so I have to set the
                size after I allocate the memory. 
*/
static void    ft_clean_darray(int **array_trash, int num_row)
{
    int i;

    i = 0;
    if (array_trash)
    {
        while (i < num_row && array_trash[i])
        {
            free (array_trash[i]);
            i++;
        }
        free (array_trash);
    }
}

void    ft_clean(t_data *trash)
{
    if (trash->img.mlx_img)
        mlx_destroy_image(trash->mlx_ptr, trash->img.mlx_img);
    if (trash->win_ptr)
        mlx_destroy_window(trash->mlx_ptr, trash->win_ptr);
    if (trash->mlx_ptr)
    {
        mlx_destroy_display(trash->mlx_ptr);
        free (trash->mlx_ptr);
    }
    ft_clean_darray(trash->mtrx.matrix, trash->mtrx.mtrx_height);
    ft_clean_darray(trash->mtrx.colors, trash->mtrx.mtrx_height);
    free (trash);
}
