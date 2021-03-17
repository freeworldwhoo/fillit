/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:10:46 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/12 21:30:34 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*go(int fd)
{
	char	buf[22];
	char	*k;
	int		i;

	k = ft_strnew(0);
	i = read(fd, buf, 22);
	buf[i] = '\0';
	k = ft_strjoin(k, buf);
	while (i != 0)
	{
		i = read(fd, buf, 22);
		buf[i] = '\0';
		k = ft_strjoin(k, buf);
	}
	return (k);
}

int		cw(char const *s)
{
	int i;
	int j;
	int b;

	i = 0;
	j = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (b == 0)
				b = 1;
			else
			{
				j++;
				b = 0;
			}
		}
		else
			b = 0;
		i++;
	}
	return (j + 1);
}

char	**ft_rsplit(char *str)
{
	char	**res;
	int		i;
	int		j;

	j = cw(str);
	res = malloc(sizeof(char *) * (j + 1));
	i = 0;
	while (i < j - 1)
	{
		res[i++] = ft_strsub(str, 0, ft_strstr(str, "\n\n") - str + 1);
		str = ft_strstr(str, "\n\n") + 2;
	}
	res[i] = ft_strdup(str);
	res[j] = NULL;
	return (res);
}

int		ft_inttet(char *tet)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (tet[i])
	{
		if (tet[i] == '.')
			m = m * 2;
		else if (tet[i] == '#')
			m = m * 2 + 1;
		i++;
	}
	return (m);
}
