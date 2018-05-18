/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:15:06 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/17 23:27:43 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flagspace(fmt_list *fmt, int strlength)
{
	int i;

	i = fmt->width;
	if(ft_strchr(fmt->flags, '+'))
		i--;
	if(ft_strchr(fmt->flags, '#'))
		i -= 2;
	while(i > strlength)
	{
		ft_putchar(' ');
		i--;
	}
}

void flagzero(fmt_list *fmt, int strlength)
{
	int i;

	i = fmt->width;
	if(ft_strchr(fmt->flags, '+'))
		i--;
	if(ft_strchr(fmt->flags, '#'))
		i -= 2;
	while(i > strlength)
	{
		ft_putchar('0');
		i--;
	}
}

void flaghex(fmt_list *fmt)
{
	if(ft_strchr(fmt->flags, '#'))
	{
		if (fmt->format == 'o' && fmt->presicion == 0)
			ft_putnbr(0);
		if(fmt->format == 'x' && ft_strcmp(fmt->formatstr, "0"))
		{
			ft_putstr("0x");
			fmt->byte_len += 2;
		}
		if(fmt->format == 'X' && ft_strcmp(fmt->formatstr, "0"))
		{
			ft_putstr("0X");
			fmt->byte_len += 2;
		}
	}
}

void flagplus(fmt_list *fmt)
{
	char f;

	f = fmt->format;
	if (ft_strchr("di", f) && ft_strchr(fmt->flags, '+'))
		ft_putchar(fmt->sign);
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
	if (ft_strchr(fmt->flags, '#') && (!(ft_strchr(fmt->flags, '-'))))
		flaghex(fmt);
}
