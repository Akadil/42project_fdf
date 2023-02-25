/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/24 14:56:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_main.h"
#include "mlx.h"

int main(int argc, char **argv)
{
    t_data  *my_data;

    my_data = NULL;
    ft_init(&my_data);
    ft_prepare_data(argc, argv, my_data);
    return (0);
}