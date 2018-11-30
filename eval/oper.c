/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:16:10 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/07 09:48:05 by lconsidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		leng(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int		oper_value(char c)
{
	if (c == '+' || c == '-')
		return (2);
	if (c == '*' || c == '/' || c == '%')
		return (3);
	return (0);
}

void	retbuf(char *stack, char *buf, int b, int k)
{
	while (k >= 0)
	{
		stack[b] = buf[k - 1];
		b++;
		k--;
	}
	return ;
}
