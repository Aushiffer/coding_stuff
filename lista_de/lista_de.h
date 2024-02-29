typedef struct Node {
	struct Node *next;
	struct Node *prev;
	int data;
} node_t;

typedef struct DL_List {
	node_t *head;
	node_t *tail;
	int size;
} dl_list;

// Creates a new node
node_t *new_node();

// Creates a new list
dl_list *new_list();

// Returns the size of the list
int size_list(dl_list *dll);

// Checks if the list is empty
int empty_list(dl_list *dll);

// Inserts a node into the list, with an specified value
void insert_node(dl_list *dll, node_t *n);

// Removes a node from the list with the specified value and returns it's data
int remove_node(dl_list *dll, int value);

// Removes the head
int remove_head(dl_list *dll);

// Removes the tail
int remove_tail(dl_list *dll);

// Frees the list and it's nodes
void free_list(dl_list *dll);

// Prints the list with printf, on the terminal
void print_list(dl_list *dll);
