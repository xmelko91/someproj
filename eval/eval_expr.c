/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:59:39 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/07 10:00:31 by lconsidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		eval_expr(char *c)
{
	int		i;
	int		b;
	int		k;
	char	*buf;
	char	*stack;

	k = 0;
	b = 0;
	i = 0;
	stack = (char*)malloc(sizeof(char) * leng(c) + 1);
	buf = (char*)malloc(sizeof(char) * leng(c) + 1);
	while (c[i] != '\0')
	{
		if (c[i] == ' ')
		{
			stack[b] = ',';
			b++;
		}
		else if (NBR)
		{
			stack[b] = c[i];
			b++;
		}
		else if (c[i] == '(')
		{
			buf[k] = c[i];
			k++;
		}
		else if (OPER)
		{
			if (c[i] == '-' && c[i + 1] >= '0' && c[i + 1] <= '9')
			{
				stack[b] = c[i];
				b++;
			}
			else if (k == 0 || (oper_value(c[i]) > oper_value(buf[k - 1])))
			{
				buf[k] = c[i];
				k++;
			}
			else
			{
				while (oper_value(c[i]) <= oper_value(buf[k - 1]))
				{
					stack[b] = buf[k - 1];
					b++;
					k--;
				}
				buf[k] = c[i];
				k++;
				if (k < 0)
					k = 0;
			}
		}
		if (c[i] == ')')
		{
			while (buf[k - 1] != '(' && k != 0)
			{
				stack[b] = buf[k - 1];
				b++;
				k--;
			}
			buf[k] = '\0';
			k--;
		}
		i++;
	}
	retbuf(stack, buf, b, k);
	return (exit_eval(stack, 0, -1));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		eval_expr(av[1]);
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
