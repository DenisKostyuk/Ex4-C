#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LETTERS ((int)26) 

typedef struct node{
    bool finish;
    int counterOfSameWords;
    int tag;
    struct node *child[NUM_LETTERS];
    char c;
}node;

void addNode(node **root,char *str);
void freethetrie(node **head);
void lexUp(node **root, int ind,char *word);
void lexDown(node **root, int ind,char *word);
node* newNode();

