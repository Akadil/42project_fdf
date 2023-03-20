/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_static_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:31:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/02 20:10:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_print(int array[2])
{
	array[0] = 1;
	printf("%d and %d\n", array[0], array[1]);
}

int	main(int argc, char **argv)
{
	int	fd[2];

	if (argc < 0)
		return (-1);
	fd[0] = atoi(argv[1]);
	fd[1] = atoi(argv[2]);
	ft_print(fd);
	printf("%d \n", fd[0]);
	return (0);
}
