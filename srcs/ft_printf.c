/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:29:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/29 19:00:43 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void formatadjust(fmt_list *fmt)
{
	if (fmt->modifier == MOD_L)
	{
		if (fmt->format == 's')
			fmt->format = 'S';
		if (fmt->format == 'd')
			fmt->format = 'D';
		if (fmt->format == 'c')
			fmt->format = 'C';
	}
}
void getoutput(fmt_list *fmt, va_list *arg)
{
	formatadjust(fmt);
	formatcheck(arg, fmt);
	flagundef(fmt);
	if (ft_strchr("oOxXp", fmt->format))
	{
		hexflags(fmt);
		formathex(fmt);
		ft_putstr(fmt->formatstr);
	}
	if (ft_strchr("sS", fmt->format))
	{
		strflag(fmt);
		formatstr(fmt);
	}
	if (ft_strchr("cC", fmt->format) || fmt->format == '%')
		charflag(fmt);
	if (ft_strchr("dDiuU", fmt->format))
	{
		intflag(fmt);
		formatint(fmt);
		ft_putstr(fmt->formatstr);
	}
}

int sizeofstring(char *format, int i, fmt_list *fmt, va_list *arg)
{
	int k;

	k = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			i += parse_percent(format + i, fmt, arg);
			fmt->byte_len += bytelen(fmt);
		}
		else
		{
			write(1, format + i++, 1);
			k++;
		}
	}
	return (k);
}

int ft_printf(char *format, ...)
{
	int i;
	int k;
	fmt_list *fmt;

	fmt = malloc(sizeof(fmt_list));
	i = 0;
	k = 0;
	fmt->byte_len = 0;
	va_list arg;
	va_start(arg, format);
	k = sizeofstring(format, i, fmt, &arg);
	va_end(arg);
	k += fmt->byte_len;
	free(fmt);
	return (k);
}

int main()
{
 	ft_printf("%d%d%d\n", 42, 43, 44);
	// while (1)
	// 	;
	return(0);
}
