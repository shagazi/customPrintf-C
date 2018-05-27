/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 23:45:47 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/26 17:11:12 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *signedcast(va_list *arg, fmt_list *fmt)
{
	int m;
	long long int n;

	m = fmt->modifier;
	if (m == MOD_HH)
		n = (signed char)va_arg(*arg, int);
	else if (m == MOD_LL)
		n = (long long int)va_arg(*arg, long long int);
	else if (m == MOD_H)
		n = (short int)va_arg(*arg, int);
	else if (m == MOD_L)
		n = (long int)va_arg(*arg, long int);
	else if (m == MOD_J)
		n = va_arg(*arg, intmax_t);
	else if (m == MOD_Z)
		n = va_arg(*arg, size_t);
	else
		n = (int)va_arg(*arg, int);
	if (n < 0)
		fmt->sign = "-";
	return(convert_int_toalpha((void *)&n, fmt));
}

char *unsignedcast(va_list *arg, fmt_list *fmt)
{
	unsigned long long int n;

	if (fmt->format == 'o' || fmt->format == 'O')
		fmt->basenumber = OCT;
	else if (fmt->format == 'x')
		fmt->basenumber = HEX;
	else if (fmt->format == 'X')
		fmt->basenumber = HEXX;
	if (fmt->modifier == MOD_L || fmt->format == 'U' || fmt->format == 'O')
		n = (unsigned long int)va_arg(*arg, unsigned long int);
	else if (fmt->modifier == MOD_LL)
		n = (unsigned long long int)va_arg(*arg, unsigned long long int);
	else if (fmt->modifier == MOD_HH)
		n = (unsigned char)va_arg(*arg, int);
	else if (fmt->modifier == MOD_H)
		n = (unsigned short)va_arg(*arg, unsigned int);
	else if (fmt->modifier == MOD_J)
		n = va_arg(*arg, uintmax_t);
	else if (fmt->modifier == MOD_Z)
		n = va_arg(*arg, ssize_t);
	else
		n = (unsigned int)va_arg(*arg, unsigned int);
	return(convert_int_toalpha((void *)&n, fmt));
}

void  wchar_check(va_list *arg, fmt_list *fmt)
{
	wchar_t p;

	if (fmt->format == 'C')
	{
		p = (wchar_t)va_arg(*arg, wchar_t);
		fmt->formatstr = (void *)&p;
	}
	if (fmt->format == 'S')
	{
		p = (wchar_t)va_arg(*arg, wchar_t*);
		fmt->formatstr = (void *)&p;
	}
}

void char_check(fmt_list *fmt, va_list *arg)
{
	if (fmt->format == 'c')
		fmt->formatchar = (char)va_arg(*arg, int);
	if (fmt->format == 's')
		fmt->formatstr = ft_strdup(va_arg(*arg, char *));
}

void formatcheck(va_list *arg, fmt_list *fmt)
{
	char f;
	char *tmp;

	f = fmt->format;
	if (ft_strchr("dDi", f))
	{
		fmt->formatstr = (char *)signedcast(arg, fmt);
		if (ft_strchr(fmt->formatstr, '-'))
		{
			tmp = ft_strdup(ft_strchr(fmt->formatstr, '-') + 1);
			free(fmt->formatstr);
			fmt->formatstr = tmp;
			fmt->sign = "-";
		}
	}
	if (ft_strchr("oOuUxX", f))
		fmt->formatstr = (char *)unsignedcast(arg, fmt);
	if (ft_strchr("cs", f))
		char_check(fmt, arg);
	if (ft_strchr("C", f))
		wchar_check(arg, fmt);
	if (fmt->format == 'p') {
		void *ptr = va_arg(*arg, void *);
		fmt->formatstr = convert_int_toalpha(ptr, fmt);
	}
	if (f == '%')
		fmt->formatchar = '%';
}
