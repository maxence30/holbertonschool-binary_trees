#include "binary_trees.h"

/**
 * binary_tree_insert_right - insère un nœud à droite d’un parent
 * @parent: pointeur vers le nœud parent
 * @value: valeur à mettre dans le nouveau nœud
 *
 * Return: pointeur vers le nouveau nœud, ou NULL si échec ou parent NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    if (parent == NULL)
        return (NULL);

    new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    /* Si un enfant droit existe déjà, on le pousse sous le nouveau nœud */
    if (parent->right != NULL)
    {
        new->right = parent->right;
        parent->right->parent = new;
    }

    parent->right = new;

    return (new);
}
