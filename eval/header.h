/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconsidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:19:10 by lconsidi          #+#    #+#             */
/*   Updated: 2018/10/06 17:19:13 by lconsidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define NBR    (c[i] >= '0' && c[i] <= '9')
# define OPER (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/' || c[i] == '%')
# define NBR1 (c[i - 1] >= '0' && c[i - 1] <= '9')
# define OPER1 (c[i - 1] == '+' || c[i - 1] == '-' || c[i - 1] == '*' || c[i - 1] == '/' || c[i - 1] == '%')

#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);
void ft_putnbr(int nb);
int oper_value(char c);
int    leng(char *c);
void retbuf(char *stack, char *buf, int b, int k);
int mod(int a, int b);
int umn(int a, int b);
int divide(int a, int b);
int minus(int a, int b);
int plus(int a, int b);
int exit_eval(char *c, int i, int n);

#endif
