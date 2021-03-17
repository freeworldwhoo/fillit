/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:41:56 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/12 23:51:51 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_pow(int a, int b)
{
	if (b == 0)
		return (1);
	return (a * ft_pow(a, b - 1));
}

int		co(size_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		if (n % 2 == 1)
			i++;
		n = n >> 1;
	}
	return (i);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

void	or(size_t *a, size_t *b, size_t **k)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*k)[i] = a[i] | b[i];
		i++;
	}
}
