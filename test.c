#include <stdio.h>
#include <assert.h>
#include "BST.h"

void test_tree_add() {
    Node *tree = NULL;

    tree_add(&tree, 5);
    tree_add(&tree, 3);
    tree_add(&tree, 7);
    tree_add(&tree, 2);
    tree_add(&tree, 4);
    tree_add(&tree, 6);
    tree_add(&tree, 8);

    printf("Tree after adding elements: ");
    print(tree);

    assert(node_search(tree, 5) != NULL);
    assert(node_search(tree, 3) != NULL);
    assert(node_search(tree, 7) != NULL);
    assert(node_search(tree, 2) != NULL);
    assert(node_search(tree, 4) != NULL);
    assert(node_search(tree, 6) != NULL);
    assert(node_search(tree, 8) != NULL);
    assert(node_search(tree, 1) == NULL);
    assert(node_search(tree, 9) == NULL);

    printf("test_tree_add passed!\n");

    tree = tree_destroy(tree);
    assert(tree == NULL);
}

void test_tree_destroy() {
    Node *tree = NULL;

    tree_add(&tree, 5);
    tree_add(&tree, 3);
    tree_add(&tree, 7);

    tree = tree_destroy(tree);
    assert(tree == NULL);

    printf("test_tree_destroy passed!\n");
}

void test_node_search() {
    Node *tree = NULL;

    tree_add(&tree, 5);
    tree_add(&tree, 3);
    tree_add(&tree, 7);
    tree_add(&tree, 2);
    tree_add(&tree, 4);
    tree_add(&tree, 6);
    tree_add(&tree, 8);

    assert(node_search(tree, 5)->data == 5);
    assert(node_search(tree, 3)->data == 3);
    assert(node_search(tree, 7)->data == 7);
    assert(node_search(tree, 2)->data == 2);
    assert(node_search(tree, 4)->data == 4);
    assert(node_search(tree, 6)->data == 6);
    assert(node_search(tree, 8)->data == 8);
    assert(node_search(tree, 1) == NULL);
    assert(node_search(tree, 9) == NULL);

    printf("test_node_search passed!\n");

    tree = tree_destroy(tree);
    assert(tree == NULL);
}

void test_empty_tree() {
    Node *tree = NULL;

    assert(node_search(tree, 5) == NULL);

    tree = tree_destroy(tree);
    assert(tree == NULL);

    printf("test_empty_tree passed!\n");
}
