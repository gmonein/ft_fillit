/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 01:26:19 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/29 01:07:24 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_map_min(t_list *lst)
{
	int		i;

	i = 0;
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void		ft_print_ul(unsigned int num)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if ((num & 0x80000000) > 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
		num <<= 1;
	}
}

unsigned int		*ft_short_to_ul(unsigned short tetris)
{
	int				i;
	int				j;
	unsigned int	*tab;

	i = 0;
	j = 0;
	tab = (unsigned int *)malloc(sizeof(unsigned int) * 5);
	while (i < 4)
		tab[i++] = 0;
	tab[0] = ((tetris & 0xF000) << 16);
	tab[1] = ((tetris & 0x0F00) << 20);
	tab[2] = ((tetris & 0x00F0) << 24);
	tab[3] = ((tetris & 0x000F) << 28);
	tab[4] = 0;
	return (tab);
}

void				ft_make_past(t_list *lst)
{
	t_list		*tmp;
	t_list		*begin;
	char		id;

	id = 'A';
	begin = lst;
	tmp = lst;
	lst = lst->next;
	while (tmp->next != NULL)
	{
		tmp->id = id;
		id++;
		tmp->begin = begin;
		lst->past = tmp;
		lst = lst->next;
		tmp = tmp->next;
	}
}

void			ft_list_init(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst->x = 0;
		lst->y = 0;
		lst = lst->next;
	}
}

void		ft_make_ul(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst->itetri = (unsigned int *)malloc(sizeof(unsigned int) * 5);
		lst->itetri = ft_short_to_ul(lst->tetri);
		lst = lst->next;
	}
}

unsigned int		*ft_setmap(void)
{
	unsigned int	*tab;
	int				i;

	tab = (unsigned int *)malloc(sizeof(unsigned int) * 33);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 33)
		tab[i++] = 0;
	return (tab);
}

unsigned long	*ft_decal_tab(unsigned long *tab, int size, int h, char r_or_l)
{
	int		i;

	i = 0;
	while (i < h)
	{
		if (r_or_l == 'l')
			tab[i] <<= size;
		else
			tab[i] >>= size;
		i++;
	}
	return (tab);
}

int				ft_can_i(UI *tab, t_list *tetris, int size)
{
	if (tetris->x + tetris->data.len > size
		&& tetris->y + tetris->data.height > size)
		return (-3);
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

unsigned int	*ft_place(UI *tab, t_list tetris)
{
	unsigned int	*ui_tetri;

	ui_tetri = ft_short_to_ul(tetris.tetri);
	tab[tetris.y] += (ui_tetri[0] >> tetris.x);
	tab[tetris.y + 1] += (ui_tetri[1] >> tetris.x);
	tab[tetris.y + 2] += (ui_tetri[2] >> tetris.x);
	tab[tetris.y + 3] += (ui_tetri[3] >> tetris.x);
	return (tab);
}

int				ft_find_place(UI *tab, t_list *tetris, int size)
{
	int		res;
	while (tetris->x != size && tetris->y != size)
	{
		res = ft_can_i(tab, tetris, size);
		if (res == 1)
			return (1);
		else if (res == -1)
			return (-1);
		if (res == -2)
		{
			tetris->x = 0;
			tetris->y++;
		}
		if (res == -3)
			return (-3);
		tetris->x++;
	}
	return (0);
}

unsigned int			*solver(unsigned int *tab, t_list *tetris, int size)
{
	int		res;

	while (tetris->next != NULL)
	{
		res = ft_find_place(tab, tetris, size);
		if (res == 0 && tetris->next == NULL)
		{
			ft_list_init(tetris->begin);
			solver(tab, tetris->begin, size + 1);
		}
		else if (res == 0)
		{
			tetris->x = 0;
			tetris->y = 0;
			solver(tab, tetris->past, size);
		}
		else if (res == 1)
		{
			ft_place(tab, *tetris);
			tetris = tetris->next;
		}
	}
	return (tab);
}

int			strlen_tab_ui(unsigned int *ui)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	while (ui[i] != 0)
	{
		uii[i] <<= 1;
		i++;
	}
	return (i);
}

char		**ft_make_char_map(int size)
{
	char	**map;
	int		b_size;

	b_size = size;
	map = (char **)malloc(sizeof(char *) * size + 2);
	map[size + 1] = NULL;
	while (size--)
	{
		map[size] = (char *)malloc(sizeof(char) * size + 1);
		map[size][b_size] = '\0';
	}
	return (map);
}

char		**ft_init_map(t_list *lst, int size)
{
	char	**map;

	map = ft_make_char_map(size);
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

void		ft_print_2D(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i++])
	{
		write (1, map[i], ft_strlen(map[i]));
		write (1, "\n", 1);
	}
}

void		ft_print_map(t_list *lst, int size)
{
	char		**map;

	map = ft_make_char_map(size);
	map = ft_init_map(lst, size);
	ft_print_2D(map);
	free(map);
}

int		main(int argc, char **argv)
{
	t_list			*lst;
	t_list			*tmp;
	unsigned int	*ul_tetris;
	short			us_tetris;
	unsigned int	*tab;
	int				i;
	int				size;

	i = 0;
	tab = ft_setmap();
	lst = ft_new_fill(argv[1]);
	ft_set_data_two(lst);
	ft_make_ul(lst);
	ft_make_past(lst);
	ft_list_init(lst);
	if (!(ft_check_list(lst)))
		return (0);
	tab = solver(tab, lst, ft_map_min(lst));
//	while (i < 32)
//	{
//		ft_print_ul(tab[i]);
//		write(1, "\n", 1);
//		i++;
//	}
	ft_print_map(lst, size);
	return (0);
}
