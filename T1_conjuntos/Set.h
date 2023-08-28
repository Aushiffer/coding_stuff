#include <stdbool.h>

#define MAX_SIZE 256

/* estrutura do conjutno */
struct set {
        int size;
        int elements[MAX_SIZE];
};

/* imprime a união de s1 e s2 */
void printUnion(struct set s1, struct set s2);

/* imprime a intersecção de s1 e s2 */
void printIntersection(struct set s1, struct set s2);

/* imprime a diferença entre s1 e s2 */
void printDifference(struct set s1, struct set s2);

/* verifica se s1 é um subconjunto de s2 */
bool isSubset(struct set s1, struct set s2);

/* verifica se um natural x pertence à s1 */
bool isIn(struct set s1, int x);

/* verifica se S é vazio */
bool isEmpty(struct set s);

/* retorna o tamanho de S */
int size(struct set s);

/* ordena S em ordem crescente */
void sortSet(struct set s);

/* imprime os elementos de S */
void printSet(struct set s);
