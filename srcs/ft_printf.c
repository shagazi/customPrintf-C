/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:29:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/01 23:16:05 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void fmtassign(fmt_list *fmt)
{
	fmt->modifier = 0;
	fmt->presicion = 0;
	fmt->width = 0;
	fmt->negwidth = 0;
	fmt->formatchar = 0;
	fmt->formatwstr = NULL;
	fmt->basenumber = "0123456789";
	fmt->formatstr = NULL;
	fmt->sign = "+";
	fmt->flags = NULL;
	fmt->hex = NULL;
	fmt->zeros = NULL;
	fmt->spaces = NULL;
}

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
	else if (ft_strchr("sS", fmt->format))
	{
		strflag(fmt);
		formatstr(fmt);
	}
	else if (ft_strchr("cC", fmt->format) || fmt->format == '%')
		charflag(fmt);
	else if (ft_strchr("dDiuU", fmt->format))
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
			if (fmt->formatstr)
				free(fmt->formatstr);
		}
		else
		{
			write(1, format + i, 1);
			i++;
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
// int main()
// {
// 	// ft_printf("%s", "pouet");
// 	// ft_printf(" pouet %s !!\n", "camembert");
// 	// ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
// 	// ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
// 	// ft_printf("%s!\n", NULL);
// 	ft_printf("%u", -0);
// 	ft_printf("%u", 0);
// 	ft_printf("%u", INT_MAX);
// 	ft_printf("%u", INT_MIN);
// 	ft_printf("%u", INT_MIN - 1);
// 	ft_printf("%u", INT_MAX + 1);
// 	ft_printf("%%u 0000042 == |%u|\n", 0000042);
// 	ft_printf("%%u \t == |%u|\n", '\t');
// 	ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
// }
