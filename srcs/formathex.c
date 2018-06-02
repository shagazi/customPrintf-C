/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formathex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 12:29:08 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/01 22:22:43 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	nohashflag(t_struct *fmt)
{
	if (FLGNEG(fmt) && (fmt->presicion < fmt->width))
		fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
	if (FLGZERO(fmt) && (!FLGNEG(fmt)))
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
	if (!FLGZERO(fmt) && (!FLGNEG(fmt)))
		fmt->formatstr = ft_strappend(fmt->spaces, fmt->formatstr);
}

void	formathex(t_struct *fmt)
{
	char	*tmp;

	tmp = NULL;
	if (FLGHASH(fmt) || fmt->format == 'p')
	{
		if (FLGNEG(fmt))
		{
			tmp = ft_strappend(fmt->hex, fmt->formatstr);
			fmt->formatstr = ft_strappend(tmp, fmt->spaces);
		}
		else if (FLGZERO(fmt))
		{
			tmp = ft_strappend(fmt->hex, fmt->zeros);
			fmt->formatstr = ft_strappend(tmp, fmt->formatstr);
		}
		if (!FLGZERO(fmt) && (!FLGNEG(fmt)))
		{
			tmp = ft_strappend(fmt->spaces, fmt->hex);
			fmt->formatstr = ft_strappend(tmp, fmt->formatstr);
		}
	}
	if (!FLGHASH(fmt) && fmt->format != 'p')
		nohashflag(fmt);
}

void	hexflags(t_struct *fmt)
{
	if (FLGHASH(fmt) || fmt->format == 'p')
		flaghex(fmt);
	if (!ft_strcmp(fmt->formatstr, "0"))
	{
		if (FLGHASH(fmt))
		{
			free(fmt->formatstr);
			fmt->formatstr = ft_strnew(1);
		}
	}
	if (fmt->presicion != FMTLEN(fmt))
	{
		presicionzero(fmt);
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
	}
	if (FLGNEG(fmt))
		flagspace(fmt, (FMTLEN(fmt) + HEXLEN(fmt)));
	if (FLGZERO(fmt))
		flagzero(fmt, (FMTLEN(fmt) + HEXLEN(fmt)));
	if (!FLGZERO(fmt) && (!FLGNEG(fmt)) && fmt->width > 0)
		flagspace(fmt, (FMTLEN(fmt) + HEXLEN(fmt)));
	if (FLGSPACE(fmt) && fmt->width == 0)
		fmt->spaces = ft_strdup(" ");
}
