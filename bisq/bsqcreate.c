/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:09:22 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/08 18:24:17 by lconsidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

int		ft_strlen2(char *str, int *nbr)
{
	while (*str != '\0')
	{
		if (*str == '\n')
		{
			if ((X0 == 0 && X > 0) || (X0 == X))
			{
				X0 = X;
				X = 0;
			}
			else
				return (incorrectf());
			Y += 1;
		}
		else
			X++;
		str++;
	}
	if (*(str - 1) != '\n')
		return (incorrectf());
	return (1);
}

int		boolmf(char c, int *nbr)
{
	if (c >= '0' && c <= '9')
	{
		if (X > 214748364)
			return (incorrectf());
		if (X == 214748364 && (c - '0') > 7)
			return (incorrectf());
		X = X * 10 + (c - '0');
	}
	else
		return (incorrectf());
	BOOL += 1;
	return (1);
}

int		bsread(char c, int *nbr, char *dat)
{
	if (BOOL < FIRSTL - 3)
	{
		if (boolmf(c, nbr) != 1)
			return (0);
	}
	else if (BOOL <= FIRSTL)
	{
		dat[Y1++] = c;
		if (c == '\n')
			dat[Y1] = '\0';
		dat[Y1] = '\0';
		BOOL += 1;
	}
	if (X != Y && BOOL >= FIRSTL)
		return (incorrectf());
	return (1);
}

int		strcreate(int *nbr, char *fl, char *bsq)
{
	char	c;
	char	dat[4];
	int		r;
	int		i;

	BOOL = 0;
	i = 0;
	if (ft_strlen2(bsq, nbr) == 0)
		return (0);
	while (fl[i])
	{
		c = fl[i];
		r = bsread(c, nbr, dat);
		if (r == 0)
			return (0);
		i++;
	}
	free(fl);
	if (X0 == 0)
		return (incorrectf());
	bsq_sqr(bsq, nbr, dat);
	return (0);
}
