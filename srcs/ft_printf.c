/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:29:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/17 18:37:32 by shagazi          ###   ########.fr       */
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
	if(fmt->format == 'c')
		ft_putchar(fmt->formatchar);
}

void getoutputhelp(fmt_list *fmt)
{
	if(fmt->format != 'c')
	{
		printoutput(fmt);
		if(fmt->width != 0)
			flagspace(fmt, ft_strlen(fmt->formatstr));
		callflags(fmt, ft_strlen(fmt->formatstr));
	}
	else
	{
		printoutput(fmt);
		if(fmt->width != 0)
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
		if (ft_strchr(fmt->flags, '+') && (!(ft_strchr(fmt->flags, '#'))))
			flagplus(fmt);
		getoutputhelp(fmt);
	}
	else
	{
		if(fmt->format != 'c')
		{
			if(fmt->width != 0)
				flagspace(fmt, ft_strlen(fmt->formatstr));
			callflags(fmt, ft_strlen(fmt->formatstr));
			printoutput(fmt);
		}
		else
		{
			if(fmt->width != 0)
				flagspace(fmt, 1);
			callflags(fmt, 1);
			printoutput(fmt);
		}
	}
}




int ft_printf(char *format, ...)
{
	int i;
	fmt_list *fmt;

	fmt = malloc(sizeof(fmt_list));
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
		}
	}
	va_end(arg);
	if (!(ft_strchr("sSoOuUxXdiCc", fmt->format)))
		return(i);
	else
		return(fmt->byte_len);
}

// int main()
// {
// 	// int x = ft_printf("%s\n %d\n","This will test the byte size of this string", 10);
// 	// printf("|x: ***%d***|\n", x);
// 	// int a = ft_printf("\n");
// 	// printf("|a: ***%d***|\n", a);
//     //
// 	// int b = ft_printf("test");
// 	// printf("\n|b: ***%d***|\n", b);
//     //
// 	// int c = ft_printf("test\n");
// 	// printf("\n|c: ***%d***|\n", c);
//     //
// 	// int d = ft_printf("1234");
// 	// printf("\n|d: ***%d***|\n", d);
//
// 	int f = ft_printf("%%");
// 	printf("\n|f: ***%d***|\n", f);
//
// 	int i = ft_printf("%5%");
// 	printf("\n|i: ***%d***|\n", i);
// 	ft_printf("%-5%");
// 	ft_printf("%.0%");
// 	ft_printf("%%", "test");
// 	ft_printf("%   %", "test");
//
// 	// int y = printf("%s %d\n","This will test the byte size of this string", 10);
// 	// printf("%d vs %d\n", x, y);
// 	//ft_printf("hello %#-- 010.10lld\n", 4);
// 	// ft_printf("Line1\n%+ 0*llx\n", 10, 100);
// 	// ft_printf("Line2\n%s\n", "String");
// 	// printf("%#\n", 100);
// 	// ft_printf("%-010s\n", "string");
// 	// ft_printf("|%10c|\n", 's');
// 	// printf("|%10c|\n", 's');
// 	// ft_printf("|%10o|\n", 100);
// 	// printf("|%10o|\n", 100);
// 	// printf("||%10.3s||\n", "string");
// 	// ft_printf("%C\n", );
// 	return(0);
// }
