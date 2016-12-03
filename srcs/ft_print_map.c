/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <gmonein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 01:51:25 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/03 01:41:15 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_make_char_map(int size)
{
	char	**map;
	int		b_size;
	int		i;

	i = 0;
	b_size = size;
	map = (char **)malloc(sizeof(char *) * size + 1);
	map[size + 1] = NULL;
	while (size != -1)
	{
		map[size] = (char *)malloc(sizeof(char) * b_size + 1);
		map[size][b_size] = '\0';
		while (i <= b_size)
		{
			map[size][i] = '.';
			i++;
		}
		i = 0;
		size--;
	}
	return (map);
}

static char		**ft_init_map(t_list *lst, char **map)
{
	while (lst->next != NULL && lst->x != -1)
	{
		map[lst->y + lst->data.y1][lst->x + lst->data.x1] = lst->id;
		map[lst->y + lst->data.y2][lst->x + lst->data.x2] = lst->id;
		map[lst->y + lst->data.y3][lst->x + lst->data.x3] = lst->id;
		map[lst->y + lst->data.y4][lst->x + lst->data.x4] = lst->id;
		lst = lst->next;
	}
	return (map);
}

static void		ft_print_twod(char **map, int size)
{
	int		i;
	int		j;
	int		b_size;

	i = 0;
	j = 0;
	b_size = size + 1;
	while (i <= size)
	{
		write(1, map[i], b_size);
		write(1, "\n", 1);
		i++;
	}
}

void			ft_print_map(t_list *lst, int size)
{
	char		**map;

	size--;
	map = ft_make_char_map(size);
	map = ft_init_map(lst, map);
	ft_print_twod(map, size);
	free(map);
}
