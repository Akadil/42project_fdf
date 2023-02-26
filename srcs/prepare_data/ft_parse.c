/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/26 16:12:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

t_list  *ft_get_all_rows(int fd, t_data *my_data)
{
    t_list  *head;
    t_list  *temp;
    char    *str;

    str = get_next_line(fd, 0);
    while (str)
    {
        temp = ft_lstnew(str);
        if (!temp)
            printf("Error in get_all_data! handle\n");
        ft_lstadd_back(&head, temp);
        str = get_next_line(fd, 0);
    }
    get_next_line(fd, 1);
    return (head);
}

void    ft_fill_matrix(t_list *head, t_data *my_data)
{
    char    **line;
    t_list  *temp;
    int     i;
    int     j;

    i = 0;
    while (head)
    {
        line = ft_split(head->content, ' ');
        if (!line)
            printf("Error!\n");
        my_data->matrix[i] = (int *)malloc(sizeof(int) * ft_strlen_new(line));
        if (!my_data->matrix[i])
            printf("Error!\n");
        j = 0;
        while (j < ft_strlen_new(line))
        {
            if (ft_isdigit(line[j][0]) == 0)
                printf("Error!\n");
            my_data->matrix[i][j] = ft_atoi(line[j]);
            if (ft_strchr(line[j], ','))
                my_data->colors[i][j] = ft_atoi(ft_strchr(line[j], ',') + 1);
            j++;
        }
        temp = head->next;
        free(head);
        head = temp;
    }
}

void    ft_parse(char **argv, t_data *my_data)
{
    t_list  *head;
    int     fd;
    int     row_num;
    int     i;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        printf("Error! handle\n");
    head = ft_get_all_rows(fd, my_data);
    if (!head)
        printf("No data?!\n");
    ft_fill_matrix(head, my_data);
    close(fd);
}
