/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/09 12:30:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_libft.h"

/*
    Used functions for ft_get_rows()
*/
static void	ft_close_clear_serror(t_data *_data, t_list *_head, int _fd);
static void	ft_close_clear_merror(t_data *_data, t_list *_head, int _fd);

/*
    Goal: Retrieve the row strings from the file and save it in linked list
*/
t_list	*ft_get_rows(t_data *data, int fd)
{
	t_list	*head;
	t_list	*temp;
	char	*str;

	head = NULL;
	str = get_next_line(fd, 0);
	while (str)
	{
		temp = ft_lstnew(str);
		if (!temp)
			ft_close_clear_error(data, head, fd);
		ft_lstadd_back(&head, temp);
		str = get_next_line(fd, 0);
	}
	get_next_line(0, 1);
	if (!head)
		ft_close_clear_merror(data, head, fd);
	data->mtrx.height = ft_lstsize(head);
	return (head);
}

/*
    ----------------------------------------------------------
    ------------------ Utils files ---------------------------
    ----------------------------------------------------------
*/
static void	ft_close_clear_serror(t_data *_data, t_list *_head, int _fd)
{
	close(_fd);
	ft_lstclear(&_head, &free);
	ft_strerror_clean_exit(_data, "Parsing the file");
}

static void	ft_close_clear_merror(t_data *_data, t_list *_head, int _fd)
{
	close(_fd);
	ft_lstclear(&_head, &free);
	ft_merror_clean_exit(_data, "The file is empty", NULL);
}
