/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresemham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:48:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/13 20:48:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// void	bresenhams(t_data *data, int x1, int y1, int x2, int y2)
// {
// 	int	err;
// 	int	e;
// 	int	x;
// 	int	y;

// 	x = x1;
// 	y = y1;
// 	err = ft_abs(x2, x1) - ft_abs(y2, y1);
// 	while (x != x2 || y != y2)
// 	{
// 		ft_pixel_put(data, x, y, ft_color(data, x, y, (x - x1) / (x2 - x1)));
// 		e = 2 * err;
// 		if (e > -1 * ft_abs(y2, y1))
// 		{
// 			err -= ft_abs(y2, y1);
// 			x += ft_slope(x1, x2);
// 		}
// 		if (e < ft_abs(x2, x1))
// 		{
// 			err += ft_abs(x2, x1);
// 			y += ft_slope(y1, y2);
// 		}
// 	}
// 	ft_pixel_put(data, x, y, ft_color(data, x, y, (x - x1) / (x2 - x1)));
// }
