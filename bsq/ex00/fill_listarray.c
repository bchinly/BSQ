/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_listarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:39:32 by jinfeld           #+#    #+#             */
/*   Updated: 2016/11/16 19:51:35 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_listarray(t_node **listarray, t_node *list, int height)
{
	t_node	*head;
	t_node	*current;
	t_node	*swap;
	int		i;

	i = 0;
	head = list;
	current = list;
	while (current && i < height)
	{
		current = head;
		while (current->data != '\n')
			current = current->next;
		swap = current->next;
		current->next = NULL;
		listarray[i] = head;
		head = swap;
		i++;
	}
}

void	get_ids(t_node **listarray, char *ids)
{
	t_node	*current;

	current = listarray[0];
	while (current->next && current->data >= '0' && current->data <= '9')
		current = current->next;
	if (current->next != NULL && (current->data < '0' || current->data > '9'))
	{
		ids[0] = current->data;
		current = current->next;
		ids[1] = current->data;
		current = current->next;
		ids[2] = current->data;
	}
	return ;
}

int		get_index(t_node *begin_list, char blocker)
{
	t_node	*current_node;
	int		count;

	count = 0;
	if (!begin_list)
		return (count);
	current_node = begin_list;
	while (current_node && current_node->data != '\n'
			&& current_node->data != blocker)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}

void	assign_coordinate(t_node **listarray, int height,
							int width, char blocker)
{
	int		i;
	int		j;
	t_node	*current;

	i = 0;
	width = 0;
	current = 0;
	while (i < height)
	{
		current = listarray[i];
		j = 0;
		while (current->data != '\n')
		{
			current->x = j;
			current->y = i;
			current->index = get_index(current, blocker);
			current = current->next;
			j++;
		}
		i++;
	}
}
