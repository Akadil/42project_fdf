/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/09 13:28:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_libft.h"
#include <fcntl.h>

void	ft_find_width(t_data *data, t_list *rows)
{
    char	*line;
    int		width;
    int		i;

    i = 0;
    width = 0;
    line = rows->content;
    while (line[i])
    {
		if (line[i] == ' ')
			width++;
        i++;
    }
	width++;
	data->mtrx.width = width;
}

int	hex_to_decimal(char* hex_string) 
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

int    my_open(t_data *_my_data, char **_argv)
{
    int fd;

    fd = open(_argv[1], O_RDONLY);
    if (fd == -1)
        ft_perror_clean_exit(_my_data, _argv[1]);
    return (fd);
}

void	ft_close_error(t_data *trash, char *str, int fd)
{
	close (fd);
	ft_strerror_clean_exit(trash, str);
}

/*
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
}*/