#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Crée un nouveau nœud d’arbre binaire
 * @parent: Pointeur vers le parent du nouveau nœud
 * @value: Valeur à mettre dans le nouveau nœud
 *
 * Return: Pointeur vers le nouveau nœud, ou NULL en cas d'échec
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    new = malloc(sizeof(binary_tree_t));
    if (new == NULL)
        return (NULL);

    new->n = value;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL;

    return (new);
}
