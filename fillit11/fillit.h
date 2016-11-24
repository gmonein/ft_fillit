/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <gmonein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 07:14:20 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/24 12:57:54 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define US unsigned short

# define MALLOC_ERROR	"Memory allocation failed\n"
# define INVALID_MAP	"Invalid tetrinos format\n"
# define CARIOT_RETURN	"Too many //n at the end file\n"
# define TOO_SHORT_LEN	"File len less than 20\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct				s_list
{
	unsigned short			tetri;
	unsigned short			x;
	unsigned short			y;
	unsigned short			x_tmp;
	unsigned short			y_tmp;
	unsigned short			lenght;
	unsigned short			height;
	struct s_list			*next;
}							t_list;

typedef struct				s_list_valid
{
	unsigned short			tetri;
	unsigned short			lenght;
	unsigned short			height;
	struct s_list_valid		*next;
}							t_list_valid;

char				*ft_read(char *file);
char				*ft_strnew(size_t i);
char				*ft_strjoin(char *s1, char *s2);

unsigned short		*ft_read_fllit(char *file);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_new_fill(char *file);
t_list_valid		*ft_list_valid(int i);

void				ft_lstadd(t_list **alst, t_list *n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);

int  				ft_check_list(t_list *list);
int					ft_strlen(char *s);

#endif
