/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/25 19:53:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <fcntl.h>
#include <stdlib.h>

void    ft_parse(char **argv, t_data *my_data)
{
    char    
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        printf("Error! handle\n");
    ft_check_the_map(fd);
}

void    ft_check_the_map(int fd)
{
    
}


void    ft_parse2(char **argv, t_data *my_data)
{
    char    *my_str;
    char    **str_array;
    int     fd;
    int     i;
    int     j;

    fd = open(argv[1], O_RDONLY);
    my_str = get_next_line(fd, 0);
    i = 0;
    while (my_str)
    {
        str_array = ft_split(my_str, ' ');
        j = 0;
        while (str_array && str_array[j])
        {
            my_data->matrix[i][j] = ft_atoi(str_array[j]);
            free (str_array[j]);
            j++;
        }
        i++;
        free (my_str);
        my_str = get_next_line(fd, 0);
    }
    get_next_line(fd, 1);
    close(fd);
}