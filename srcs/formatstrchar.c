/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatstrchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:46:23 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/28 18:30:29 by shagazi          ###   ########.fr       */
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
			free(fmt->formatstr);
		}
		else
			ft_putchar(fmt->formatchar);
	}
	else
	{
		if (fmt->spaces != NULL)
		{
			fmt->formatstr = ft_strappend(fmt->spaces, fmt->formatstr);
			ft_putstr(fmt->formatstr);
			free(fmt->formatstr);
			ft_putchar(fmt->formatchar);
		}
		else
			ft_putchar(fmt->formatchar);
	}
}

void printwidestr(fmt_list *fmt)
{
	wchar_t *p;

	p = fmt->formatwstr;
	while (*p)
	{
		ft_putchar((char)*p);
		p++;
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
	if (fmt->format == 'S')
		printwidestr(fmt);
	else
		ft_putstr(fmt->formatstr);
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
