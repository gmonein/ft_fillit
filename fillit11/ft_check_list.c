/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:54:22 by jpeguet           #+#    #+#             */
/*   Updated: 2016/11/22 10:34:23 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


unsigned short *tab_tetri_valid(void)
{
  unsigned short *tab_valid;

  tab_valid = (US *)malloc(sizeof(US) * 19);
  tab_valid[18] = '\0';
  tab_valid[0] = 0xF000;
  tab_valid[1] = 0x8888;
  tab_valid[2] = 0xCC00;
  tab_valid[3] = 0x4E00;
  tab_valid[4] = 0xE400;
  tab_valid[5] = 0x8C80;
  tab_valid[6] = 0x4C40;
  tab_valid[7] = 0x6C00;
  tab_valid[8] = 0x8C40;
  tab_valid[9] = 0xC880;
  tab_valid[10] = 0xC600;
  tab_valid[11] = 0xE200;
  tab_valid[12] = 0x4C80;
  tab_valid[13] = 0x88C0;
  tab_valid[14] = 0x2E00;
  tab_valid[15] = 0xC440;
  tab_valid[16] = 0xE800;
  tab_valid[17] = 0x44C0;
  tab_valid[18] = 0x8E00;
  return (tab_valid);
}

int  ft_check_list(t_list *list)
{
	US		*tab;
	int		valid;
	int		i;

	tab = tab_tetri_valid();
	while (list->next != NULL)
	{
		while (tab[i])
		{
			if ((tab[i] | list->content->tetri) == tab[i])
				valid = 1;
			i++;
		}
		if (valid == 0)
			return (0);
		valid = 0;
	}
	return (1);
}
