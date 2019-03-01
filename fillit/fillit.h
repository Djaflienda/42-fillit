/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:31:17 by pben              #+#    #+#             */
/*   Updated: 2019/01/11 19:31:19 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
#include <fcntl.h>

typedef struct s_list
{
	char **mtx; // matrix for figurka
	int x; // координтаты первой точки
	int y;      
	int x_max; // ширина
	int y_max;// высота
	struct s_list *next;
}              	t_list;

char **ft_read_tetro(int fd);
int valid(char **tab);
char **move_left_figure(char **tab);
int check2(int i, int j, char **tab);
int check(char **tab);
t_list  *list_new(char **mtx);
void list_add_tail(t_list **head, char **mtx);
void free_list(t_list **head);
int find_x_y_max(t_list *list);
char	**create_map(int size);
int		add_figure(t_list *f, char **map, int size);
int move_figure(t_list *f, char **map, int size);
char	**map_copy(char **map, int size);
void	free_map(char **tmp_map, int size);
void 	dell_figure(t_list *f, char **map);
int		 solver(t_list *f, char **map, int size);
void	ft_print_mtx(char **mtx);
int add_solver(t_list *f, char **map, int size, char **tmp_map);
void    print_solution(t_list *head, int size);
#endif
