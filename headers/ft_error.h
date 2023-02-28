/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:22:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/27 20:39:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

/* Output error */
void	ft_error(void);
/* Output error with specifying the error */
void	ft_strerror(char *str);
/* Output error with error command*/
void	ft_perror(char *str);
/* Output the custom error */
void	ft_merror(char *str, char *param);
void	ft_strerror_exit(char *str);
void	ft_strerror_clean_exit(t_data *trash, char *str);
void    ft_perror_clean_exit(t_data *trash, char *str);
void	ft_merror_clean_exit(t_data *trash, char *str, char *param);

#endif