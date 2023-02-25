/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:57:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/25 18:27:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_coef
{
    int     alpha; 
    int     beta;
    int     grid;
    int     attitude;
    int     x_offset;
    int     y_offset;
    int     proj_model;
    int     color;
}   t_coef;


typedef struct s_data{

    // MLX info
    void *mlx_ptr;
    void *win_ptr;

    t_img	img;
    
    // Matrix info
    int   **matrix;
    int   mtrx_length;
    int   mtrx_height;
    int     z_max;
    
    // Scaling info
    t_coef  coef;

} t_data;

#endif