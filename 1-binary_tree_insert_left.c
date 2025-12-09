#include "binary_trees.h"

/**
 * binary_tree_insert_left - insère un nœud en tant qu’enfant gauche
 * @parent: pointeur vers le nœud parent
 * @value: valeur à mettre dans le nouveau nœud
 *
 * Return: pointeur vers le nouveau nœud, ou NULL en cas d'erreur
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    if (parent == NULL)
        return (NULL);

    new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    /* Si un enfant gauche existe déjà, on le pousse sous le nouveau nœud */
    if (parent->left != NULL)
    {
        new->left = parent->left;
        parent->left->parent = new;
    }

    parent->left = new;

    return (new);
}
