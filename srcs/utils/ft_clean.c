/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 18:11:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_mlx.h"
#include <stdlib.h>

/*
        Note:   
            1. I have to know the proper size of matrix, so I have to set the
                size after I allocate the memory. 
*/
static void	ft_clean_darray(t_data *trash)
{
	int	i;

	i = 0;
	if (!trash)
		return ;
	if (trash->mtrx.node)
	{
		while (i < trash->mtrx.height && trash->mtrx.node[i])
		{
			free(trash->mtrx.node[i]);
			i++;
		}
		free(trash->mtrx.node);
	}
}

void	ft_clean(t_data *trash)
{
	if (trash->img.mlx_img)
		mlx_destroy_image(trash->mlx_ptr, trash->img.mlx_img);
	if (trash->win_ptr)
		mlx_destroy_window(trash->mlx_ptr, trash->win_ptr);
	if (trash->mlx_ptr)
	{
		mlx_destroy_display(trash->mlx_ptr);
		free(trash->mlx_ptr);
	}
	ft_clean_darray(trash);
	if (trash)
		free(trash);
}
