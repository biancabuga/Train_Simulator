/*BUGA Bianca Gabriela - 311CD*/
#include "../main.h"

void search(char *pattern, train_t *train, FILE *output)
{
	int i;

	deq_n *current;
	deq_n *init;
	deq_n *start;

	start = train->mechanic;
	init = train->mechanic;
	do {
		current = start;

		for (i = 0; i < strnlen(pattern, sizeof(pattern)); i++) {
			if (current == train->engine)
				current = current->next;

			if (current->data != pattern[i])
				break;

			current = current->next;
		}

		if (i == strlen(pattern)) {
			train->mechanic = start;
			return;
		}

		start = start->next;
		if (start == train->engine)
			start = start->next;
	} while (init != start);

	fprintf(output, "ERROR\n");
}

void search_right(char *pattern, train_t *train, FILE *output)
{
	int i;

	deq_n *current;
	deq_n *init;
	deq_n *start;

	start = train->mechanic;
	init = train->mechanic;

	do {
		if (start == train->engine)
			start = start->next;

		current = start;

		for (i = 0; i < strlen(pattern); i++) {
			if (current == train->engine)
				current = current->next;

			if (current->data != pattern[i])
				break;

			current = current->next;
		}

		if (i == strlen(pattern)) {
			train->mechanic = current->prev;
			return;
		}

		start = start->next;
		if (start == train->engine)
			start = start->next;
	} while (init != start);

	fprintf(output, "ERROR\n");
}

void search_left(char *pattern, train_t *train, FILE *output)
{
	int i;

	deq_n *current;
	deq_n *init;
	deq_n *start;

	start = train->mechanic;
	init = train->mechanic;
	do {
		current = start;

		for (i = 0; i < strlen(pattern); i++) {
			if (current == train->engine)
				current = current->prev;

			if (current->data != pattern[i])
				break;

			current = current->prev;
		}

		if (i == strlen(pattern)) {
			train->mechanic = current->next;
			return;
		}

		start = start->prev;
		if (start == train->engine)
			start = start->prev;
	} while (init != start);

	fprintf(output, "ERROR\n");
}
