/*BUGA Bianca Gabriela - 311CD*/
#include "main.h"

int main(int argc, char *argv[])
{
	// File management
	FILE *input = fopen("tema1.in", "rt");
		if (!input) {
		printf("Error: Unable to open file.\n");
		printf("Error code: %d\n", errno);
		return 1;
	}

	FILE *output = fopen("tema1.out", "w");
	if (!output) {
		printf("Error: Unable to open file.\n");
		printf("Error code: %d\n", errno);
		return 1;
	}

	// Initial setup
	train_t train = init_train();
	queue_t *commands = init_queue();

	// Read commands
	int number_of_commands;
	char command[BUFFER];

	fscanf(input, "%d", &number_of_commands);
	fgetc(input);

	for (int i = 0; i < number_of_commands; i++) {
		fgets(command, BUFFER, input);
		manage(command, commands, &train, output);
	}

	// Memory management
	free_deque(train.engine);
	free_queue(commands);

	// Close files
	fclose(input);
	fclose(output);

	return 0;
}

