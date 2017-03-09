/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:46:24 by jinfeld           #+#    #+#             */
/*   Updated: 2016/11/16 19:46:46 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	draw_square(t_node **listarray, char fill, int size, int x, int y)
{
	t_node	*head;
	t_node	*current;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	head = listarray[y];
	current = listarray[y];
	while (k < size)
	{
		i = 0;
		j = 0;
		head = listarray[y];
		current = listarray[y];
		while (i < x)
		{
			current = current->next;
			i++;
		}	
		while (j < size)
		{
			current->data = fill;
			current = current->next;
			j++;
		}
		listarray[y] = head;
		y++;
		k++;
	}
}
