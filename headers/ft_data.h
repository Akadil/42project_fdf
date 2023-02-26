/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:57:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/26 16:18:41 by akalimol         ###   ########.fr       */
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
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_coef
{
	int			alpha;
	int			beta;
	int			grid;
	int			attitude;
	int			x_offset;
	int			y_offset;
	int			proj_model;
}				t_coef;

typedef struct s_matrix
{
	int			**matrix;
	int			**colors;
	int			mtrx_length;
	int			mtrx_height;
	int			z_max;
}				t_matrix;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_matrix	mtrx;
	t_coef		coef;
}				t_data;

#endif