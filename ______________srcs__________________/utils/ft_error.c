/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:21:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/28 14:51:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_data.h"
#include "ft_clean.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

void	ft_error(void)
{
	ft_printf_stderr("%s\n", strerror(errno));
}

void	ft_strerror(char *str)
{
	ft_printf_stderr("%s: %s\n", str, strerror(errno));
}

void	ft_perror(char *str)
{
	perror(str);
}

void	ft_merror(char *str, char *param)
{
	ft_printf_stderr(str, param);
}

void	ft_strerror_exit(char *str)
{
	ft_strerror(str);
	exit (-1);
}

void	ft_strerror_clean_exit(t_data *trash, char *str)
{
	ft_clean(trash);
	ft_strerror(str);
	exit (-1);
}

void	ft_perror_clean_exit(t_data *trash, char *str)
{
	ft_clean(trash);
	ft_perror(str);
	exit (-1);
}

void	ft_merror_clean_exit(t_data *trash, char *str, char *param)
{
	ft_clean(trash);
	ft_merror(str, param);
	exit (-1);
}
