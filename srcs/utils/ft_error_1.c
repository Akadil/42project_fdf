/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:21:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:12:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clean.h"
#include "ft_data.h"
#include "ft_libft.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

void	ft_error(void)
{
	ft_printf_stderr("%s\n", strerror(errno));
}

void	ft_perror(char *str)
{
	perror(str);
}

void	ft_merror(char *str, char *param)
{
	ft_printf_stderr(str, param);
}

void	ft_perror_clean_exit(t_data *trash, char *str)
{
	ft_clean(trash);
	ft_perror(str);
	exit(-1);
}

void	ft_merror_clean_exit(t_data *trash, char *str, char *param)
{
	ft_clean(trash);
	ft_merror(str, param);
	exit(-1);
}
