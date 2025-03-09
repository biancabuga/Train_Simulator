/*BUGA Bianca Gabriela - 311CD*/
#include "../main.h"

void move_right(train_t *train)
{
	if (train->mechanic->next != train->engine) {
		train->mechanic = train->mechanic->next;
		return;
	}

	deq_n * new_vagon = alloc_deqN('#');

	new_vagon->next = train->engine;
	new_vagon->prev = train->mechanic;

	train->mechanic->next = new_vagon;

	train->mechanic = new_vagon;
}

void move_left(train_t *train)
{
	if (train->mechanic->prev != train->engine)
		train->mechanic = train->mechanic->prev;
	else
		train->mechanic = train->engine->prev;
}

void write(train_t *train, char inscription)
{
	train->mechanic->data = inscription;
}

void insert_right(train_t *train, char inscription)
{
	deq_n *new_vagon = alloc_deqN(inscription);

	new_vagon->next = train->mechanic->next;
	new_vagon->prev = train->mechanic;

	train->mechanic->next->prev = new_vagon;
	train->mechanic->next = new_vagon;

	train->mechanic = new_vagon;
}

void insert_left(train_t *train, char inscription, FILE *output)
{
	if (train->mechanic == train->engine->next) {
		fprintf(output, "ERROR\n");
		return;
	}

	deq_n *new_vagon = alloc_deqN(inscription);

	new_vagon->next = train->mechanic;
	new_vagon->prev = train->mechanic->prev;

	train->mechanic->prev->next = new_vagon;
	train->mechanic->prev = new_vagon;

	train->mechanic = new_vagon;
}

void clear_all(train_t *train)
{
	free_deque(train->engine);
	*train = init_train();
}

void clear_cell(train_t *train)
{
	deq_n *to_delete = train->mechanic;

	train->mechanic->prev->next = train->mechanic->next;
	train->mechanic->next->prev = train->mechanic->prev;

	train->mechanic = train->mechanic->prev;
	if (train->mechanic == train->engine)
		train->mechanic = train->engine->prev;

	free(to_delete);
}
