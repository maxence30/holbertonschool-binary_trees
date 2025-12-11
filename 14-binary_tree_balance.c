#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_h = 0, right_h = 0;

    if (tree == NULL)
        return (0);

    if (tree->left)
        left_h = 1 + binary_tree_height(tree->left);
    if (tree->right)
        right_h = 1 + binary_tree_height(tree->right);

    return (left_h - right_h);
}
