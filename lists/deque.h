/*BUGA Bianca Gabriela - 311CD*/
// Structure for a node in the deque
typedef struct deq_n {
    struct deq_n *prev;    // Pointer to the previous node
    char data;             // Data stored in the node
    struct deq_n *next;    // Pointer to the next node
} deq_n;

// Initialize a deque
deq_n *init_deque();

// Allocate memory for a new deque node with given data
deq_n *alloc_deqN(char data);

// Free memory allocated for the deque
void free_deque(deq_n *engine);
