/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:05:57 by pben              #+#    #+#             */
/*   Updated: 2018/12/02 13:06:00 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n && s1 && (*((unsigned char*)s1) == *((unsigned char *)s2)))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
