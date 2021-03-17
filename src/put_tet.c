/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:52:06 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/13 01:46:23 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tor(size_t *b, int **s, int m)
{
	size_t	l;
	size_t	*n;
	int		i;

	n = (size_t *)malloc(sizeof(size_t) * 4);
	i = -1;
	while (++i < 4)
		n[i] = b[i];
	while (n[0] % ft_pow(2, m) == 0)
		bit_shift(&n, -m);
	l = n[0];
	(*s)[0] = co(l % ft_pow(2, m));
	(*s)[1] = 0;
	bit_shift(&n, -m);
	while (n[0] % ft_pow(2, m) != 0)
	{
		l = n[0];
		bit_shift(&n, -m);
		(*s)[1]++;
	}
	free(n);
	(*s)[2] = co(l % ft_pow(2, m));
}

int		tor1(size_t *b, int *s, int m)
{
	int *o;
	int i;

	o = (int *)malloc(sizeof(int) * 3);
	tor(b, &o, m);
	i = 0;
	while (i < 3)
	{
		if (o[i] != s[i])
		{
			free(o);
			return (0);
		}
		i++;
	}
	return (1);
}

void	sub_put(size_t **b, int *n, int *i)
{
	int *l;

	l = (int *)malloc(sizeof(int) * 3);
	if (i[0] == i[1] && (*b)[(i[2] * i[2]) / 64] >> ((i[2] * i[2]) % 64) != 0)
		fit(b, n[i[0]], i[2]);
	else if (i[0] == i[1])
	{
		tor(*b, &l, i[2]);
		bit_shift(b, -1);
		while ((*b)[0] + (*b)[1] + (*b)[2] + (*b)[3] != 1
				&& tor1(*b, l, i[2]) == 0)
			bit_shift(b, -1);
	}
	free(l);
}

void	sub_put1(size_t **a, size_t **k, int f)
{
	int z;

	z = -1;
	while (f != 4 && ++z < 4)
		(*k)[z] = 0;
	z = -1;
	while (++z < 4)
		(*a)[z] = (*k)[z];
}

void	put(size_t **a, size_t **b, int *n, int *i)
{
	int		z;
	int		f;
	size_t	*k;
	int		*l;

	sub_put(b, n, i);
	l = (int *)malloc(sizeof(int) * 3);
	tor(*b, &l, i[2]);
	k = (size_t *)malloc(sizeof(size_t) * 4);
	z = co((*a)[0]) + co((*a)[1]) + co((*a)[2]) + co((*a)[3]);
	or(*a, *b, &k);
	f = co(k[0]) + co(k[1]) + co(k[2]) + co(k[3]) - z;
	while (f != 4 && co((*b)[0]) + co((*b)[1]) + co((*b)[2])
			+ co((*b)[3]) == 4)
	{
		bit_shift(b, -1);
		while (tor1(*b, l, i[2]) == 0 && (*b)[0]
				+ (*b)[1] + (*b)[2] + (*b)[3] != 1)
			bit_shift(b, -1);
		or(*a, *b, &k);
		f = co(k[0]) + co(k[1]) + co(k[2]) + co(k[3]) - z;
	}
	sub_put1(a, &k, f);
	free(k);
	free(l);
}
