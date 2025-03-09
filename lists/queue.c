/*BUGA Bianca Gabriela - 311CD*/
#include "../main.h"

queue_t *init_queue()
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	if (queue) {
		queue->head = NULL;
		queue->tail = NULL;
	}

	return queue;
}

que_n *push(queue_t *queue, char *command)
{
	que_n *node = (que_n *)malloc(sizeof(que_n));
	DIE(!node, "Memory allocation for queue node failed\n");

	if (node) {
		strncpy(node->command, command, BUFFER);
		node->next = NULL;

		if (!queue->head) {
			queue->head = node;
			queue->tail = node;
		} else {
			queue->tail->next = node;
			queue->tail = node;
		}
	}

	return node;
}

void pop(queue_t *queue)
{
	if (queue->head) {
		que_n *node = queue->head;
		queue->head = queue->head->next;
		free(node);
	}
}

void free_queue(queue_t *queue)
{
	que_n *current = queue->head;
	que_n *next = NULL;

	while (current) {
		next = current->next;
		free(current);
		current = next;
	}

	free(queue);
}