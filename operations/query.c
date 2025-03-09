/*BUGA Bianca Gabriela - 311CD*/
#include "../main.h"

void show(train_t *train, FILE *output)
{
	deq_n *current = train->engine->next;

	while (current != train->engine) {
		if (current == train->mechanic)
			fprintf(output, "|%c|", current->data);
		else
			fprintf(output, "%c", current->data);

		current = current->next;
	}

	fprintf(output, "\n");
}

void show_current(train_t *train, FILE *output)
{
	fprintf(output, "%c\n", train->mechanic->data);
}

void switchQ(queue_t *queue)
{
	if (!queue || !queue->head || !queue->head->next)
		return;

	que_n *prev = NULL;
	que_n *current = queue->head;
	que_n *next = NULL;
	queue->tail = queue->head;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	queue->head = prev;
}
