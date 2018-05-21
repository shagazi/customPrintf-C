/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:48:00 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/20 15:42:46 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int parse_modifier(char *str, fmt_list *fmt)
{
	int i = 0;
	if(str[0] == 'h' && str[1] == 'h')
		fmt->modifier = MOD_HH;
	else if(str[0] == 'l' && str[1] == 'l')
		fmt->modifier = MOD_LL;
	else if(str[0] == 'h')
		fmt->modifier = MOD_H;
	else if(str[0] == 'l')
		fmt->modifier = MOD_L;
	else if(str[0] == 'j')
		fmt->modifier = MOD_J;
	else if(str[0] == 'z')
		fmt->modifier = MOD_Z;
	if(fmt->modifier == 1 || fmt->modifier == 2)
		i = 2;
	if(fmt->modifier >= 3 && fmt->modifier <= 6)
		i = 1;
	return (i);
}

int parse_precision(char *str, fmt_list *fmt, va_list *arg)
{
	int i;

	i = 0;
	if(str[i] == '.')
	{
		i++;
		while(str[i] >= '0' && str[i] <= '9')
			i++;
		if(str[i] == '*')
		{
			i++;
			fmt->presicion = va_arg(*arg, int);
		}
		else
			fmt->presicion = ft_atoi(&str[1]);
	}
	return (i);
}

int parse_width(char *str, fmt_list *fmt, va_list *arg)
{
	int i;

	i = 0;
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	if(str[i] == '*')
	{
		i++;
		fmt->width = va_arg(*arg, int);
	}
	else
		fmt->width = ft_atoi(str);
	return (i);
}

int parse_flags(char *str, fmt_list *fmt)
{
	int i;
	char *tmp;

	i = 0;
	tmp = ft_strnew(0);
	while(str[i] == ' ' || str[i] == '-' || str[i] == '+' || str[i] == '0'
	|| str[i] == '#')
	i++;
	ft_strncpy(tmp, str, i);
	fmt->flags = ft_removedup(tmp);
	return (i);
}




int parse_percent(char *str, fmt_list *fmt, va_list *arg)
{
	int i;

	i = 0;
	fmt->modifier = 0;
	fmt->sign = '+';
	fmt->presicion = 0;
	fmt->basenumber = "0123456789";
	fmt->width = 0;
	fmt->formatstr = NULL;
	fmt->flags = NULL;
	fmt->zeros = NULL;
	fmt->spaces = NULL;
	fmt->hex = NULL;
	fmt->formatchar = '\0';
	i += parse_flags(str, fmt);
	i += parse_width(str + i, fmt, arg);
	i += parse_precision(str + i, fmt, arg);
	i += parse_modifier(str + i, fmt);
	fmt->format = str[i];
	i++;
	getoutput(fmt, arg);
	return (i);
}
