// Set ADT
typedef struct Set {
	int abs_size;
	int max_size;
	int *elements;
} set_t;

// Creates a new set
set_t *new_set();

// Returns the absolute size of the set
int size_set(set_t *s);

// Checks if 'a' exists in 's'
int exists_in_set(set_t *s, int a);

/* Insertion Sort 
 * This algo was chosen because at the moment of insertion of a new value, the set is already sorted, therefore making it O(n)) */
void insertion_sort(int *set_array, int b);

// Puts 'a' into 's'
void insert_in_set(set_t *s, int a);

// Removes 'a' from 's'
void remove_from_set(set_t *s, int a);

// Checks if 's' is empty
int is_set_empty(set_t *s);

// Frees 's' and its elements
void free_set(set_t *s);

// Prints all elements of 's'
void print_set(set_t *s);

// Returns the union between 's1' and 's2'
set_t *unite(set_t *s1, set_t *s2);

// Returns the intersection between 's1' and 's2'
set_t *intersect(set_t *s1, set_t *s2);