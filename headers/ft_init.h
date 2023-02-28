/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:56:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/27 12:36:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include <stdlib.h>
# include "ft_data.h"
# include "ft_error.h"

static void    ft_init_img(t_data *_data);
static void    ft_init_coef(t_data *_data);
static void    ft_init_matrix(t_data *_data);

#endif