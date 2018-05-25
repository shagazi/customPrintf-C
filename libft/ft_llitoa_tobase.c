/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_tobase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:39:52 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/11 17:41:59 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llitoa_tobase(long long int n, char *base)
{
	unsigned long long int	nbr;
	int						len;
	int						base_len;
	char					*str;

	base_len = ft_strlen(base);
	nbr = (unsigned long long int)n;
	nbr = n < 0 ? -nbr : nbr;
	len = 2;
	while (nbr /= base_len)
		len++;
	nbr = (unsigned long long int)n;
	nbr = n < 0 ? -nbr : nbr;
	len += n < 0;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len-- > 0)
	{
		str[len] = base[nbr % base_len];
		nbr /= base_len;
	}
	str[0] = n < 0 ? '-' : str[0];
	return (str);
}
