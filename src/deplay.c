/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:59:05 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/13 02:17:27 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	*ft_copy(size_t *n)
{
	size_t *k;

	k = (size_t *)malloc(sizeof(size_t) * 4);
	k[0] = n[0];
	k[1] = n[1];
	k[2] = n[2];
	k[3] = n[3];
	return (k);
}

void	sub_desplay(size_t **t, int j, int i, int *k)
{
	size_t	*a;
	int		f;
	int		o;

	a = ft_copy(t[j]);
	f = 0;
	while (f++ < i)
		bit_shift(&a, -1);
	o = a[0] % 2;
	free(a);
	if (o == 1)
	{
		ft_putchar('A' + j);
		*k = 1;
	}
}

void	ft_desplay(size_t **t, int dim, int len, int i)
{
	int j;
	int k;

	k = 0;
	if (i != dim * dim)
	{
		ft_desplay(t, dim, len, i + 1);
		j = 0;
		while (j < len)
		{
			sub_desplay(t, j, i, &k);
			j++;
		}
		if (k == 0)
			ft_putchar('.');
		if (i % dim == 0)
			ft_putchar('\n');
	}
}
