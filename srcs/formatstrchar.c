/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatstrchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:46:23 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/01 17:44:16 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void printchar(fmt_list *fmt)
{
	if (FLGNEG(fmt))
	{
		if (fmt->spaces != NULL)
		{
			fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
			ft_putchar(fmt->formatchar);
			ft_putstr(fmt->formatstr);
		}
		else
			ft_putchar(fmt->formatchar);
	}
	else
	{
		if (fmt->spaces != NULL || fmt->zeros != NULL)
		{
			fmt->formatstr = ft_strappend(fmt->spaces, fmt->formatstr);
			fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
			ft_putstr(fmt->formatstr);
			ft_putchar(fmt->formatchar);
		}
		else
			ft_putchar(fmt->formatchar);
	}
}

void printwidestr(fmt_list *fmt)
{
	wchar_t *p;
	int i;

	p = fmt->formatwstr;
	i = 0;
	if (fmt->formatwstr == NULL)
	{
		ft_putstr("(null)");
		fmt->byte_len += 6;
	}
	else
	{
		while (*p)
		{
			ft_putchar((char)*p);
			p++;
			i++;
		}
		fmt->byte_len += (i - 1);
	}
}

void formatstr(fmt_list *fmt)
{
	if (FLGNEG(fmt))
		fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
	else
	{
		fmt->formatstr = ft_strappend(fmt->spaces, fmt->formatstr);
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
	}
	if (fmt->format == 'S')
		printwidestr(fmt);
	else
		ft_putstr(fmt->formatstr);
}

void strflag(fmt_list *fmt)
{
	if (fmt->presicion < FMTLEN(fmt) && fmt->presicionflag == 1)
		presicionstring(fmt, fmt->presicion);
	if (fmt->width > 0)
	{
		if (ft_strchr(fmt->flags, '0'))
			flagzero(fmt, FMTLEN(fmt));
		else
			flagspace(fmt, FMTLEN(fmt));
	}
	if (fmt->formatstr == NULL && ft_strchr("s", fmt->format) && fmt->width == 0)
	{
		ft_bzero(fmt->formatstr, FMTLEN(fmt));
		fmt->formatstr = ft_strdup("(null)");
	}
}

void charflag(fmt_list *fmt)
{
	if (fmt->width > 1)
	{
		if (ft_strchr(fmt->flags, '0'))
			flagzero(fmt, 1);
		else
			flagspace(fmt, 1);
	}
	if (fmt->width < 0)
		flagspace(fmt, 1);
	printchar(fmt);
}
