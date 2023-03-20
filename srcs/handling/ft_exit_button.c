/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:58:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/20 20:29:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_clean.h"
#include <stdlib.h>

int	ft_handle_exit(t_data *data)
{
	ft_clean(data);
	exit (0);
}
