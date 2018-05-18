/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:28:14 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/17 17:57:10 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void log_fmt(fmt_list *fmt) {
	printf("\nFlags |%s|\n", fmt->flags);
	printf("width: %d\n", fmt->width);
	printf("Presicion: %d\n", fmt->presicion);
	printf("Mod: %d\n", fmt->modifier);
	printf("Format: %c\n", fmt->format);
	printf("Flags_len: %d\n", fmt->byte_len);
	// printf("Formatstr: %s\n", fmt->formatstr);
}

//
//
// int main()
// {
// 	int x = ft_printf("%s %d","This will test the byte size of this string", 10);
// 	int y = printf("%s %d","This will test the byte size of this string", 10);
// 	printf("%d vs %d\n", x, y);
// 	//ft_printf("hello %#-- 010.10lld\n", 4);
// 	// ft_printf("Line1\n%+ 0*llx\n", 10, 100);
// 	// ft_printf("Line2\n%s\n", "String");
// 	// printf("%#\n", 100);
// 	// ft_printf("%-010s\n", "string");
// 	// ft_printf("|%10c|\n", 's');
// 	// printf("|%10c|\n", 's');
// 	// ft_printf("|%10o|\n", 100);
// 	// printf("|%10o|\n", 100);
// 	// printf("||%10.3s||\n", "string");
// 	// ft_printf("%C\n", );
// 	return(0);
// }



// int ft_printf(char *format, ...)
// {
// 	int i;
// 	int startpercent;
// 	int endpercent;
// 	fmt_list *fmt;
//
// 	fmt = malloc(sizeof(fmt_list));
// 	i = 0;
// 	startpercent = 0;
// 	endpercent = 0;
// 	fmt->byte_len = 0;
// 	va_list arg;
// 	va_start(arg, format);
// 	while(format[i])
// 	{
// 		if(format[i] == '%')
// 		{
// 			startpercent = i;
// 			startpercent += 1;
// 			startpercent += parse_percent(format + startpercent, fmt, &arg);
// 			endpercent = startpercent - i;
// 			i = startpercent;
// 			fmt->byte_len += bytelen(fmt);
// 			printf("|bl: %i|\n", fmt->byte_len);
// 		}
// 		else
// 		{
// 			write(1, format + i, 1);
// 			i++;
// 		}
// 	}
// 	// printf("\n|bytes: ***%d***|\n", fmt->byte_len);
// 	va_end(arg);
// 	return(fmt->byte_len);
// }
