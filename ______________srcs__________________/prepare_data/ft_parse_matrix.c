/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/03 13:24:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_libft.h"
#include "ft_error.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

t_list  *ft_get_all_rows(t_data *data, int fd)
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
            close(fd);
            ft_lstclear(&head, &free);
            ft_strerror_clean_exit(data, "Parsing the file");
        }
        ft_lstadd_back(&head, temp);
        str = get_next_line(fd, 0);
    }
    get_next_line(0, 1);
    if (!head)
    {
        close (fd);
        ft_merror_clean_exit(data, "The file is empty", NULL);
    }
    data->mtrx.mtrx_height = ft_lstsize(head);
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

void	ft_free_d_array_char(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free (trash[i]);
		i++;
	}
	free (trash);
}

void	ft_close_error(t_data *trash, char *str, int fd)
{
	close (fd);
	ft_strerror_clean_exit(trash, str);
}

int hex_to_decimal(char* hex_string) 
{
    int decimal_value;
    int i;
    int digit_value;
    char    c;

    decimal_value = 0;
    i = 0;
    while (hex_string[i] != '\0')
    {
        c = hex_string[i];
        if (c >= '0' && c <= '9')
            digit_value = c - '0';
        else if (c >= 'A' && c <= 'F')
            digit_value = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            digit_value = c - 'a' + 10;
        decimal_value = decimal_value * 16 + digit_value;
        i++;
    }
    return decimal_value;
}

/*  ! Consider Maria's case !   */
/*	! Do I need to ft_calloc this matrix elements? !	*/
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
		if (data->mtrx.mtrx_length == 0)
			data->mtrx.mtrx_length = ft_strlen_darray(line);
		data->mtrx.matrix[++i] = (int *)malloc(sizeof(int) * data->mtrx.mtrx_length);
        if (!data->mtrx.matrix[i])
			ft_close_error(data, "Row creation", fd);
        data->mtrx.colors[i] = (int *)malloc(sizeof(int) * data->mtrx.mtrx_length);
        if (!data->mtrx.colors[i])
			ft_close_error(data, "Row creation", fd);
        j = -1;
        while (++j < data->mtrx.mtrx_length)
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

int    my_open(t_data *_my_data, char **_argv)
{
    int fd;

    fd = open(_argv[1], O_RDONLY);
    if (fd == -1)
        ft_perror_clean_exit(_my_data, _argv[1]);
    return (fd);
}

int **my_d_array_int_calloc(t_data *_data, int fd)
{
    int **returner;
    int i;

    returner = (int **)malloc(sizeof(int *) * _data->mtrx.mtrx_height);
    if (!returner)
    {
        close (fd);
        ft_strerror_clean_exit(_data, "Parsing the matrix");
    }
    i = 0;
    while (i < _data->mtrx.mtrx_height)
    {
        returner[i] = NULL;
        i++;
    }
    return (returner);
}

void    ft_parse_matrix(t_data *data, char **argv)
{
    t_list  *rows;
    int     fd;

    fd = my_open(data, argv);
    rows = ft_get_all_rows(data, fd);
    data->mtrx.matrix = my_d_array_int_calloc(data, fd);
    data->mtrx.colors = my_d_array_int_calloc(data, fd);
    ft_fill_matrix(data, rows, fd);
    ft_lstclear(&rows, &free);
    close(fd);
}
