/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:13:09 by pben              #+#    #+#             */
/*   Updated: 2018/12/06 15:13:12 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if ((str = (char *)malloc(size * sizeof(*str))) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
