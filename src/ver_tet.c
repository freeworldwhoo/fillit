/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:34:04 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/13 02:36:26 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(int i)
{
	ft_putstr("error\n");
	exit(i);
}

void	ver(char *f)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	s = ft_strsplit(f, '\n');
	i = -1;
	k = 0;
	if (ft_strlen(f) != 20)
		ft_exit(0);
	while (s[++i])
	{
		j = 0;
		if (ft_strlen(s[i]) != 4)
			ft_exit(0);
		while (j < 4)
		{
			if (s[i][j] != '.' && s[i][j] != '#')
				ft_exit(0);
			k = k + (s[i][j++] == '#');
		}
	}
	if (k != 4)
		ft_exit(0);
}

void	ver2(int n)
{
	if (n != 4369 && n != 15 && n != 275 && n != 23
			&& n != 547 && n != 113 && n != 116 && n != 802
			&& n != 71 && n != 785 && n != 305 && n != 39
			&& n != 562 && n != 114 && n != 99 && n != 561
			&& n != 54 && n != 306 && n != 51)
		ft_exit(0);
}
