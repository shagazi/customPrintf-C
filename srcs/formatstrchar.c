/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatstrchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:46:23 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/25 16:09:42 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void printchar(fmt_list *fmt)
{
	char *ptr;

	ptr = ft_strnew(1);
	ptr = ft_strncpy(ptr, &fmt->formatchar, 1);
	if (FLGNEG(fmt))
	{
		if (fmt->spaces != NULL)
		{
			fmt->formatstr = ft_strcat(ptr, fmt->spaces);
			ft_putstr(fmt->formatstr);
			// fmt->byte_len += 1;
		}
		else
			ft_putchar(fmt->formatchar);
	}
	else
	{
		if (fmt->spaces != NULL)
		{
			fmt->formatstr = ft_strappend(fmt->spaces, ptr);
			ft_putstr(fmt->formatstr);
			// fmt->byte_len += 1;
		}
		else
			ft_putchar(fmt->formatchar);
	}
}

void formatstr(fmt_list *fmt)
{
	char	*tmp;

	tmp = fmt->formatstr;
	if (FLGNEG(fmt))
		fmt->formatstr = ft_strappend(tmp, fmt->spaces);
	else
		fmt->formatstr = ft_strappend(fmt->spaces, tmp);
}

void strflag(fmt_list *fmt)
{
	if (fmt->presicion < FMTLEN(fmt) )
		presicionstring(fmt, fmt->presicion);
	if (fmt->width > FMTLEN(fmt))
		flagspace(fmt, FMTLEN(fmt));
	if (fmt->formatstr == NULL && ft_strchr("sS", fmt->format))
	{
		ft_bzero(fmt->formatstr, FMTLEN(fmt));
		fmt->formatstr = ft_strdup("(null)");
	}
}

void charflag(fmt_list *fmt)
{
	if (fmt->width > 1)
		flagspace(fmt, 1);
	if (fmt->width < 0)
		flagspace(fmt, 1);
	printchar(fmt);
}
