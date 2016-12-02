/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <gmonein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 01:26:19 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/02 05:13:24 by jpeg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				ft_can_i(UI *tab, t_list *tetris, int size)
{
	if (tetris->x + tetris->data.len > size)
		return (-2);
	if (tetris->y + tetris->data.height > size)
		return (-1);
	if ((tab[tetris->y] & (tetris->itetri[0] >> tetris->x)) > 0)
		return (0);
	if ((tab[tetris->y + 1] & (tetris->itetri[1] >> tetris->x)) > 0)
		return (0);
	if ((tab[tetris->y + 2] & (tetris->itetri[2] >> tetris->x)) > 0)
		return (0);
	if ((tab[tetris->y + 3] & (tetris->itetri[3] >> tetris->x)) > 0)
		return (0);
	return (1);
}

unsigned int	*ft_place(UI *tab, t_list *tetris)
{
	if (tetris->itetri == 0)
		tetris->itetri = ft_short_to_ul(tetris->tetri);
	tab[tetris->y] += (tetris->itetri[0] >> tetris->x);
	tab[tetris->y + 1] += (tetris->itetri[1] >> tetris->x);
	tab[tetris->y + 2] += (tetris->itetri[2] >> tetris->x);
	tab[tetris->y + 3] += (tetris->itetri[3] >> tetris->x);
	tetris->placed = 1;
	return (tab);
}

int				ft_find_place(UI *tab, t_list *tetris, int size)
{
	int		res;

	while (tetris->x != size && tetris->y != size)
	{
		tetris->x++;
		if (res == -2)
		{
			tetris->x = 0;
			tetris->y++;
		}
		res = ft_can_i(tab, tetris, size);
		if (res == -1)
		{
			tetris->last_pos = 1;
			return (0);
		}
		if (res == 1)
			return (1);
	}
	tetris->last_pos = 1;
	return (0);
}

int				ft_isallplaced(t_list *lst)
{
	lst = lst->begin;

	while (lst->next != NULL)
	{
		if (lst->placed == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int				solver(unsigned int *tab, t_list *lst, int size)
{
	while (!(ft_isallplaced(lst) == 1))
	{
		while (ft_find_place(tab, lst, size) && lst->next != NULL)
		{
			tab = ft_place(tab, lst);
			if (lst->next != NULL)
				lst = lst->next;
			if (lst->next == NULL)
				return (size);
		}
		if (lst->past == NULL && lst->last_pos == 1)
		{
			tab = ft_erase_map(tab);
			ft_list_init(lst->begin);
			lst = lst->begin;
			size++;
		}
		if (lst->last_pos == 1 && lst->next != NULL)
		{
			lst->x = -1;
			lst->y = 0;
			lst = lst->past;
			tab = ft_del_tetris(tab, lst);
		}
	}
	return (size);
}
