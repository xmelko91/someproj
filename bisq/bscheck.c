/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bscheck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:11:52 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/09 20:38:35 by alorent-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		flcreate(int *nbr, char *c, char *fl)
{
	if (BOOL == 0 && c[0] != '\n')
	{
		fl[FIRSTL++] = c[0];
		fl[FIRSTL] = '\0';
	}
	else if (BOOL == 0 && c[0] == '\n')
		BOOL = 1;
	else
		return (0);
	return (1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	nbrz(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	t[4] = 0;
	t[5] = 0;
	t[6] = 0;
	t[7] = 0;
	t[8] = 0;
	t[9] = 0;
}

char	*read_file(int name, int *nbr, char *fl, int len)
{
	int		c_size;
	int		ret;
	char	*c;
	char	*c2;

	c_size = 1;
	c = (char *)malloc(sizeof(char) * (c_size + 1));
	while ((ret = read(name, c + len, c_size)) > 0)
	{
		if (flcreate(nbr, c, fl) == 1)
			continue ;
		else
		{
			len += ret;
			if (c_size < 536870912)
				c_size *= 2;
			c[len] = '\0';
			c2 = c;
			c = (char *)malloc(sizeof(char) * (len + c_size + 1));
			ft_strcpy(c, c2);
			free(c2);
		}
	}
	return (c);
}

int		checkfn(char *str)
{
	char	*bsq;
	int		name;
	int		nbr[10];
	char	*fl;
	int		len;

	name = 0;
	len = 0;
	nbrz(nbr);
	if (str)
		name = open(str, O_RDONLY);
	if (name == -1)
		return (openerror());
	fl = (char *)malloc(sizeof(char) * 14);
	bsq = read_file(name, nbr, fl, len);
	if (close(name) == -1)
		return (0);
	if (strcreate(nbr, fl, bsq) == 1)
		return (1);
	return (0);
}
