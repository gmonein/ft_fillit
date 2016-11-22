/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:54:22 by jpeguet           #+#    #+#             */
/*   Updated: 2016/11/22 13:48:26 by jpeguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static unsigned short tab_tetri_valid(void)
{
  unsigned short *tetri_val[18];

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

static int *len_tetri_valid(void)
{
  int   len_valid[18];

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

static int *height_tetri_valid(void)
{
  int   height_valid[18];

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

t_list_valid  *ft_list_valid(void)
{
  int i;

  while (t_list_valid->nxt != NULL)
  {
    i = 0;
    while (i != 19)
    {
      t_list_valid->data.tetri = tetri_valid[i];
      t_list_valid->data.len = len_valid[i];
      t_list_valid->data.height = height_valid[i];
    }
    t_list_valid = t_list_valid->nxt;
  }
  return (t_list_valid);
}
