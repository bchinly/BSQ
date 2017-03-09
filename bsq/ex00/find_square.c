/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 02:57:14 by jinfeld           #+#    #+#             */
/*   Updated: 2016/11/16 19:48:05 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_node	*move_horiz(t_node *list, int mv)
{
	int move;

	move = 0;
	while (move < mv)
	{
		list = list->next;
		move++;
	}
	return (list);
}

void	set_square(t_node *current, t_square *square, int sqind)
{
	if (sqind > square->size)
	{
		square->size = sqind;
		square->x = current->x;
		square->y = current->y;
	}
}

int		square_check(int *sjmh, t_node **listarray, t_square *square, int i)
{
	int		j;
	int		sqind;
	int		height;
	t_node	*verthead;

	j = sjmh[1];
	sqind = sjmh[0];
	height = sjmh[3];
	while (j < height && sqind > square->size && (height - i) > square->size)
	{
		verthead = listarray[j];
		listarray[j] = move_horiz(listarray[j], sjmh[2]);
		sqind = square_index_check(sqind, listarray[j]->index, i, j);
		if (sqind == (j - i) || sqind == (j - i) + 1)
		{
			listarray[j] = verthead;
			break ;
		}
		listarray[j] = verthead;
		j++;
	}
	return (sqind);
}

void	find_square(t_node **listarray, t_square *square, int i, int height)
{
	t_node	*verthead;
	t_node	*current;
	int		sjmh[4];
	int		sqind;

	sjmh[2] = 0;
	sjmh[3] = height;
	verthead = listarray[i];
	current = listarray[i];
	while (current->data != '\n')
	{
		sjmh[1] = i;
		sjmh[0] = current->index;
		sqind = sjmh[0];
		sqind = square_check(sjmh, listarray, square, i);
		if (height - i < sqind)
			sqind = height - i;
		set_square(current, square, sqind);
		current = current->next;
		sjmh[2] += 1;
	}
	if ((i + 1) < height)
		find_square(listarray, square, i + 1, height);
}
