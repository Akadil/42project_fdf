/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:28:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/09 13:29:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_libft.h"

void    ft_fill_matrix(t_data *data, t_list *head, int fd)
{
    char    **line;
    int     i;
    int     j;

    i = -1;
    while (head)
    {
        line = ft_split(head->content, ' ');
        if (!line)
            ft_close_error(data, "Line separation", fd);
		if (data->mtrx.width == 0)
			data->mtrx.width = ft_strlen_darray(line);
		data->mtrx.matrix[++i] = (int *)malloc(sizeof(int) * data->mtrx.width);
        if (!data->mtrx.matrix[i])
			ft_close_error(data, "Row creation", fd);
        data->mtrx.colors[i] = (int *)malloc(sizeof(int) * data->mtrx.width);
        if (!data->mtrx.colors[i])
			ft_close_error(data, "Row creation", fd);
        j = -1;
        while (++j < data->mtrx.width)
        {
            data->mtrx.matrix[i][j] = ft_atoi(line[j]);
            if (ft_strchr(line[j], ','))
                data->mtrx.colors[i][j] = hex_to_decimal(ft_strchr(line[j], ',') + 1);
            else
                data->mtrx.colors[i][j] = -1;
        }
		ft_free_d_array_char(line);
        head = head->next;
    }
}