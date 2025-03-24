#ifndef BST_H
#define BST_H

typedef int Data;
typedef struct Node {
	Data data;
	struct Node * left;
	struct Node * right;
} Node;

void tree_print (Node * tree);

void print (Node * tree);

void tree_add (Node ** tree, Data x);

Node* tree_destroy (Node * tree);

Node* node_search (Node * tree, Data x);

Node* tree_delete_node (Node * tree, Data x);

#endif

