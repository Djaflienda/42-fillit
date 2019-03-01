/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:17:26 by pben              #+#    #+#             */
/*   Updated: 2019/02/07 20:17:28 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int valid(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i]) 
	{
		if (i > 4)
			return(0);
		j = 0;
		if ((ft_strlen(tab[i])) != 4)
			return (0);
		while (tab[i][j])
		{
			if (j > 4 && (tab[i][j] != '#' && tab[i][j] != '.'))
				return(0); 
			if (check(tab) == 0)
				return(0);
			j++;
		}
	i++;
	}
	return(1);
}

void	ft_shift(char **tab, int i, int j)
{
	int		k;
	char	tmp_c;
	char	*tmp;
	
	k = 0;
	while(k < i)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = tmp;
		k++;
	}
	i = 0;
	while (i < 4)
	{
		k = 0;
		while(k < j)
		{
			tmp_c = tab[i][0];
			tab[i][0] = tab[i][1];
			tab[i][1] = tab[i][2];
			tab[i][2] = tab[i][3];
			tab[i][3] = tmp_c;
			k++;
		}
		i++;
	}
}

char	**move_left_figure(char **tab)
{
	char *tmp;
	int i;
	int j;
	
	j = 0;
	while (j < 4)
	{
		if (tab[0][j] == '.' && tab[1][j] == '.' &&
			tab[2][j] == '.' && tab[3][j] == '.')
			j++;
		else 
			break;
	}
	i = 0;
	while (i < 4)
	{
		if(ft_strchr(tab[i], '#') == 0)
			i++;			
		else
			break ;
	}
	ft_shift(tab, i, j);
	return(tab);
}

int		check2(int i, int j, char **tab)
{
	int links;
	
	links = 0;
	if (i > 0)
	{
		if (tab[i][j] == tab[i - 1][j])
		links++;
	}
	if (i < 3)
	{
		if (tab[i][j] == tab[i + 1][j])
		links++;
	} 
	if (j > 0)
	{
		if (tab[i][j] == tab[i][j - 1])
		links++;
	}
	if (j < 3)
	{
		if (tab[i][j] == tab[i][j + 1])
		links++;
	}
	return(links);
}

int		check(char **tab)
{
    int		i;
    int		j;
	int		links_all;
	int		count;

	i = 0;
	links_all = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			if (tab[i][j] == '#' )
			{
				links_all += check2(i, j, tab);
				count++;
            }
			j++;
		}
        i++;
    }
	if (count > 4)
		return(0);
	if (links_all >= 6)
    	return(1);
	else 
		return(0); 
}