/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:13:18 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/07 10:45:40 by lconsidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int		get_op(char c, int a, int b)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	if (c == '%')
		return (a % c);
	return (0);
}

int		ft_toint(char *c, int k)
{
	int		nb;
	int		l;

	l = 0;
	nb = 0;
	while (c[k - 1] >= '0' && c[k - 1] <= '9')
		k--;
	while (c[k] >= '0' && c[k] <= '9')
	{
		l = c[k] - '0';
		nb = nb * 10 + l;
		k++;
	}
	return (nb);
}

int		exit_eval(char *c, int i, int n)
{
	int *nb;
	int min;

	nb = (int*)malloc(sizeof(int) * leng(c));
	while (c[i] != '\0')
	{
		while (c[i] == ',')
			i++;
		if ((NBR) && (c[i + 1] < '0' || c[i + 1] > '9'))
		{
			n++;
			nb[n] = ft_toint(c, i);
			(min == 1) ? (nb[n] = (nb[n] * -1)) && (min = 0) : (0);
		}
		if (OPER)
		{
			if (c[i] == '-' && c[i + 1] >= '0' && c[i + 1] <= '9')
				min = 1;
			else
			{
				nb[n - 1] = get_op(c[i], nb[n - 1], nb[n]);
				n--;
			}
		}
		i++;
	}
	return (nb[0]);
}
