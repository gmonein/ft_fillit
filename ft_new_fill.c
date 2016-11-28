/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:12:15 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/27 04:57:18 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				ft_error(int error_nb)
{
	if (error_nb == 1)
		write(1, INVALID_MAP, ft_strlen(INVALID_MAP));
	if (error_nb == 2)
		write(1, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
	if (error_nb == 4)
		write(1, CARIOT_RETURN, ft_strlen(CARIOT_RETURN));
	if (error_nb == 5)
		write(1, TOO_SHORT_LEN, ft_strlen(TOO_SHORT_LEN));
	return (-1);
}

static int			ft_valid(char c, int i)
{
	if ((i + 1) % 5 != 0 && c != '.' && c != '#')
		return (1);
	return (0);
}

unsigned short	ft_bits(char *s)
{
	int				i;
	int				j;
	int				cfor;
	unsigned short	res;

	i = 0;
	j = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '#' || s[i] == '.')
			res = res << 1;
		if (s[i] == '#')
			res = res + 1;
		i++;
		if ((s[i] != '\n' && (i + 1) % 5 == 0) || (ft_valid(s[i], i)) == 1)
			return (ft_error(1));
		if ((i + 1) % 5 == 0)
			i++;
	}
	while ((res & 0x8888) == 0)
		res = res << 1;
	while ((res & 0xF000) == 0)
		res = res << 4;
	return (res);
}

t_list			*ft_new_fill(char *file)
{
	int				fd;
	char			buf[21];
	int				readed;
	t_list			*lst;
	t_list			*tmp;

	fd = open(file, O_RDONLY);
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp = lst;
	readed = 42;
	while (readed == 42 || readed == 1)
	{
		readed = read(fd, buf, 20);
		buf[20] = '\0';
		if ((lst->tetri = ft_bits(buf)) == 65535)
			return (NULL);
		lst->next = (t_list *)malloc(sizeof(t_list));
		lst = lst->next;
		lst->next = NULL;
		readed = read(fd, buf, 1);
		buf[1] = '\0';
	}
	close(fd);
	return ((!(readed == 0) && ft_error(5)) ? NULL : tmp);
}
