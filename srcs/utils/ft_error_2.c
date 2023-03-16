/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:10:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:12:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clean.h"
#include "ft_data.h"
#include "ft_libft.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

void	ft_strerror(char *str)
{
	ft_printf_stderr("%s: %s\n", str, strerror(errno));
}

void	ft_strerror_exit(char *str)
{
	ft_strerror(str);
	exit(-1);
}

void	ft_strerror_clean_exit(t_data *trash, char *str)
{
	ft_clean(trash);
	ft_strerror(str);
	exit(-1);
}
