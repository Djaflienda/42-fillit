/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:41:15 by pben              #+#    #+#             */
/*   Updated: 2018/12/02 11:41:19 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	if (s1 < s2)
		ft_memcpy(s1, s2, len);
	else if (s1 > s2)
	{
		while (len--)
		{
			s1[len] = s2[len];
		}
	}
	return (s1);
}
