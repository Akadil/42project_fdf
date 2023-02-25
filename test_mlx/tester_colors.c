/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:08:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/25 19:01:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main(void)
{
    int my_color;

    my_color = create_trgb(255, 255, 255);
    printf("My color is %d\n", my_color);
    printf("The red %d\n", get_r(my_color));
    printf("The green %d\n", get_g(my_color));
    printf("The blue %d\n", get_b(my_color));
    printf("The transparency %d\n", get_t(my_color));

    return (0);
}
