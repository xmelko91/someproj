/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_sqr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorent- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 09:26:14 by alorent-          #+#    #+#             */
/*   Updated: 2018/10/09 20:39:21 by alorent-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		bsq_final(char *bsq, int *nbr, char *dat)
{
	Y1 = 0;
	while (Y1 < X)
	{
		X1 = 0;
		while (X1 < X)
		{
			bsq[FIRSTL + X1 + (Y1 * (X0 + 1))] = dat[2];
			X1++;
		}
		Y1++;
	}
	display_f(bsq);
	return (0);
}

void	bsq_sqr_if(char *bsq, int *nbr, char *dat)
{
	if (bsq[XY + 1] == dat[0])
		sqr_r(bsq, nbr, dat, XY + 1);
	if ((XY + X0 + 1) < (Y * (X0 + 1)) && bsq[XY + X0 + 1] == dat[0])
		sqr_b(bsq, nbr, dat, XY + X0 + 1);
}

int		bsq_sqr(char *bsq, int *nbr, char *dat)
{
	X1 = 0;
	Y1 = 0;
	FIRSTL = 0;
	X = 0;
	while (bsq[XY] != '\0')
	{
		if (bsq[XY] != dat[0] && bsq[XY] != dat[1] && bsq[XY] != '\n')
			return (incorrectf());
		BOOL = 1;
		if (XY == 0 && bsq[XY] == dat[0])
		{
			sqr_r(bsq, nbr, dat, XY);
		}
		else if (bsq[XY] == dat[1])
			bsq_sqr_if(bsq, nbr, dat);
		if (X1 == X0)
		{
			X1 = 0;
			Y1 += 1;
		}
		else
			X1 += 1;
	}
	return (bsq_final(bsq, nbr, dat));
}
