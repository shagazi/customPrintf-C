/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:49:34 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/17 00:55:52 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	char *str = argv[1];
	char strj[256];

	i = 0;
	j = 0;
	strj[j] = 0;
	if (argc == 2  && str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			while(str[i] == ' ' || str[i] == '\t')
				i++;
			while(str[i] >= 33 && str[i] <= 127)
			{
				strj[j] = str[i];
				i++;
				j++;
				strj[j] = '\0';
			}
			if(str[i] == '\0' && strj[0] != '\0')
			{
				j = 0;
				while (strj[j] != '\0')
				{
					write(1, &strj[j], 1);
					j++;
				}
				write(1, "\n", 1);
				break ;
			}
			else
				j = 0;
			if(str[i] == '\0')
				write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
