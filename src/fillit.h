/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:09:28 by rnbou             #+#    #+#             */
/*   Updated: 2018/12/13 02:44:34 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

char	*go(int fd);
int		cw(char const *s);
char	**ft_rsplit(char *str);
int		ft_inttet(char *tet);
void	ft_exit(int i);
void	ver(char *f);
void	ver2(int n);
int		shift(int n);
void	bit_shift(size_t **k, int s);
int		shift1(int n);
void	fit(size_t **k, int n, int m);
int		ft_pow(int a, int b);
int		co(size_t n);
int		ft_sqrt(int nb);
void	or(size_t *a, size_t *b, size_t **k);
void	tor(size_t *b, int **s, int m);
int		tor1(size_t *b, int *s, int m);
void	put(size_t **a, size_t **b, int *n, int *i);
int		backtrack(size_t ***t, int *n, int m, int f);
void	ft_desplay(size_t **t, int dim, int len, int i);
size_t	*ft_copy(size_t *n);

#endif
