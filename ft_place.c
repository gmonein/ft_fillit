/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 01:26:19 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/29 03:59:43 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_map_min(t_list *lst)
{
	int		i;
	int		sqtr;

	i = 0;
	sqtr = 1;
	while (lst->next != NULL)
	{
		i = i + 4;
		lst = lst->next;
	}
	while ((sqtr * sqtr) < i)
		sqtr++;
	printf("i = %d\nsqtr = %d\n", i, sqtr);
	return (sqtr);
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
	lst->begin = NULL;
	lst = lst->next;
	while (tmp->next != NULL)
	{
		tmp->id = id;
		id++;
		tmp->placed = 0;
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
		lst->last_pos = 0;
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
		return (0);
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
		if (res == -2)
		{
			tetris->x = 0;
			tetris->y++;
		}
		if (res == -3)
			return (-1);
		tetris->x++;
	}
	tetris->last_pos = -1;
	return (-2);
}

unsigned int		*ft_del_tetris(t_list *tetris, unsigned int *tab)
{
	unsigned int	td[4];

	td[0] = 1;
	td[1] = 1;
	td[2] = 1;
	td[3] = 1;
	td[0] <<= 31 - (tetris->x + tetris->data.x1);
	td[1] <<= 31 - (tetris->x + tetris->data.x2);
	td[2] <<= 31 - (tetris->x + tetris->data.x3);
	td[3] <<= 31 - (tetris->x + tetris->data.x4);
	tab[0 + tetris->y] -= td[0];
	tab[1 + tetris->y] -= td[1];
	tab[2 + tetris->y] -= td[2];
	tab[3 + tetris->y] -= td[3];
	tetris->x = 0;
	tetris->y = 0;
	tetris->placed = 0;
	return (tab);
}

unsigned int				*ft_erase_map(unsigned int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

unsigned int			*solver(unsigned int *tab, t_list *tetris, int size)
{
	int		res;

	while (tetris->next != NULL)
	{
		res = ft_find_place(tab, tetris, size);
		printf("%d\n", res);
		if (res == 1)
		{
			printf("PLACED\n");
			ft_place(tab, *tetris);
			tetris = tetris->next;
		}
		if (res == -1 && tetris->begin != NULL)
		{
			printf("ONE TETRI ERASED\n");
			tab = ft_del_tetris(tetris, tab);
			tetris = tetris->begin;
			tetris->x++;
		}
		if ((res == -1 && tetris->begin == NULL) || res == -2)
		{
			printf("MAP ERASED\n");
			tab = ft_erase_map(tab);
			ft_list_init(tetris->begin);
			tetris = tetris->begin;
			size++;
		}
	}
	return (tab);
}
/*
unsigned int			*solver(unsigned int *tab, t_list *tetris, int size)
{
	int		res;

	while (tetris->next != NULL)
	{
		res = ft_find_place(tab, tetris, size);
		if (res == -1 && tetris->last_pos == -1)
		{
			printf("NEW MAP SIZE\n");
			solver(tab, tetris, size + 1);
		}
		else if (res == -1)
		{
			printf("BACK IN PAST\n");
			solver(tab, tetris->past, size);
		}
		else if (res == 1)
		{
			printf("PLACED\n");
			ft_place(tab, *tetris);
			tetris = tetris->next;
		}
		else if (res == 0)
		{
			printf("G RI1 FE\n");
		}
	}
	return (tab);
}
*/
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
		dprintf(1, "0\n");
	ft_set_data_two(lst);
		dprintf(1, "1\n");
	ft_make_ul(lst);
		dprintf(1, "2\n");
	ft_make_past(lst);
		dprintf(1, "3\n");
	ft_list_init(lst);
		dprintf(1, "4\n");
	if (!(ft_check_list(lst)))
		return (0);
		dprintf(1, "5\n");
	tab = solver(tab, lst, 1);
		dprintf(1, "6\n");
	while (i < 32)
	{
		ft_print_ul(tab[i]);
		write(1, "\n", 1);
		i++;
	}
		dprintf(1, "7\n");
	ft_print_map(lst, ft_strlen_tab_ui(tab));
		dprintf(1, "8\n");
	return (0);
}
