/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:55:17 by jinfeld           #+#    #+#             */
/*   Updated: 2016/11/16 19:55:23 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_node
{
	char			data;
	int				x;
	int				y;
	int				index;
	struct s_node	*next;
}					t_node;
typedef struct		s_square
{
	int				size;
	int				x;
	int				y;
}					t_square;
void				print_fail(void);
void				ft_putchar(char c);
void				print_list(t_node *begin_list);
int					get_width(t_node *begin_list);
int					get_height(t_node *begin_list);
int					read_files(char *argv, t_node **begin_list,
					t_node **tail_list);
t_node				*create_node(char c);
void				push_node(t_node **begin_list, t_node **tail_list, char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				fill_listarray(t_node **listarray,
					t_node *list, int height);
int					get_index(t_node *begin_list, char blocker);
void				assign_coordinate(t_node **listarray,
					int height, int width, char blocker);
void				find_square(t_node **listarray,
					t_square *square, int i, int height);
int					square_check (int *sjmh, t_node **listarray,
					t_square *square, int i);
void				set_square(t_node *current, t_square *square, int sqind);
t_square			*create_square(void);
t_node				*move_horiz(t_node *list, int mv);
void				draw_square(t_node **listarray, char fill,
					int size, int x, int y);
void				print_array(t_node **begin_list, int height);
void				mr_list(char *argv, t_node *begin_list, t_node *tail_list);
int					square_index_check(int sqind, int dex, int i, int j);
void				get_ids(t_node **listarray, char *ids);
int					get_index(t_node *begin_list, char blocker);

#endif
