/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_index_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:48:53 by jinfeld           #+#    #+#             */
/*   Updated: 2016/11/16 19:48:43 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		square_index_check(int sqind, int dex, int i, int j)
{
	if (dex < sqind)
	{
		if (dex <= j - i)
		{
			sqind = (j - i);
		}
		else
			sqind = dex;
	}
	return (sqind);
}
