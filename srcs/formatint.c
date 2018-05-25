/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:20:38 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/24 16:23:56 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void formatint(fmt_list *fmt)
{
	char *str;

	str = NULL;
	if (FLGNEG(fmt))
	{
		if (FLGPLUS(fmt) || (!(ft_strcmp(fmt->sign, "-"))))
			str = ft_strdup(fmt->sign);
		if (ZEROLEN(fmt) && fmt->presicion != FMTLEN(fmt))
			str = ft_strappend(str, fmt->zeros);
		fmt->formatstr = ft_strappend(str, fmt->formatstr);
		if (SPACELEN(fmt))
			fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
	}
	else
	{
		if (SPACELEN(fmt) && fmt-> width >= 0)
			str = ft_strappend(str, fmt->spaces);
		if ((FLGPLUS(fmt) || (!(ft_strcmp(fmt->sign, "-")))) &&
		(!(ft_strchr("uU", fmt->format))))
			str = ft_strappend(str, fmt->sign);
		if (ZEROLEN(fmt) && fmt->presicion != FMTLEN(fmt))
			str = ft_strappend(str, fmt->zeros);
		fmt->formatstr = ft_strappend(str, fmt->formatstr);
		if (SPACELEN(fmt) && fmt-> width < 0)
			fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
	}
}

void intflag(fmt_list *fmt)
{
	if (fmt->presicion != FMTLEN(fmt) && fmt->presicion >= 0)
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
	if((!(ft_strcmp(fmt->formatstr, "0"))) &&
	(fmt->presicionflag == 1 && fmt->presicion == 0))
		ft_bzero(fmt->formatstr, FMTLEN(fmt));
 	if (FLGNEG(fmt))
		flagspace(fmt, (FMTLEN(fmt)));
	else if (!FLGZERO(fmt) && fmt->width > (FMTLEN(fmt) + SPACELEN(fmt)))
		flagspace(fmt, (FMTLEN(fmt) + SPACELEN(fmt)));
	if (FLGZERO(fmt) && (!FLGNEG(fmt) && fmt->presicion == 0))
		flagzero(fmt, (FMTLEN(fmt)));
	else if (fmt->width != (FMTLEN(fmt) + SPACELEN(fmt)) && fmt->width != 0)
		flagspace(fmt, (FMTLEN(fmt) + SPACELEN(fmt)));
	if (FLGSPACE(fmt) && (!FLGPLUS(fmt)) && fmt->width == 0 &&
	(!(ft_strchr("uU", fmt->format))))
		flagspace(fmt, -1);
}
