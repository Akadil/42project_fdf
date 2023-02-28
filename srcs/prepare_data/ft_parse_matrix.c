/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/27 21:27:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_libft.h"
#include "ft_error.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

t_list  *ft_get_all_rows(t_data *my_data, int fd)
{
    t_list  *head;
    t_list  *temp;
    char    *str;

    head = NULL;
    str = get_next_line(fd, 0);
    while (str)
    {
        temp = ft_lstnew(str);
        if (!temp)
        {
            ft_lstclear(&head, &free);
            ft_strerror_clean_exit(my_data, "Parsing the file");
        }
        ft_lstadd_back(&head, temp);
        str = get_next_line(fd, 0);
    }
    get_next_line(0, 1);
    return (head);
}

int ft_strlen_darray(char **array)
{
    int len;

    len = 0;
    while (array[len])
        len++;
    return (len);
}

void    ft_fill_matrix(t_data *my_data, t_list *head)
{
    char    **line;
    t_list  *temp;
    int     i;
    int     j;

    i = -1;
    while (head)
    {
        line = ft_split(head->content, ' ');
        if (!line)
            printf("Error!\n");
        my_data->mtrx.matrix[++i] = (int *)malloc(sizeof(int) * ft_strlen_darray(line));
        if (!my_data->mtrx.matrix[i])
            printf("Error!\n");
        j = -1;
        while (++j < ft_strlen_darray(line))
        {
            my_data->mtrx.matrix[i][j] = ft_atoi(line[j]);
            if (ft_strchr(line[j], ','))
                my_data->mtrx.colors[i][j] = ft_atoi(ft_strchr(line[j], ',') + 1);
        }
        temp = head;
        head = head->next;
        free(temp);
    }
}

void    ft_parse_matrix(t_data *my_data, char **argv)
{
    t_list  *head;
    int     fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_perror_clean_exit(my_data, argv[1]);
    head = ft_get_all_rows(my_data, fd);
    if (!head)
        printf("No data?!\n"); // consider this case
    my_data->mtrx.matrix = (int **)malloc (sizeof(int *) * ft_lstsize(head));
    ft_fill_matrix(my_data, head);
    ft_lstclear(&head, &free);
    close(fd);
}
