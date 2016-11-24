/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:54:22 by jpeguet           #+#    #+#             */
/*   Updated: 2016/11/24 13:05:03 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static unsigned short		*tab_tetri_valid(void)
{
	unsigned short		*tetri_valid;

	tetri_valid = (unsigned short *)malloc(sizeof(unsigned short) * 19);
	tetri_valid[19] = '\0';
	tetri_valid[0] = 0xF000;
	tetri_valid[1] = 0x8888;
	tetri_valid[2] = 0xCC00;
	tetri_valid[3] = 0x4E00;
	tetri_valid[4] = 0xE400;
	tetri_valid[5] = 0x8C80;
	tetri_valid[6] = 0x4C40;
	tetri_valid[7] = 0x6C00;
	tetri_valid[8] = 0x8C40;
	tetri_valid[9] = 0xC880;
	tetri_valid[10] = 0xC600;
	tetri_valid[11] = 0xE200;
	tetri_valid[12] = 0x4C80;
	tetri_valid[13] = 0x88C0;
	tetri_valid[14] = 0x2E00;
	tetri_valid[15] = 0xC440;
	tetri_valid[16] = 0xE800;
	tetri_valid[17] = 0x44C0;
	tetri_valid[18] = 0x8E00;
	return (tetri_valid);
}

static unsigned short		*len_tetri_valid(void)
{
	unsigned short		*len_valid;

	len_valid = (unsigned short *)malloc(sizeof(unsigned short) * 19);
	len_valid[19] = '\0';
	len_valid[0] = 4;
	len_valid[1] = 1;
	len_valid[2] = 2;
	len_valid[3] = 3;
	len_valid[4] = 2;
	len_valid[6] = 2;
	len_valid[7] = 3;
	len_valid[8] = 2;
	len_valid[9] = 3;
	len_valid[10] = 2;
	len_valid[11] = 2;
	len_valid[12] = 3;
	len_valid[13] = 2;
	len_valid[14] = 3;
	len_valid[15] = 2;
	len_valid[16] = 3;
	len_valid[17] = 2;
	len_valid[18] = 3;
	return (len_valid);
}

static unsigned short		*height_tetri_valid(void)
{
	unsigned short	*height_valid;

	height_valid = (unsigned short *)malloc(sizeof(unsigned short) * 19);
	height_valid[19] = '\0';
	height_valid[0] = 1;
	height_valid[1] = 4;
	height_valid[2] = 2;
	height_valid[3] = 2;
	height_valid[4] = 2;
	height_valid[5] = 3;
	height_valid[6] = 3;
	height_valid[7] = 2;
	height_valid[8] = 3;
	height_valid[9] = 2;
	height_valid[10] = 3;
	height_valid[11] = 3;
	height_valid[12] = 2;
	height_valid[13] = 3;
	height_valid[14] = 2;
	height_valid[15] = 3;
	height_valid[16] = 2;
	height_valid[17] = 3;
	height_valid[18] = 2;
	return (height_valid);
}

t_list_valid  *ft_list_valid(int i)
{
	t_list_valid	*vlist;
	t_list_valid	*tmp;
	unsigned short	*tetri;
	unsigned short	*height;
	unsigned short	*len;

	tetri = tab_tetri_valid();
	height = height_tetri_valid();
	len = len_tetri_valid();
	vlist = (t_list_valid *)malloc(sizeof(t_list_valid));
	tmp = vlist;
	while (tetri[i] != '\0')
	{
		tmp->tetri = tetri[i];
		tmp->lenght = len[i];
		tmp->height = height[i];
		tmp->next = (t_list_valid *)malloc(sizeof(t_list_valid));
		tmp = tmp->next;
		i++;
	}
	free(tetri);
	free(height);
	free(len);
	return (vlist);
}

#include <stdio.h>
int			main()
{
	t_list_valid	*lst;

	lst = ft_list_valid(0);
	while (lst->next != NULL)
	{
		printf("tetri = %hu\n len = %hu\n height = %hu\n", lst->tetri, lst->lenght, lst->height);
		lst = lst->next;
	}
	printf("tetri = %hu\n len = %hu\n height = %hu\n", lst->tetri, lst->lenght, lst->height);
	return (0);
}
