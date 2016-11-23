/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:54:22 by jpeguet           #+#    #+#             */
/*   Updated: 2016/11/23 12:27:14 by jpeguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  ft_check_list(t_list *list)
{
	t_list		*lst;
	int				valid;
	int				i;

	lst = ft_list_valid();
	while (list->nxt != NULL)
	{
		while (lst->nxt != NULL && valid != 1)
		{
			if (lst->data->tetri | list->content->tetri) == lst->data->tetri)
			{
				valid = 1;
				list->content->tetri = lst->data->tetri;
				list->content->lenght = lst->data->lenght;
				list->content->height = lst->data->height;
			}
			lst = lst->nxt;
		}
		if (valid == 0)
			return (0);
		valid = 0;
	}
	return (1);
}
