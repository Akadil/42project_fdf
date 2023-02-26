/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:21:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/26 18:44:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "ft_libft.h"

void	ft_strerror(void)
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
