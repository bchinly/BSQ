/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 03:09:47 by bchin             #+#    #+#             */
/*   Updated: 2016/11/16 22:01:07 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		print_list(t_node *begin_list)
{
	t_node	*link;

	link = begin_list;
	if (!link)
		return ;
	ft_putchar(link->data);
	while (link->next)
	{
		link = link->next;
		ft_putchar(link->data);
	}
}

void		print_array(t_node **begin_list, int height)
{
	int		i;

	i = 1;
	while (i < height)
	{
		print_list(begin_list[i]);
		i++;
	}
}

void		mr_list(t_node *begin_list)
{
	t_node		**list_array;
	int			height;
	int			width;
	t_square	*square;
	char		ebf[3];

	ebf[0] = 'a';
	ebf[1] = 'b';
	ebf[2] = 'c';
	square = create_square();
	height = get_height(begin_list);
	width = get_width(begin_list);
	list_array = (t_node**)malloc(sizeof(t_node*) * height);
	fill_listarray(list_array, begin_list, height);
	get_ids(list_array, ebf);
	assign_coordinate(list_array, height, width, ebf[1]);
	find_square(list_array, square, 1, height);
	draw_square(list_array, ebf[2], square->size, square->x, square->y);
	print_array(list_array, height);
}
