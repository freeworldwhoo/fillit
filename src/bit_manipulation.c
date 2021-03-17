/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:46:26 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/12 23:37:05 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		shift(int n)
{
	while (n % 16 == 0)
		n = n >> 4;
	while (n % 2 + (n >> 4) % 2 + (n >> 8) % 2 + (n >> 12) % 2 == 0)
		n = n >> 1;
	return (n);
}

void	bit_shift(size_t **k, int s)
{
	size_t	div;
	int		i;
	size_t	div1;

	i = -1;
	div = 0;
	if (s > 0)
	{
		while (++i < 4)
		{
			div1 = (*k)[i] >> (64 - s);
			(*k)[i] = div + ((*k)[i] << s);
			div = div1;
		}
	}
	else
	{
		while (++i < 4)
		{
			div1 = (*k)[3 - i] << (64 + s);
			(*k)[3 - i] = div + ((*k)[3 - i] >> (-1 * s));
			div = div1;
		}
	}
}

int		shift1(int n)
{
	while (n / 4096 == 0)
		n = n << 4;
	while ((n >> 3) % 2 + (n >> 7) % 2 + (n >> 11) % 2 + (n >> 15) % 2 == 0)
		n = n << 1;
	return (n);
}

void	fit(size_t **k, int n, int m)
{
	int i;
	int l;

	l = 3;
	i = 0;
	n = shift1(n);
	(*k)[0] = 0;
	(*k)[1] = 0;
	(*k)[2] = 0;
	(*k)[3] = 0;
	while (i != m)
	{
		bit_shift(k, m);
		if (m > 4)
			(*k)[0] += ((n / ft_pow(2, l * 4)) << (m - 4));
		else
			(*k)[0] += (n / ft_pow(2, l * 4)) >> (4 - m);
		n = n % ft_pow(2, l * 4);
		if (l > 0)
			l--;
		i++;
	}
}
