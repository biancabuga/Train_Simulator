/*BUGA Bianca Gabriela - 311CD*/
#include "../main.h"

deq_n *init_deque()
{
	deq_n *engine = alloc_deqN('>');
	deq_n *mechanic = alloc_deqN('#');

	if (engine && mechanic) {
		engine->prev = mechanic;
		engine->next = mechanic;

		mechanic->prev = engine;
		mechanic->next = engine;
	}

	return engine;
}

deq_n *alloc_deqN(char data)
{
	deq_n *node = (deq_n *)malloc(sizeof(deq_n));
	DIE(!node, "Memory allocation for deque node failed\n");

	if (node) {
		node->prev = NULL;
		node->data = data;
		node->next = NULL;
	}

	return node;
}

void free_deque(deq_n *sentinel)
{
	deq_n *current = sentinel->next;
	deq_n *next = NULL;

	while (current != sentinel) {
		next = current->next;
		free(current);
		current = next;
	}

	free(sentinel);
}
