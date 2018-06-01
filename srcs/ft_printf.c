/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:29:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/31 22:52:05 by shagazi          ###   ########.fr       */
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
// // // // // // // // //
// // // // 	// int x = ft_printf("{%*c}", -15, 0);
// // // // 	// int y = printf("{%*c}", -15, 0);
// // 	int x = ft_printf("%hd %hd\n", (short int)0, (short int)42);
// // 	int y = printf("%hd %hd\n", (short int)0, (short int)42);
// // // 	ft_printf("%s", "pouet");
// // // 	ft_printf(" pouet %s !!\n", "camembert");
// // // 	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
// // // 	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
// // //
// // // 	printf(" pouet %s !!\n", "camembert");
// // // 	printf("%s !\n", "Ceci n'est pas un \0 exercice !");
// // // 	printf("%s!\n", "Ceci n'est toujours pas un exercice !");
// // //
// // // // // 	ft_printf("%#.o, %#.0o\n", 0, 0);
// // // // // 	printf("%#.o, %#.0o\n", 0, 0);
// // // // // 	ft_printf("%.o, %.0o\n", 0, 0);
// // // // // 	printf("%.o, %.0o\n", 0, 0);
// // // // // 	ft_printf("%.o, %.0O\n", 0, 0);
// // // // // 	printf("%.o, %.0O\n", 0, 0);
// // // // //
// // // // // 	int x = ft_printf("%#o\n", 0);
// // // // // 	int y = printf("%#o\n", 0);
// // // // // // // 	// // 	int x = ft_printf("{%05.s}\n", 0);
// // // // // // // // // 	int y = printf("{%07.s}\n", NULL);
// // // // // // // // 	// int x = ft_printf("%#.3o\n", 1);
// // // // // // // // 	// int y = printf("%#.3o\n", 1);
// // // // // // // // 	int x = ft_printf("{%05.S}\n", L"42 c est cool");
// // // // // // // // 	int y = printf("{%05.S}\n", L"42 c est cool");
// // // // printf("%d\n", x);
// // // 	// printf("%d\n", y);
// ft_printf("|#.x, #.0x| %#.x, %#.0x\n", 0, 0);
// printf("%#.x, %#.0x\n", 0, 0);
// ft_printf("%#o\n", 0);
// printf("%#o\n", 0);
// ft_printf("%#.o\n", 0);
// printf("%#.o\n", 0);
// ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
// ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
// printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
//  	return (0);
//  }
