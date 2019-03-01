/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:55:05 by pben              #+#    #+#             */
/*   Updated: 2019/02/10 16:55:07 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_solution(t_list *head, int size)
{
	char	c;
	int		i;
	int		j;
	char	**map;	
	t_list	*f;
	
	c = 'A';
	map = create_map(size);
	while (head)
	{
		i = 0;
		while (i < head->y_max)
		{
			j = 0;
			while (j < head->x_max)
			{
				if (head->mtx[i][j] == '#')
					map[i + head->y][j + head->x] = c;
				j++;
			}
			i++;
		}
		c++;
		head = head->next;
	}
	ft_print(map, size);
	free_map(map, size);
}
