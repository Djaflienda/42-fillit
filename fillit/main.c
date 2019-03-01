/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:46:10 by pben              #+#    #+#             */
/*   Updated: 2019/02/04 14:46:12 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_read_tetro(int fd)
{
	char	**tab;
	int		ret;
	static int ret2;
	char	buffer[22];
	
	ret = read(fd, buffer, 21);
	buffer[ret] = '\0';
	
	if (ret == 0 && ret2 == 20)
		return (NULL);
	if (ret < 20)
	{
		write (1, "error\n", 6);
		exit(0);
	}
	if (!(tab = ft_strsplit(buffer, '\n')))
		exit(-1);
	ret2 = ret;
	return(tab);
}

int		ft_read(t_list **head, char *file)
{
	int		count;
	int 	fd;
	char 	**mtx;
	t_list	*f;

	count = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
			write (1, "error\n", 6);
	while ((mtx = ft_read_tetro(fd)) != NULL)
	{	
		if (valid(mtx) == 0 || count++ > 25)
		{
			ft_putstr("error\n");
			exit(0);
		}
		mtx = move_left_figure(mtx);
		list_add_tail(head, mtx);
	}
	f = *head;
	while (f)
	{
		find_x_y_max(f);
		f = f->next;
	}
	return(1);
}

int		main(int argc, char **argv)
{
	t_list	*head = NULL;
	int		size;
	char	**map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	ft_read(&head, argv[1]);
	size = 2;
	while (size < 16)
	{
		map = NULL;
		if (solver(head, map, size) == 1)
		{
			print_solution(head, size);
			free_list(&head);
			return (1);
		}
		else
			free_map(map, size++);
	}
	ft_putstr("No solution");
	return (0);
}
