/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:20:15 by pben              #+#    #+#             */
/*   Updated: 2018/12/06 21:20:17 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (ft_space(s[i - 1]))
		i--;
	while (ft_space(*s) && i > 0)
	{
		s++;
		i--;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	ft_memcpy(str, s, i);
	return (str);
}
