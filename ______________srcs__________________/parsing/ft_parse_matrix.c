/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/09 13:28:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_libft.h"
#include "ft_error.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_parse_matrix(t_data *data, char **argv)
{
    t_list  *rows;
    int     fd;

    fd = my_open(data, argv);
    rows = ft_get_all_rows(data, fd);
    ft_init_matrix(data, rows, fd);
    ft_fill_matrix(data, rows, fd);
    ft_lstclear(&rows, &free);
    close(fd);
}

void    ft_init_matrix(t_data *data, t_list *rows, int fd)
{
    t_node  **node;
    int i;

    ft_find_width(data, rows);
    node = (t_node **)malloc(sizeof(t_node *) * (data->mtrx.height + 1));
    if (!node)
        print("Error");
    i = 0;
    while (i < data->mtrx.height)
    {
        node[i] = (t_node *)malloc(sizeof(t_node) * data->mtrx.width);
        if (!node[i])
            print("Error");
        i++;
    }
}


