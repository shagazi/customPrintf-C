/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:06:17 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/19 17:34:16 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *ptr, size_t size)
{
	void *copiedstring;

	if (!(copiedstring = (void *)malloc(sizeof(size))))
		return (NULL);
	return (ft_memcpy(copiedstring, ptr, size));
}
