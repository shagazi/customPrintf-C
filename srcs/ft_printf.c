/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:29:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/25 16:22:53 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void getoutput(fmt_list *fmt, va_list *arg)
{
	formatcheck(arg, fmt);
	if (ft_strchr("oOxXp", fmt->format))
	{
		hexflags(fmt);
		formathex(fmt);
		ft_putstr(fmt->formatstr);
	}
	if (ft_strchr("sSC", fmt->format))
	{
		strflag(fmt);
		formatstr(fmt);
		ft_putstr(fmt->formatstr);
	}
	if (ft_strchr("c", fmt->format) || fmt->format == '%')
		charflag(fmt);
	if (ft_strchr("dDiuU", fmt->format))
	{
		intflag(fmt);
		formatint(fmt);
		ft_putstr(fmt->formatstr);
	}
}

// static void set_args(int *i, int *k, fmt_list *fmt)
// {
// 	*i = 0;
// 	*k = 0;
// 	fmt->byte_len = 0;
// }

// static void parseformat(fmt_list *fmt, int i, int *k, char *format, va_list *arg)
// {
// 	while(format[i])
// 	{
// 		if(format[i] == '%')
// 		{
// 			i += 1;
// 			i += parse_percent(format + i, fmt, arg);
// 			fmt->byte_len += bytelen(fmt);
// 		}
// 		else
// 		{
// 			write(1, format + i, 1);
// 			i++;
// 			k++;
// 		}
// 	}
// }

int ft_printf(char *format, ...)
{
	int i;
	int k;
	fmt_list *fmt;

	fmt = malloc(sizeof(fmt_list));
	i = 0;
	k = 0;
	fmt->byte_len = 0;
	// set_args(&i, &k, fmt);
	va_list arg;
	va_start(arg, format);
	// parseformat(fmt, i, &k, format, &arg);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			i += parse_percent(format + i, fmt, &arg);
			fmt->byte_len += bytelen(fmt);
		}
		else
		{
			write(1, format + i++, 1);
			k++;
		}
	}
	va_end(arg);
	k += fmt->byte_len;
	free(fmt);
	return (k);
}
// //
int main()
{
	int x =   printf("%2c\n", 0);
	printf("%d\n", x);
  	int y =   ft_printf("%2c\n", 0);                      
	printf("%d\n", y);
  	return(0);
}
