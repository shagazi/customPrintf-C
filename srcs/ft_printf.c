/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:29:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/17 23:27:45 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void printoutput(fmt_list *fmt)
{
	char f;

	f = fmt->format;
	if (ft_strchr("sSoOuUxXdi", f))
		ft_putstr(fmt->formatstr);
	if (fmt->format == 'C')
		write(1, (wchar_t *)fmt->formatstr, 4);
	if (fmt->format == 'c')
		ft_putchar(fmt->formatchar);
	if (fmt->format == '%')
		ft_putchar(fmt->formatchar);
}

void getoutputhelp(fmt_list *fmt)
{
	if(!(ft_strchr("cC%",fmt->format)))
	{
		if (ft_strchr(fmt->flags, '#') && (ft_strchr(fmt->flags, '0')))
		{
			flaghex(fmt);
			flagzero(fmt, ft_strlen(fmt->formatstr));
		}
		printoutput(fmt);
		if(fmt->width != 0 && (!(ft_strchr(fmt->flags, '0'))))
			flagspace(fmt, ft_strlen(fmt->formatstr));
		callflags(fmt, ft_strlen(fmt->formatstr));
	}
	else
	{
		printoutput(fmt);
		if(fmt->width != 0 && (!(ft_strchr(fmt->flags, '0'))))
			flagspace(fmt, 1);
		callflags(fmt, 1);
	}
}

void getoutput(fmt_list *fmt, va_list *arg)
{
	formatcheck(arg, fmt);
	applypresicion(fmt);
	if (ft_strchr(fmt->flags, '-'))
	{
		if (ft_strchr(fmt->flags, '+')) /*&& (!(ft_strchr(fmt->flags, '#'))))*/
			flagplus(fmt);
		getoutputhelp(fmt);
	}
	else
	{
		if(fmt->format != 'c' && fmt->format != '%')
		{
			if(fmt->width != 0 && (!(ft_strchr(fmt->flags, '0'))))
				flagspace(fmt, ft_strlen(fmt->formatstr));
			callflags(fmt, ft_strlen(fmt->formatstr));
			printoutput(fmt);
		}
		else
		{
			if(fmt->width != 0 && (!(ft_strchr(fmt->flags, '0'))))
				flagspace(fmt, 1);
			callflags(fmt, 1);
			printoutput(fmt);
		}
	}
}

int ft_printf(char *format, ...)
{
	int i;
	int k;
	fmt_list *fmt;

	fmt = malloc(sizeof(fmt_list));
	k = 0;
	i = 0;
	fmt->byte_len = 0;
	va_list arg;
	va_start(arg, format);
	while(format[i])
	{
		if(format[i] == '%')
		{

			i += 1;
			i += parse_percent(format + i, fmt, &arg);
			fmt->byte_len += bytelen(fmt);
		}
		else
		{
			write(1, format + i, 1);
			i++;
			k++;
		}
	}
	fmt->byte_len += k;
	va_end(arg);
	return(fmt->byte_len);
}
//
// int main()
// {
// 	 ft_printf("%#x", 42);
// 	return(0);
// }
