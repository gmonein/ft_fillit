/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 04:49:58 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/27 04:50:49 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_data		ft_xy_f(void)
{
	t_data	data;

	data.x1 = 0;
	data.x2 = 1;
	data.x3 = 1;
	data.x4 = 2;
	data.y1 = 0;
	data.y2 = 0;
	data.y3 = 1;
	data.y4 = 0;
	data.len = 0;
	data.height = 3;

	return(data);
}

t_data		ft_xy_g(void)
{
	t_data	data;

	data.x1 = 0;
	data.x2 = 1;
	data.x3 = 1;
	data.x4 = 2;
	data.y1 = 1;
	data.y2 = 0;
	data.y3 = 1;
	data.y4 = 1;
	data.len = 2;
	data.height = 3;

	return(data);
}

t_data		ft_xy_h(void)
{
	t_data	data;

	data.x1 = 0;
	data.x2 = 0;
	data.x3 = 1;
	data.x4 = 1;
	data.y1 = 1;
	data.y2 = 2;
	data.y3 = 0;
	data.y4 = 1;
	data.len = 3;
	data.height = 2;

	return(data);
}

t_data		ft_xy_i(void)
{
	t_data	data;

	data.x1 = 0;
	data.x2 = 1;
	data.x3 = 1;
	data.x4 = 2;
	data.y1 = 0;
	data.y2 = 0;
	data.y3 = 1;
	data.y4 = 1;
	data.len = 2;
	data.height = 3;

	return(data);
}

t_data		ft_xy_j(void)
{
	t_data	data;

	data.x1 = 0;
	data.x2 = 0;
	data.x3 = 1;
	data.x4 = 2;
	data.y1 = 0;
	data.y2 = 1;
	data.y3 = 0;
	data.y4 = 0;
	data.len = 3;
	data.height = 2;

	return(data);
}
