/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:11:22 by mhrima            #+#    #+#             */
/*   Updated: 2022/11/06 08:17:32 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *conv, ...);
int convertfromDec_X(unsigned int num, char x);
int convertfromDec_P(unsigned long long num);
int printSpace(int *addSpace);
int lenU(unsigned num);
int lenP(unsigned long long p);
int lenX(unsigned int num);
int lend(long int num);
int ft_atoi(const char *s);
int ft_putunsignednbr(unsigned int num);
int ft_putnbr(long int num);
char	*ft_strchr(char *str, char to_find);
int ft_putstr(char *str, int n);
int ft_putchar(int c);
int ft_strlen(const char *str);

#endif