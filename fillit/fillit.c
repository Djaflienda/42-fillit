/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:31:32 by pben              #+#    #+#             */
/*   Updated: 2019/01/11 19:31:34 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
 
char	**create_map(int size)
{
	char	**mtx;
	int		i;
	int		j;

	mtx = (char**)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		mtx[i] = (char*)malloc(sizeof(char) * (size + 1));
		j= 0;
		while (j < size)
		{
			mtx[i][j] = '.';
			j++;
		}
		i++;
	}
	mtx[i] = NULL;
	return(mtx);
}

int		add_figure(t_list *f, char **map, int size)
{
	int		i;
	int		j;
	
	i = 0;
 	while ((i + f->y) < size && i < 4)
	{
		j = 0;
		while ((j + f->x) < size && j < 4) 
		{
			if ((map[i + f->y][j + f->x] == '#' && f->mtx[i][j] == '#') 
			|| (f->x_max + f->x > size) || (f->y_max + f->y > size))
				return (0);
			if (f->mtx[i][j] == '#')
			{
				map[i + f->y][j + f->x] = f->mtx[i][j];
				j++;
			}
			else 
				j++;
		} 
		i++;
	}
	return (1);
}

int		move_figure(t_list *f, char **map, int size) 
{
	int		i;
	int		j;
	
	if (f->x + f->x_max < size)
	{
		f->x++;
		return(1);
	}	
	else if (f->y + f->y_max < size)
	{
		f->y++;
		f->x = 0;
		return (1);
	}
	f->x = 0;
	f->y = 0;
	return (0);
}

void	free_map(char **tmp_map, int size)
{
	int i;
	i = 0;
	while (tmp_map && i < size)
	{
		free(tmp_map[i]);
		i++;
	}
	free(tmp_map);
}

char	**map_copy(char **map, int size)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = create_map(size);
	i = 0;
	if (map)
	{
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				new_map[i][j] = map[i][j];
				j++;
			}
			i++;
		}
	}
	return (new_map);
}

int solver(t_list *f, char **map, int size)
{                                                                                                                                                                             
	char	**tmp_map;

	if (f == NULL)
		return (1);
	tmp_map = map_copy(map, size);
 	while (1)
 	{
		if (add_figure(f, tmp_map, size))
		{
			if ((solver(f->next, tmp_map, size)) == 1)
			{
				free_map(tmp_map, size);
				return(1);
			}
		}
		if (move_figure(f,tmp_map, size) == 0)
		{
			free_map(tmp_map, size);
			return(0);
		}
		else 
		{
			free_map(tmp_map, size);
			tmp_map = map_copy(map, size);
		}
	}
	free_map(tmp_map, size);
}	
