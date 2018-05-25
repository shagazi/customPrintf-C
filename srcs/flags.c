/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:15:06 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/24 16:26:55 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flagspace(fmt_list *fmt, int strlength)
{
	int i;

	i = fmt->width;
	if (i < 0)
		i *= -1;
	if(ft_strchr(fmt->flags, '+') || (!(ft_strcmp(fmt->sign, "-"))))
		i--;
	while(i > strlength)
	{
		fmt->spaces = ft_strappend(fmt->spaces, " ");
		i--;
	}
}

void flagzero(fmt_list *fmt, int strlength)
{
	int i;

	i = fmt->width;
	if(ft_strchr(fmt->flags, '+') || (!(ft_strcmp(fmt->sign, "-"))))
		i--;
	while(i > strlength)
	{
		fmt->zeros = ft_strappend(fmt->zeros, "0");
		i--;
	}
}

void flaghex(fmt_list *fmt)
{
	if (fmt->format == 'o')
			fmt->hex = "0";
		if((fmt->format == 'x' && ft_strcmp(fmt->formatstr, "0")) ||
			fmt->format == 'p')
			fmt->hex = "0x";
		if(fmt->format == 'X' && ft_strcmp(fmt->formatstr, "0"))
			fmt->hex = "0X";
}

void flagplus(fmt_list *fmt)
{
	char f;

	f = fmt->format;
	if (ft_strchr("di", f) && ft_strchr(fmt->flags, '+') &&
	(!(ft_strchr(fmt->formatstr, '-'))))
		fmt->sign = "+";

}
