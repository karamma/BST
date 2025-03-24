#include <stdio.h>
#include <assert.h>
#include "BST.h"

void test_bst() {
    printf("=== Начало тестирования BST ===\n");
    
    // 1. Тест создания и добавления элементов
    Node* root = NULL;
    tree_add(&root, 50);
    tree_add(&root, 30);
    tree_add(&root, 70);
    tree_add(&root, 20);
    tree_add(&root, 40);
    tree_add(&root, 60);
    tree_add(&root, 80);
    
    printf("Дерево после добавления элементов: ");
    print(root);  // Ожидаемый вывод: 20 30 40 50 60 70 80
    
    // 2. Тест поиска элементов
    assert(node_search(root, 50) != NULL);
    assert(node_search(root, 30) != NULL);
    assert(node_search(root, 99) == NULL);
    printf("Тест поиска пройден успешно\n");
    
    // 3. Тест удаления листа (узла без детей)
    root = tree_delete_node(root, 20);
    printf("После удаления 20: ");
    print(root);  // Ожидаемый вывод: 30 40 50 60 70 80
    assert(node_search(root, 20) == NULL);
    assert(root->left->left == NULL);
    
    // 4. Тест удаления узла с одним ребенком
    root = tree_delete_node(root, 30);
    printf("После удаления 30: ");
    print(root);  // Ожидаемый вывод: 40 50 60 70 80
    assert(node_search(root, 30) == NULL);
    assert(root->left->data == 40);
    
    // 5. Тест удаления узла с двумя детьми
    root = tree_delete_node(root, 50);
    printf("После удаления 50: ");
    print(root);  // Ожидаемый вывод: 40 60 70 80
    assert(node_search(root, 50) == NULL);
    assert(root->data == 60);  // Преемник должен заменить корень
    
    // 6. Тест удаления несуществующего узла
    Node* before = root;
    root = tree_delete_node(root, 99);
    assert(root == before);  // Дерево не должно измениться
    printf("Попытка удаления несуществующего узла не изменила дерево\n");
    
    // 7. Проверка структуры после всех операций
    printf("Финальное состояние дерева: ");
    print(root);
    
    // 8. Тест очистки дерева
    root = tree_destroy(root);
    assert(root == NULL);
    printf("Дерево успешно очищено\n");
    
    printf("=== Все тесты пройдены успешно ===\n\n");
}
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
