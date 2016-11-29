/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 01:51:25 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/29 01:56:24 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_strlen_tab_ui(unsigned int *ui)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	j = 0;
	max = 0;
	while (ui[j] != 0)
	{
		while (ui[j] != 0)
		{
			ui[j] <<= 1;
			i++;
		}
		if (i > max)
			max = i;
		i = 0;
		j++;
	}
	if (j > (max + 1))
		max = j - 1;
	return (max);
}

char		**ft_make_char_map(int size)
{
	char	**map;
	int		b_size;
	int		i;

	b_size = size;
	map = (char **)malloc(sizeof(char *) * size + 2);
	map[size + 1] = NULL;
	while (size--)
	{
		map[size] = (char *)malloc(sizeof(char) * b_size + 1);
		map[size][b_size] = '\0';
		while (i < b_size)
		{
			map[size][i] = '.';
			i++;
		}
		i = 0;
	}
	return (map);
}

char		**ft_init_map(t_list *lst, int size, char **map)
{
	while (lst->next != NULL)
	{
		map[lst->y + lst->data.y1][lst->x + lst->data.x1] = lst->id;
		map[lst->y + lst->data.y2][lst->x + lst->data.x2] = lst->id;
		map[lst->y + lst->data.y3][lst->x + lst->data.x3] = lst->id;
		map[lst->y + lst->data.y4][lst->x + lst->data.x4] = lst->id;
		lst = lst->next;
	}
	return (map);
}

void		ft_print_2D(char **map, int size)
{
	int		i;
	int		j;
	int		b_size;

	i = 0;
	j = 0;
	b_size = size;
	while (size--)
	{
		write (1, map[i], b_size);
		write (1, "\n", 1);
		i++;
	}
}

void		ft_print_map(t_list *lst, int size)
{
	char		**map;

	map = ft_make_char_map(size);
	map = ft_init_map(lst, size, map);
	ft_print_2D(map, size);
	free(map);
}
