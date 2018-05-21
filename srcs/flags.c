/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:15:06 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/20 23:42:55 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flagspace(fmt_list *fmt, int strlength)
{
	int i;

	i = fmt->width;
	if(ft_strchr(fmt->flags, '+'))
		i--;
	// if (ft_strchr(fmt->flags, '-'))
	// {
	// //	printoutput(fmt);
	while(i > strlength)
	{
		fmt->spaces = ft_strappend(fmt->spaces, " ");
		i--;
	}
	// }
	// else
	// {
		// while(i > strlength)
		// {
		// 	fmt->spaces = ft_strjoin(fmt->spaces, " ");
		// 	i--;
		// }
	// //	printoutput(fmt);
	// }
	// fmt->byte_len += (fmt->width - strlength);
}

void flagzero(fmt_list *fmt, int strlength)
{
	int i;

	i = fmt->width;
	if(ft_strchr(fmt->flags, '+'))
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
		if(fmt->format == 'x' && ft_strcmp(fmt->formatstr, "0"))
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
		fmt->formatstr = ft_strappend(&fmt->sign, fmt->formatstr);

}

void callflags(fmt_list *fmt, int strlength)
{
	if (ft_strchr(fmt->flags, ' '))
		flagspace(fmt, strlength);
	if (ft_strchr(fmt->flags, '0') && (!(ft_strchr(fmt->flags, '-'))))
		flagzero(fmt, strlength);
	if (ft_strchr(fmt->flags, '+') && (!(ft_strchr(fmt->flags, '-')) &&
	(!(ft_strchr(fmt->flags, '#')))))
		flagplus(fmt);
}
