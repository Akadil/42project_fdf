/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/06 20:13:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_mlx.h"
#include <stdlib.h>
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

typedef struct s_line
{
	int x0;
	int	y0;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_line;

int	ft_compare(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

// Improve if colors are the same
int	ft_color(int x0, int x1, int x, int colors[2])
{
	float	z;

	if (colors[0] == colors[1])
		return (colors[0]);
	z = x - x0;
	z /= x1 - x0;
	z *= colors[1] - colors[0];
	z += colors[0];
	return (z);
}

void	ft_draw_line(t_data *data, int p0[2], int p1[2], int colors[2])
{
	t_line	line;

	line.x0 = p0[0];
	line.y0 = p0[1];
	line.dx = abs(p1[0] - line.x0);
	line.dy = abs(p1[1] - line.y0);
	line.sx = ft_compare(line.x0, p1[0]);
	line.sy = ft_compare(line.y0, p1[1]);
	line.err = line.dx - line.dy;
	while (line.x0 != p1[0] || line.y0 != p1[1])
	{
		my_mlx_pixel_put(data, line.x0, line.y0, ft_color(p0[0], p1[0], line.x0, colors));
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
	my_mlx_pixel_put(data, line.x0, line.y0, ft_color(line.x0, p1[0], line.x0, colors));
}

#include <stdio.h>
void	ft_transform(t_data *data, int ret[2], int x, int y)
{
	float	alpha_rad;
	float	beta_rad;
	float	pi;

	pi = 3.142857;
	alpha_rad = data->coef.alpha * (pi / 180.0);
	beta_rad = data->coef.beta * (pi / 180.0);

	// ret[0] = x * data->coef.grid * sin(alpha_rad) * sin(beta_rad);
	// ret[0] += y * data->coef.grid * cos(alpha_rad);
	// ret[0] += data->mtrx.matrix[x][y] * data->coef.attitude * sin(alpha_rad) * cos(beta_rad);
	// ret[0] += data->coef.y_offset;
	// ret[1] = x * data->coef.grid * cos(alpha_rad);
	// ret[1] -= data->mtrx.matrix[x][y] * data->coef.attitude * sin(beta_rad);
	// ret[1] += data->coef.x_offset;
	
	//printf("%f %f\n", cos(alpha_rad), sin(beta_rad));

	ret[1] = 0;
	ret[1] += cos(alpha_rad) * x * data->coef.grid;
	// ----------------------
	ret[1] += sin(alpha_rad) * data->mtrx.matrix[x][y] * data->coef.attitude;
	ret[1] += data->coef.x_offset;


	ret[0] = 0;
	ret[0] += cos(beta_rad) * y * data->coef.grid;
	// ----------------------
	ret[0] -= sin(beta_rad) * data->mtrx.matrix[x][y] * data->coef.attitude;
	ret[0] += data->coef.y_offset;
}

void	ft_inner_projection(t_data *data, int i, int j)
{
	int	curr_p[2];
	int	next_p[2];
	int	colors[2];

	curr_p[0] = 0;
	curr_p[1] = 0;
	next_p[0] = 0;
	next_p[1] = 0;
	colors[0] = data->mtrx.colors[i][j];
	ft_transform(data, curr_p, i, j);
	//printf("For %d and %d, values are %d %d\n", i, j, curr_p[0], curr_p[1]);
	if (j != data->mtrx.mtrx_length - 1)
	{
		colors[1] = data->mtrx.colors[i][j + 1];
		ft_transform(data, next_p, i, j + 1);
		ft_draw_line(data, curr_p, next_p, colors);
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	}
	if (i != data->mtrx.mtrx_height - 1)
	{
		colors[1] = data->mtrx.colors[i + 1][j];
		ft_transform(data, next_p, i + 1, j);
		ft_draw_line(data, curr_p, next_p, colors);
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	}
}

void	ft_render_projection(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mtrx.mtrx_height)
	{
		j = 0;
		while (j < data->mtrx.mtrx_length)
		{
			ft_inner_projection(data, i, j);
			j++;
		}
		i++;
	}
}
