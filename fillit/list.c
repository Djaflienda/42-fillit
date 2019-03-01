/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:09:45 by pben              #+#    #+#             */
/*   Updated: 2019/02/14 16:09:47 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list  *list_new(char **mtx)
{
	t_list *head;

	head = (t_list*)malloc(sizeof(t_list));
	head->mtx = mtx;
	head->x = 0;
	head->y = 0;
	head->x_max = 0;
	head->y_max = 0;
	head->next = NULL;
	return (head);
}

void list_add_tail(t_list **head, char **mtx)
{
	while(*head != NULL)
		head = &((*head)->next);
	*head = list_new(mtx);
}

void	free_list(t_list **head)
{
	t_list	*tmp;
	size_t	i;

	while(*head)
	{
		tmp = (*head)->next;
		i = 0;
		while ((*head)->mtx[i] != NULL)
		{
			free((*head)->mtx[i]);
			i++;
		}
		free((*head)->mtx);
		free(*head);
		*head = tmp;
	}
}
