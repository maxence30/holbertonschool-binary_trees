#include "binary_trees.h"

/**
 * depth_leftmost - Computes depth of leftmost leaf
 * @tree: pointer to tree
 * Return: depth
 */
int depth_leftmost(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_recursive - Checks if perfect
 * @tree: pointer
 * @depth: expected depth
 * @level: current level
 * Return: 1 or 0
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (1);

	/* leaf */
	if (!tree->left && !tree->right)
		return (depth == level + 1);

	/* missing one child => not perfect */
	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to root
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (!tree)
		return (0);

	depth = depth_leftmost(tree);

	return (is_perfect_recursive(tree, depth, 0));
}
