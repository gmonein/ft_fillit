/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <gmonein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 07:14:20 by gmonein           #+#    #+#             */
/*   Updated: 2016/11/29 03:17:13 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define US		unsigned short
# define UL		unsigned long
# define UI		unsigned int
# define ULM	0x80000000
# define MALLOC_ERROR	"Memory allocation failed\n"
# define INVALID_MAP	"Invalid tetrinos format\n"
# define CARIOT_RETURN	"Too many //n at the end file\n"
# define TOO_SHORT_LEN	"File len less than 20\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct				s_data
{
	unsigned short			x1;
	unsigned short			y1;
	unsigned short			x2;
	unsigned short			y2;
	unsigned short			x3;
	unsigned short			y3;
	unsigned short			x4;
	unsigned short			y4;
	unsigned short			len;
	unsigned short			height;
}							t_data;

typedef struct				s_list
{
	unsigned short			tetri;
	unsigned int			*itetri;
	unsigned int			x;
	unsigned int			y;
	unsigned int			f_x;
	unsigned int			f_y;
	struct s_data			data;
	char					id;
	int						last_pos;
	int						placed;
	struct s_list			*next;
	struct s_list			*past;
	struct s_list			*begin;
}							t_list;

typedef struct				s_list_valid
{
	unsigned short			tetri;
	struct s_list_valid		*next;
}							t_list_valid;

char				*ft_read(char *file);
char				*ft_strnew(size_t i);
char				*ft_strjoin(char *s1, char *s2);

unsigned short		*ft_read_fllit(char *file);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_new_fill(char *file);

void				ft_lstadd(t_list **alst, t_list *n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);

int  				ft_check_list(t_list *list);
int					ft_strlen(char *s);

void		ft_bzero(void *s, size_t n);
void	*ft_memset(void *ptr, int value, size_t num);
void		ft_list_init(t_list *lst);
int			ft_strlen_tab_ui(unsigned int *ui);
char		**ft_make_char_map(int size);
char		**ft_init_map(t_list *lst, int size, char **map);
void		ft_print_2D(char **map, int size);
void		ft_print_map(t_list *lst, int size);
t_data		ft_xy_s(void);
t_data		ft_xy_r(void);
t_data		ft_xy_q(void);
t_data		ft_xy_p(void);
t_data		ft_xy_o(void);
t_data		ft_xy_n(void);
t_data		ft_xy_m(void);
t_data		ft_xy_l(void);
t_data		ft_xy_k(void);
t_data		ft_xy_j(void);
t_data		ft_xy_i(void);
t_data		ft_xy_h(void);
t_data		ft_xy_g(void);
t_data		ft_xy_f(void);
t_data		ft_xy_e(void);
t_data		ft_xy_d(void);
t_data		ft_xy_c(void);
t_data		ft_xy_b(void);
t_data		ft_xy_a(void);
void		ft_set_data_one(t_list *list);
void		ft_set_data_two(t_list *list);
#endif
