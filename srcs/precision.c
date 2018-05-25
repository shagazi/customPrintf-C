/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:31:00 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/24 15:53:17 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void presicionstring(fmt_list *fmt, int i)
{
	int strlength;

	strlength = FMTLEN(fmt);
	if (i > 0)
	{
		while (strlength > i)
		{
			((char *)fmt->formatstr)[i] = '\0';
			i++;
		}
	}
}

void presicionzero(fmt_list *fmt)
{
	int i;

	i = fmt->presicion;
	while (i > FMTLEN(fmt))
	{
		fmt->zeros = ft_strappend(fmt->zeros, "0");
		i--;
	}
}

void negpresicionzero(fmt_list *fmt)
{
	int i;
	int j;

	i = fmt->presicion;
	j = fmt->width;
	while (j > FMTLEN(fmt))
	{
		fmt->zeros = ft_strappend(fmt->zeros, "0");
		j--;
	}
}

void intpresicion(fmt_list *fmt)
{
	char *tmp;
	int j;

	j = 0;
	tmp = malloc(sizeof(fmt->presicion));
	if (ft_strchr("dDi",fmt->format))
	{
		while (j < (fmt->presicion - (int)ft_strlen(fmt->formatstr)))
		{
			tmp[j] = '0';
			j++;
		}
		fmt->formatstr = ft_strjoin(tmp, fmt->formatstr);
		free(tmp);
	}
	if (ft_strchr("oOuUxX",fmt->format))
	{
		if (fmt->presicion > FMTLEN(fmt))
			presicionzero(fmt);
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
	}
}

void applypresicion(fmt_list *fmt)
{
	char *tmpstr;
	int i;

	i = fmt->presicion;
	if (fmt->presicion > 0)
	{
		tmpstr = fmt->formatstr;
		if (ft_strchr("dDioOuUxXp",fmt->format))
			intpresicion(fmt);
		if (fmt->format == 's')
			presicionstring(fmt, fmt->presicion);
	}
}
