/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:15:06 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/26 18:17:41 by shagazi          ###   ########.fr       */
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
	if (fmt->format == 'o' )/*&& (!ft_strcmp(fmt->formatstr, "0")))*/
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

void flagundef(fmt_list *fmt)
{
	int i;
	char *newstr;
	char *flagstr;

	i = 0;
	newstr = ft_strnew(0);
	flagstr = fmt->flags;
	while (flagstr[i] != '\0')
	{
		if (flagstr[i] == ' ' && ft_strchr(flagstr, ' ')
			&& ft_strchr(flagstr, '+'))
			i++;
		if (flagstr[i] == '0' && ft_strchr(flagstr, '0')
			&& ft_strchr(flagstr, '-'))
			i++;
		if (flagstr[i] == ' ' &&
			(fmt->width > 0 || (!FLGMINUS(fmt)) || fmt->format == 'u'))
			i++;
		newstr = ft_strncat(newstr, &flagstr[i], 1);
		i++;
	}
	i = ft_strlen(newstr);
	newstr[i] = '\0';
	fmt->flags = ft_strdup(newstr);
	free(newstr);
}
