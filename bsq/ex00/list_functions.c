/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:26:38 by biremong          #+#    #+#             */
/*   Updated: 2016/11/16 03:17:58 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_node		*create_node(char c)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = c;
	new_node->x = 0;
	new_node->y = 0;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

t_square	*create_square(void)
{
	t_square *new_sq;

	new_sq = (t_square*)malloc(sizeof(t_square));
	new_sq->size = 0;
	new_sq->x = 0;
	new_sq->y = 0;
	return (new_sq);
}

void		push_node(t_node **begin_list, t_node **tail_list, char c)
{
	t_node *current_node;
	t_node *new_node;

	new_node = create_node(c);
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
		*tail_list = new_node;
	}
	else
	{
		current_node = *tail_list;
		current_node->next = new_node;
		*tail_list = new_node;
	}
	return ;
}
