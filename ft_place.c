/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 01:26:19 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/01 18:43:20 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_map_min(t_list *lst)
{
	int		i;
	int		sqtr;
	int		min;

	min = 0;
	i = 0;
	sqtr = 1;
	if (lst->data.len > min)
		min = lst->data.len;
	if (lst->data.height > min)
		min = lst->data.height;
	while (lst->next != NULL)
	{
		i = i + 4;
		lst = lst->next;
	}
	while ((sqtr * sqtr) < i)
		sqtr++;
	if (min > sqtr)
		return (min);
	return (sqtr);
}

void		ft_print_ul(unsigned int num, int size)
{
	int		i;

	i = 0;
	while (i < 32 && i < size)
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

unsigned int	*ft_decal_tab(unsigned int *tab, int h, char r_or_l)
{
	int		i;

	i = 0;
	while (i < h)
	{
		if (r_or_l == 'l')
			tab[i] <<= 1;
		else
			tab[i] >>= 1;
		i++;
	}
	return (tab);
}

unsigned int	*ft_up_down(unsigned int *tab, int h, char h_or_d)
{
	int		i;

	while (tab[i] != 0)
		i++;
	while ((i - 1) != 0)
	{
		if (h_or_d == 'd')
			tab[i] = tab[i - 1];
		else
			tab[i - 1] = tab[i];
		i--;
	}
	if (h_or_d == 'd')
		tab[0] = 0;
	return (tab);
}

int				ft_can_i(UI *tab, t_list *tetris, int size)
{
//	if (tetris->x + tetris->data.len > size
//		&& tetris->y + tetris->data.height > size)
//		return (-3);
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

int			ft_find_place(UI *tab, t_list *tetris, int size)
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
		if (res == 1)
			return (1);
	}
	tetris->last_pos = 1;
	return (0);
}

void					ft_print_ul_tab(unsigned int *tab, int size)
{
	int		i;

	i = 0;
	while (i < 32 && i < size)
	{
		ft_print_ul(tab[i], size);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int			solver(unsigned int *tab, t_list *lst, int size)
{
	while (!(lst->placed == 1 && lst->next == NULL))
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
			printf("MAP UP");
			tab = ft_erase_map(tab);
			ft_list_init(lst->begin);
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

int		main(int argc, char **argv)
{
	t_list			*lst;
	t_list			*tmp;
	unsigned int	*ul_tetris;
	short			us_tetris;
	unsigned int	*tab;
	int				i;
	int				size;
	char			**test;
	int				i_test;
	int				j_test;

	i_test = 0;
	j_test = 0;
	test = (char **)malloc(sizeof(char *) * 5);
	test[4] = NULL;
	while (i_test < 4)
	{
		j_test = 0;
		test[i_test] = (char *)malloc(sizeof(char) * 5);
		while (j_test < 4)
		{
			test[i_test][j_test] = '.';
			j_test++;
		}
		test[i_test][4] = '\0';
		i_test++;
	}
	i = 0;
	tab = ft_setmap();
	lst = ft_new_fill(argv[1]);
	if (!(ft_check_list(lst)))
	{
		printf("INVALID TETRI");
		return (0);
	}
	ft_set_data_two(lst);
	ft_make_ul(lst);
	ft_make_past(lst);
	ft_list_init(lst);
	if (!(ft_check_list(lst)))
		return (0);
		dprintf(1, "5\n");
	size = solver(tab, lst->begin, ft_map_min(lst->begin));
		dprintf(1, "6\n");
		dprintf(1, "7\n");
	ft_print_map(lst->begin, size - 1);
		dprintf(1, "8\n");
	return (0);
}
