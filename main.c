/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:55:59 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/22 14:17:01 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_list		*list;

	if (argc == 2 && (list = ft_new_fill(argv[1])) != NULL)
	{
		while (list->next != NULL)
		{
			printf("%hu\n", list->content->tetri);
			list = list->next;
		}
//		if (ft_check_list(list) == 1)
//			printf("Tetriminos valide");
//		else if (ft_check_list(list) == 0)
//			printf("Tetriminos invalide");
//		else
//			printf("erreur");
	}
	else if (argc == 1)
		printf("%s", "Met des arguemnts connard !");
	else if (argc > 2)
		printf ("%s", "Vaut mieux trop que pas asse ?");
	return (0);
}
