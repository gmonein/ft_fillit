/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 01:26:19 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/28 23:51:43 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

	tmp = lst;
	lst = lst->next;
	while (tmp->next != NULL)
	{
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
		write(1, "\n", 1);
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
	if (tetris->x + tetris->data.len > size)
		return (0);
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
	while (tetris->x != size && tetris->y != size)
	{
		if (ft_can_i(tab, tetris, size))
			return (1);
		if (tetris->x == size)
		{
			if(tetris->x == size && tetris->y == size)
				return (0);
			tetris->x = 0;
			tetris->y++;
		}
		tetris->x++;
		printf("x = %d\nsize = %d\n", tetris->x, size);
	}
			printf("\tcan I ? end\n");
	return (0);
}

unsigned int		*solver(unsigned int *tab, t_list *tetris, int size)
{
	while (tetris->next != NULL)
	{
		if (ft_find_place(tab, tetris, size) == 0)
		{
			printf("no place\n");
			tetris->x = 0;
			tetris->y = 0;
			solver(tab, tetris, size + 1);
		}
		else
		{
			printf("placed\n");
			ft_place(tab, *tetris);
			tetris = tetris->next;
		}
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	t_list			*lst;
	t_list			*tmp;
	unsigned int	*ul_tetris;
	short			us_tetris;
	unsigned int	*tab;
	int				i;

	i = 0;
	tab = ft_setmap();
	printf("1\n");
	lst = ft_new_fill(argv[1]);
	printf("2\n");
	ft_set_data_two(lst);
	printf("3\n");
	ft_make_ul(lst);
	printf("4\n");
	ft_make_past(lst);
	printf("5\n");
	ft_list_init(lst);
	printf("6\n");
	if (!(ft_check_list(lst)))
		return (0);
	printf("7\n");
	tab = solver(tab, lst, 6);
	while (i < 32)
	{
		ft_print_ul(tab[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
