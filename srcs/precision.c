/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:31:00 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/01 22:53:16 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void presicionstring(fmt_list *fmt, int i)
{
	int strlength;
	char *tmp;

	strlength = FMTLEN(fmt);
	if (i >= 0)
	{
		if (strlength > i)
		{
			tmp = ft_strnew(i);
			ft_strncpy(tmp, fmt->formatstr, i);
			free(fmt->formatstr);
			fmt->formatstr = ft_strdup(tmp);
			free(tmp);
		}
	}
}

void presicionzero(fmt_list *fmt)
{
	int i;
	int j;
	int strlength;
	char *zero;

	j = 0;
	i = fmt->presicion;
	if (fmt->format == 'o')
		strlength = FMTLEN(fmt) + HEXLEN(fmt);
	else
		strlength = FMTLEN(fmt);
	if (i > strlength)
	{
		zero = ft_strnew(i - strlength);
		while (i > strlength)
		{
			zero[j] = '0';
			j++;
			i--;
		}
		fmt->zeros = ft_strappend(fmt->zeros, zero);
	}
}

void negpresicionzero(fmt_list *fmt)
{
	int j;
	int k;
	char *zero;

	j = fmt->width;
	k = 0;
	if (j > FMTLEN(fmt))
	{
		zero = ft_strnew(j - FMTLEN(fmt));
		while (j > FMTLEN(fmt))
		{
			zero[k] = '0';
			k++;
			j--;
		}
		fmt->zeros = ft_strappend(fmt->zeros, zero);
	}
}

void intpresicion(fmt_list *fmt)
{
	char *zero;
	int j;

	j = 0;
	if (ft_strchr("dDi",fmt->format))
	{
		if (j < (fmt->presicion - (int)ft_strlen(fmt->formatstr)))
		{
			zero = ft_strnew(fmt->presicion - FMTLEN(fmt));
			while (j < (fmt->presicion - (int)ft_strlen(fmt->formatstr)))
			{
				zero[j] = '0';
				j++;
			}
			fmt->formatstr = ft_strappend(zero, fmt->formatstr);
		}
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
	if (fmt->presicion > 0)
	{
		if (ft_strchr("dDioOuUxXp",fmt->format))
			intpresicion(fmt);
		if (fmt->format == 's')
			presicionstring(fmt, fmt->presicion);
	}
}
