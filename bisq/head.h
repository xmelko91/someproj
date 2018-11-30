/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:42:57 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/09 20:33:18 by alorent-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define NUMS (str[0][i] >= '0' && str[0][i] <= '9')
# define Y (nbr[0])
# define X (nbr[1])
# define X0 (nbr[2])
# define FIRSTL (nbr[3])
# define BOOL (nbr[4])
# define X1 (nbr[5])
# define Y1 (nbr[6])
# define SIZE (nbr[7])
# define CHECK (nbr[8])
# define I (nbr[9])
# define XY (Y1 * (X0 + 1) + X1)

void	ft_putstr(char *str);
int		openerror(void);
int		incorrectf1(char *bsq);
int		openerror1(char *bsq);
int		incorrectf(void);
int		checkfn(char *str);
int		display_f(char *bsq);
int		bsq_sqr(char *bsq, int *nbr, char *dat);
int		sqr_r(char *bsq, int *nbr, char *dat, int xy);
int		sqr_r2(char *bsq, int *nbr, char *dat, int xy);
int		sqr_b(char *bsq, int *nbr, char *dat, int xy);
int		sqr_b2(char *bsq, int *nbr, char *dat, int xy);
int		strcreate(int *nbr, char *fl, char *bsq);

#endif
