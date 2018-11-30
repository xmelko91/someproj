/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:21:59 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/09 20:38:21 by alorent-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		display_f(char *bsq)
{
	int		i;

	i = 0;
	while (bsq[i] != '\0' && bsq[i + 1] != '\0')
	{
		write(1, &bsq[i], 1);
		i++;
	}
	free(bsq);
	return (0);
}

int		openerror(void)
{
	write(2, "open error", 10);
	return (0);
}

int		openerror1(char *bsq)
{
	write(2, "open error", 10);
	free(bsq);
	return (0);
}

int		incorrectf(void)
{
	write(2, "map error", 9);
	return (0);
}

int		incorrectf1(char *bsq)
{
	write(2, "map error", 9);
	free(bsq);
	return (0);
}
