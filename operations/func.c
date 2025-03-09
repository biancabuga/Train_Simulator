/*BUGA Bianca Gabriela - 311CD*/
#include "../main.h"

void execute(queue_t *commands, train_t *train, FILE *output)
{
	if (commands->head)
		run(commands, train, output);
}

void run(queue_t *commands, train_t *train, FILE *output)
{
	char command[BUFFER];

	strncpy(command, commands->head->command, BUFFER);
	pop(commands);

	// fprintf(output, "Text:\t");
	// show(train, output);
	// fprintf(output,"command: %s\tOutput: ", command);

	// UPDATE

	if (strncmp(command, "MOVE_RIGHT", strlen("MOVE_RIGHT")) == 0) {
		move_right(train);
		return;
	}

	if (strncmp(command, "MOVE_LEFT", strlen("MOVE_LEFT")) == 0) {
		move_left(train);
		return;
	}

	if (strncmp(command, "WRITE", strlen("WRITE")) == 0) {
		write(train, command[strlen("WRITE") + 1]);
		return;
	}

	if (strncmp(command, "INSERT_RIGHT", strlen("INSERT_RIGHT")) == 0) {
		insert_right(train, command[strlen("INSERT_RIGHT") + 1]);
		return;
	}

	if (strncmp(command, "INSERT_LEFT", strlen("INSERT_LEFT")) == 0) {
		insert_left(train, command[strlen("INSERT_LEFT") + 1], output);
		return;
	}

	if (strncmp(command, "CLEAR_ALL", strlen("CLEAR_ALL")) == 0) {
		clear_all(train);
		return;
	}

	if (strncmp(command, "CLEAR", strlen("CLEAR")) == 0) {
		clear_cell(train);
		return;
	}

	// SEARCH

	if (!strncmp(command, "SEARCH_RIGHT", strlen("SEARCH_RIGHT"))) {
		search_right(command + strlen("SEARCH_RIGHT") + 1, train, output);
		return;
	}

	if (!strncmp(command, "SEARCH_LEFT", strlen("SEARCH_LEFT"))) {
		search_left(command + strlen("SEARCH_LEFT") + 1, train, output);
		return;
	}

	if (!strncmp(command, "SEARCH", strlen("SEARCH"))) {
		search(command + strlen("SEARCH") + 1, train, output);
		return;
	}
}

void manage(char *command, queue_t *commands, train_t *train, FILE *output)
{
	command[strlen(command) - 1] = '\0'; // strip the newline

	// QUERY

	if (!strncmp(command, "SHOW_CURRENT", strlen("SHOW_CURRENT"))) {
		show_current(train, output);
		return;
	}

	if (!strncmp(command, "SHOW", strlen("SHOW"))) {
		show(train, output);
		return;
	}

	if (strncmp(command, "SWITCH", strlen("SWITCH")) == 0) {
		switchQ(commands);
		return;
	}

	// EXECUTE

	if (!strncmp(command, "EXECUTE", strlen("EXECUTE"))) {
		execute(commands, train, output);
		return;
	}

	// UPDATE
	push(commands, command);
}


train_t init_train()
{
	train_t train;
	train.engine = init_deque();
	train.mechanic = train.engine->next;

	return train;
}
