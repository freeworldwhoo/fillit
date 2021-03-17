/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:47:45 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/13 01:56:34 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_ver(size_t ***t, int i, int m, int *n)
{
	int		j;
	size_t	*k;
	int		index[3];

	j = 0;
	k = (size_t *)malloc(sizeof(size_t) * 4);
	while (j < 4)
		k[j++] = 0;
	j = 0;
	index[0] = i;
	index[2] = m;
	while (j <= i)
	{
		index[1] = j;
		put(&k, &((*t)[j]), n, index);
		if (k[0] + k[1] + k[2] + k[3] == 0)
		{
			free(k);
			return (0);
		}
		j++;
	}
	free(k);
	return (1);
}

int	backtrack(size_t ***t, int *n, int m, int f)
{
	int i;

	i = 0;
	while (i < f && i > -1)
	{
		if (get_ver(t, i, m, n) == 1)
			i++;
		else
		{
			fit(&((*t)[i]), n[i], m);
			while ((*t)[i][(m * m) / 64] >> ((m * m) % 64) == 0)
				bit_shift(&((*t)[i]), 1);
			i--;
		}
	}
	if (i == -1)
		return (0);
	else
		return (1);
}
