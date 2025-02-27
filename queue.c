/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:31:19 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/27 21:16:40 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = malloc (sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->top = NULL;
	queue->bottom = NULL;
	return (queue);
}

void	enqueue(t_queue *queue, t_point pos)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->pos = pos;
	new_node->next = NULL;
	if (!queue->bottom)
		queue->top = new_node;
	else
		queue->bottom->next = new_node;
	queue->bottom = new_node;
}

t_point	dequeue(t_queue *queue)
{
	t_point pos = {-1, -1};
	t_node	*temp;

	if (!queue->top)
		return (pos);
	temp = queue->top;
	pos = temp->pos;
	queue->top = queue->top->next;
	if (!queue->top)
		queue->bottom = NULL;
	free(temp);
	return (pos);
}



/*int main(void)
{
    t_queue *queue = init_queue();
    if (!queue)
    {
        printf("Erreur : allocation de la file\n");
        return (1);
    }
    // Ajouter des éléments
    printf("Enqueue (1,1)\n");
    enqueue(queue, (t_point){1, 1});
    
    printf("Enqueue (2,2)\n");
    enqueue(queue, (t_point){2, 2});
    
    printf("Enqueue (3,3)\n");
    enqueue(queue, (t_point){3, 3});

    // Retirer les éléments
    while (queue->top)
    {
        t_point p = dequeue(queue);
        printf("Dequeue -> (%d, %d)\n", p.x, p.y);
    }

    // Libérer la mémoire de la file
    free(queue);

    return (0);
}*/
