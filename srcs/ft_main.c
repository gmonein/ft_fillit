/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:42:47 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/02 19:41:31 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_list			*lst;
	unsigned int	*tab;
	int				size;

	if (argc != 2)
		return (0);
	tab = ft_setmap();
	lst = ft_new_fill(argv[1]);
	if (!(ft_check_list(lst)))
		return (0);
	ft_set_data_two(lst);
	ft_make_ul(lst);
	ft_make_past(lst);
	ft_list_init(lst);
	size = solver(tab, lst->begin, ft_map_min(lst->begin));
	ft_print_map(lst->begin, size - 1);
	return (0);
}
