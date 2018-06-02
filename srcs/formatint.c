/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:20:38 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/01 23:59:20 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	formatnegint(t_struct *fmt, char *str)
{
	if (FLGSPACE(fmt))
		str[0] = ' ';
	if (FLGPLUS(fmt) || (!(ft_strcmp(fmt->sign, "-"))))
		str = ft_strappend(str, fmt->sign);
	if (ZEROLEN(fmt) && fmt->presicion != FMTLEN(fmt))
		str = ft_strappend(str, fmt->zeros);
	fmt->formatstr = ft_strappend(str, fmt->formatstr);
	if (SPACELEN(fmt))
		fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
}

void	formatint(t_struct *fmt)
{
	char *str;

	str = ft_strnew(1);
	if (FLGNEG(fmt))
		formatnegint(fmt, str);
	else
	{
		if (FLGSPACE(fmt) && ft_strcmp(fmt->sign, "-") && fmt->width == 0
			&& (!(ft_strchr("uU", fmt->format))))
			str[0] = ' ';
		if (SPACELEN(fmt) && fmt->width >= 0)
			str = ft_strappend(str, fmt->spaces);
		if ((FLGPLUS(fmt) || (!(ft_strcmp(fmt->sign, "-")))) &&
			(!(ft_strchr("uU", fmt->format))))
			str = ft_strappend(str, fmt->sign);
		if (ZEROLEN(fmt) && fmt->presicion != FMTLEN(fmt))
			str = ft_strappend(str, fmt->zeros);
		fmt->formatstr = ft_strappend(str, fmt->formatstr);
		if (SPACELEN(fmt) && fmt->negwidth < 0)
			fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
	}
}

void	intflaghelp(t_struct *fmt)
{
	if (FLGNEG(fmt))
		flagspace(fmt, (FMTLEN(fmt)));
	else if (fmt->width != (FMTLEN(fmt) + ZEROLEN(fmt)) && fmt->presicion == 0)
		flagspace(fmt, FMTLEN(fmt) + ZEROLEN(fmt));
	else if (fmt->width > FMTLEN(fmt) && fmt->presicion != 0)
		flagspace(fmt, FMTLEN(fmt));
	if (FLGSPACE(fmt) && (ft_strcmp(fmt->sign, "-")) &&
		fmt->width < fmt->presicion && (!(ft_strchr("uU", fmt->format))))
		flagspace(fmt, fmt->width - 1);
}

void	intflag(t_struct *fmt)
{
	if (fmt->presicion != FMTLEN(fmt) && fmt->presicion > 0)
	{
		presicionzero(fmt);
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
	}
	else if (fmt->presicion < 0)
	{
		negpresicionzero(fmt);
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
		fmt->zeros = NULL;
	}
	if ((!(ft_strcmp(fmt->formatstr, "0"))) &&
	(fmt->presicionflag == 1 && fmt->presicion == 0))
	{
		free(fmt->formatstr);
		fmt->formatstr = ft_strnew(1);
	}
	if (FLGZERO(fmt) && fmt->presicion != FMTLEN(fmt))
		flagzero(fmt, (FMTLEN(fmt)));
	intflaghelp(fmt);
}

void	castint(t_struct *fmt, va_list *arg)
{
	char *tmp;

	fmt->formatstr = (char *)signedcast(arg, fmt);
	if (ft_strchr(fmt->formatstr, '-'))
	{
		tmp = ft_strdup(ft_strchr(fmt->formatstr, '-') + 1);
		free(fmt->formatstr);
		fmt->formatstr = ft_strdup(tmp);
		free(tmp);
		fmt->sign = ft_strdup("-");
	}
	else if (ft_strchr(fmt->flags, '+'))
	{
		fmt->sign = ft_strdup("+");
	}
}
