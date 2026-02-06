/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:44:13 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/06 22:17:25 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

static void	heapify_down(t_heap *heap, int i)
{
	int	left;
	int	right;
	int	smallest;

	while (1)
	{
		smallest = i;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < heap->size
			&& heap->array[left].priority_value
			< heap->array[smallest].priority_value)
			smallest = left;
		if (right < heap->size
			&& heap->array[right].priority_value
			< heap->array[smallest].priority_value)
			smallest = right;
		if (smallest == i)
			break ;
		swap_nodes(&heap->array[i], &heap->array[smallest]);
		i = smallest;
	}
}

t_heap	*init_heap(int max_size)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return (NULL);
	heap->array = malloc(sizeof(t_node) * max_size);
	if (!heap->array)
	{
		free(heap);
		return (NULL);
	}
	heap->size = 0;
	heap->capacity = max_size;
	return (heap);
}

int	heap_peek(t_heap *heap)
{
	if (heap->size == 0)
		return (-1);
	return (heap->array[0].coder_id);
}

void	heap_push(t_heap *heap, int id, long long prio)
{
	int	i;
	int	parent;

	if (heap->size >= heap->capacity)
		return ;
	i = heap->size;
	heap->array[i].coder_id = id;
	heap->array[i].priority_value = prio;
	heap->size++;
	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (heap->array[i].priority_value < heap->array[parent].priority_value)
		{
			swap_nodes(&heap->array[i], &heap->array[parent]);
			i = parent;
		}
		else
			break ;
	}
}

int	heap_pop(t_heap *heap)
{
	int	res_id;

	res_id = heap_peek(heap);
	if (res_id == -1)
		return (-1);
	heap->size--;
	if (heap->size > 0)
	{
		heap->array[0] = heap->array[heap->size];
		heapify_down(heap, 0);
	}
	return (res_id);
}

// int	main(void)
// {
// 	t_heap	*heap;

// 	heap = init_heap(10);
// 	if (!heap)
// 		return (-1);g
// 	heap_push(heap, 1, 100);
// 	heap_push(heap, 222, 300);
// 	heap_push(heap, 333, 300);
// 	heap_push(heap, 111, 0);
// 	printf("has lowest: [%d]\n", heap_pop(heap));
// 	printf("capacity :[%d]\n", heap->capacity);
// 	printf("size :[%d]\n", heap->size);
// 	return (0);
// }
