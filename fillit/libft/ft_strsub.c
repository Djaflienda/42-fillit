/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:26:53 by pben              #+#    #+#             */
/*   Updated: 2018/12/06 19:26:54 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (s[start] && (i < (int)len))
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
