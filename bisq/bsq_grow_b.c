/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_grow_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorent- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:14:54 by alorent-          #+#    #+#             */
/*   Updated: 2018/10/09 20:38:44 by alorent-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		sqr_b_f(char *bsq, int *nbr, char *dat, int xy)
{
	CHECK = xy - SIZE + I * (X0 + 1);
	if (CHECK >= 0 && CHECK <= (Y * (X0 + 1)) && bsq[CHECK] == dat[0])
	{
		BOOL += 1;
		I++;
	}
	else
	{
		BOOL = SIZE;
		sqr_r2(bsq, nbr, dat, xy - (BOOL - 1));
		return (1);
	}
	return (0);
}

int		sqr_b_f2(char *bsq, int *nbr, char *dat, int xy)
{
	CHECK = xy + SIZE * (X0 + 1) - I;
	if (CHECK >= 0 && CHECK <= (Y * (X0 + 1)) && bsq[CHECK] == dat[0])
	{
		BOOL += 1;
		I++;
	}
	else
	{
		BOOL = SIZE;
		sqr_r2(bsq, nbr, dat, xy - (BOOL - 1));
		return (1);
	}
	return (0);
}

int		sqr_b(char *bsq, int *nbr, char *dat, int xy)
{
	SIZE = BOOL;
	I = 0;
	BOOL = 0;
	while (BOOL <= SIZE)
	{
		if (sqr_b_f(bsq, nbr, dat, xy) == 1)
			return (0);
	}
	BOOL = 0;
	I = 0;
	while (BOOL < SIZE)
	{
		if (sqr_b_f2(bsq, nbr, dat, xy) == 1)
			return (0);
	}
	if (BOOL == SIZE)
	{
		BOOL += 1;
		sqr_b(bsq, nbr, dat, xy);
	}
	return (0);
}
