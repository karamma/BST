#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void tree_print (Node * tree) {
	if (tree == NULL) {return;}
	tree_print(tree->left);
	printf("%d ", tree->data);
	tree_print(tree->right);
}

void print (Node * tree) {
	tree_print(tree);
	printf("\n");
}

Node* node_create (Data x) {
	Node* nd = malloc(sizeof(Node));
	nd->data = x;
	nd->left = nd->right = NULL;
	return nd;
}

void tree_add (Node ** tree, Data x) {
	if (*tree == NULL) {
		*tree = node_create(x);
	} else if ((*tree)->data < x) {
		tree_add(&(*tree)->right, x);
	} else if ((*tree)->data > x) {
		tree_add(&(*tree)->left,x );
	}
}

Node* tree_destroy (Node * tree) {
	if (tree == NULL) {return NULL;}
	tree_destroy(tree->left);
	tree_destroy(tree->right);
	free(tree);
	return NULL;
}

Node* node_search (Node * tree, Data x) {
	if (tree == NULL) {return NULL;}
	if (tree->data < x)  {return node_search(tree->right, x);}
	else if (tree->data > x)  {return node_search(tree->left, x);}
	return tree;
}

Node* tree_delete_node (Node * tree, Data x) {
	if (tree == NULL) {return NULL;}
	if (x < tree->data) {
		tree->left = tree_delete_node(tree->left, x);
	} else if (x > tree->data) {
		tree->right = tree_delete_node(tree->right, x); 
	} else {
		if (tree->left == NULL)  {
			Node * change = tree->right;
			free(tree);
			return change;
		}
		if (tree->right == NULL) {
			Node * change = tree->left;
			free(tree);
			return change;
		}

		Node * change = tree->right;
		for (; change->left != NULL; change = change->left);
		tree->data = change->data;
		tree->right = tree_delete_node(tree->right, tree->data);
	}
	return tree;
}
