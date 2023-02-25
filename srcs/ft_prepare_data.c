/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/25 19:32:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static void ft_parse(char **argv, t_data *my_data);
static void ft_set_coefficients(t_data *my_data);
static int ft_find_grid(t_data *my_data);
static int ft_find_attitude(t_data *my_data);

void    ft_prepare_data(int argc, char **argv, t_data *my_data)
{
    if (argc != 2)
    {
        printf("ERROR!\n");
        exit(-1);
    }
    ft_parse(argv,  my_data);
    ft_set_coefficients(my_data);
}

static void    ft_parse(char **argv, t_data *my_data)
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

/*
    typedef struct s_coef
    {
        int     alpha; 
        int     beta;
        int     grid_coef;
        int     attitude_coef;
        int     x_offset;
        int     y_offset;
        int     proj_model;
        int     color;
    }   t_coef;
*/

static void ft_set_coefficients(t_data *my_data)
{
    my_data->coef.alpha = 30;
    my_data->coef.beta = 30;
    my_data->coef.x_offset = 500;
    my_data->coef.y_offset = 250;
    my_data->coef.proj_model = 1;
    my_data->coef.grid = ft_find_grid(my_data);
    my_data->coef.attitude = ft_find_attitude(my_data);
}

static int ft_find_grid(t_data *my_data)
{
    int max_bw_row_col;

    max_bw_row_col = my_data->mtrx_height;
    if (max_bw_row_col < my_data->mtrx_length)
        max_bw_row_col = my_data->mtrx_length;
    return ((WINDOW_WIDTH - my_data->coef.x_offset * 2 ) / max_bw_row_col / sqrt(2));
}

static int ft_find_attitude(t_data *my_data)
{
    int z_max;
    int i;
    int j;
    
    z_max = -2147483648;
    i = 0;
    while (i < my_data->mtrx_height)
    {
        j = 0;
        while (i < my_data->mtrx_length)
        {
            if (my_data->matrix[i][j] > z_max)
                z_max = my_data->matrix[i][j];
            j++;
        }
        i++;
    }
    return ((WINDOW_HEIGHT - my_data->coef.y_offset * 2 ) / z_max);
}