/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:28:16 by pben              #+#    #+#             */
/*   Updated: 2018/12/04 19:28:18 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t j;

	j = c;
	i = ft_strlen(s);
	while (0 != i && s[i] != (char)j)
		i--;
	if (s[i] == (char)j)
		return ((char *)s + i);
	return (NULL);
}
