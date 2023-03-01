/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/01 11:39:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_clean.h"

void ft_print(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < data->mtrx.mtrx_length)
        {
            printf("%d,%d ", data->mtrx.matrix[i][j], data->mtrx.colors[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    t_data  *my_data;

    my_data = NULL;
    ft_init(&my_data);
    ft_prepare_data(argc, argv, my_data);
    ft_print(my_data);
    ft_clean(my_data);
    return (0);
}