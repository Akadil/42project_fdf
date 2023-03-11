/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_fill_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:28:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 19:19:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

void	ft_init_matrix(t_data *data, t_list *rows, int fd)
{
	t_node	**node;
	int		i;

	ft_find_width(data, rows);
	node = (t_node **)malloc(sizeof(t_node *) * (data->mtrx.height + 1));
	if (!node)
		ft_close_free_serror(data, rows, "Matrix creation", fd);
	i = 0;
	while (i < data->mtrx.height)
	{
		node[i] = (t_node *)malloc(sizeof(t_node) * data->mtrx.width);
		if (!node[i])
			ft_close_free_serror(data, rows, "Matrix creation", fd);
		i++;
	}
}

void    ft_fill_matrix(t_data *data, t_list *rows, int fd)
{
    char    **line;
    int     i;
    int     j;

    ft_init_matrix(data, rows, fd);
    i = 0;
    while (rows)
    {
        line = ft_split(rows->content, ' ');
        if (!line)
            ft_close_free_error(data, rows, "Line separation", fd);
        j = -1;
        while (++j < data->mtrx.width)
        {
            data->mtrx.node[i][j].z = ft_atoi(line[j]);
            if (ft_strchr(line[j], ','))
                data->mtrx.node[i][j].color = hex_to_decimal(ft_strchr(line[j], ',') + 1);
            else
                data->mtrx.node[i][j].color = -1;
        }
		ft_free_d_array_char(line);
        rows = rows->next;
        i++;
    }
}