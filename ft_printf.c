/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:48:00 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/07 22:46:18 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int flags(char *str, ...)
// {
// 	va_list arg;
// 	int i;
//
// 	i = 0;
// 	va_start(arg, str);
// 	if (*str == '%')
// 	{
// 		if((str[i + 1]) == 'c')
// 		{
// 			int i = va_arg(arg, int);
// 			ft_putchar(i);
// 			str += 2;
// 		}
// 		if((str[i + 1]) == 'd')
// 		{
// 			int i = va_arg(arg, int);
// 			ft_itoa(i);
// 			ft_putnbr(i);
// 			str += 2;
// 		}
// 		if((str[i + 1]) == 'e')
// 		{
// 			int i = va_arg(arg, int);
// 			ft_putnbr(i);
// 			str += 2;
// 		}
// 		if((str[i + 1]) == 'f')
// 		{
// 			int i = va_arg(arg, int);
// 			ft_putnbr(i);
// 			str += 2;
// 		}
// 		if((str[i + 1]) == 'g')
// 		{
// 			int i = va_arg(arg, int);
// 			ft_putnbr(i);
// 			str += 2;
// 		}
// 		if((str[i + 1]) == 'i')
// 		{
// 			int i = va_arg(arg, int);
// 			ft_putnbr(i);
// 			str += 2;
// 		}
// 	}
// 	va_end(arg);
// 	return (0);
// }


int ft_printf(char *format, ...)
{
	int i;
	char *str;

	va_list arg;
	va_start(arg, format);
	str = format;
	i = 0;
	while(*str != '\0')
	{
		ft_putchar(*str);
		str++;
		if (*str == '%')
		{
			if((str[i + 1]) == 'd')
			{
				int i = va_arg(arg, int);
				ft_itoa(i);
				ft_putnbr(i);
				str += 2;
			}
		}
	}
	va_end(arg);
	return(0);
}

#include <stdio.h>

int main()
{
	ft_printf("hello %d\n", 4);
	// printf("lol\n");
	return(0);
}
