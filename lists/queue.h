/*BUGA Bianca Gabriela - 311CD*/
#define BUFFER 32

// Structure for a node in the queue
typedef struct que_n {
	char command[BUFFER];
	struct que_n *next;
} que_n;

// Structure for the queue itself
typedef struct queue_t {
	que_n *head;
	que_n *tail;
} queue_t;

// Initialize a queue
queue_t *init_queue();

// Push a command onto the queue
que_n *push(queue_t *queue, char *command);

// Pop a command from the queue
void pop(queue_t *queue);

// Free memory allocated for the queue
void free_queue(queue_t *head);

