/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:18:18 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/13 02:54:24 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_readall(char *argv, int *len, int *dim)
{
	int		fd;
	char	**k;
	int		*l;
	char	*st;

	fd = open(argv, O_RDONLY);
	st = go(fd);
	*len = cw(st);
	close(fd);
	k = ft_rsplit(st);
	*dim = ft_sqrt(*len * 4);
	l = (int *)malloc(sizeof(int) * (*len));
	fd = 0;
	while (fd < *len)
	{
		ver(k[fd]);
		l[fd] = shift(ft_inttet(k[fd]));
		ver2(l[fd++]);
	}
	free(k);
	free(st);
	return (l);
}

void	ft_get_tet(size_t ***t, int *l, int dim, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		fit(&((*t)[i]), l[i], dim);
		j = 0;
		while (((*t)[i][(dim * dim) / 64]) >> ((dim * dim) % 64) == 0)
			bit_shift(&((*t)[i]), 1);
		i++;
	}
}

void	create(size_t ***t, int len)
{
	int i;

	i = 0;
	while (i < len)
		(*t)[i++] = (size_t *)malloc(sizeof(size_t) * 4);
}

void	do_all(char *argv)
{
	int		dim;
	int		len;
	size_t	**t;
	int		*l;

	l = ft_readall(argv, &len, &dim);
	if (len == 0 || len > 26)
		ft_exit(0);
	t = (size_t **)malloc(sizeof(size_t*) * len);
	create(&t, len);
	ft_get_tet(&t, l, dim, len);
	while (backtrack(&t, l, dim, len) == 0)
		ft_get_tet(&t, l, ++dim, len);
	ft_desplay(t, dim, len, 0);
	free(t);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (0);
	}
	do_all(argv[1]);
	return (0);
}
