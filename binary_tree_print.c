#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

#define PRINT_WIDTH 5

static int _print_t(const binary_tree_t *tree, int is_left,
                    int offset, int depth, char s[20][255])
{
    char b[PRINT_WIDTH + 1];
    int left, right, i;

    if (!tree)
        return (0);

    sprintf(b, "(%03d)", tree->n);

    left = _print_t(tree->left, 1, offset, depth + 1, s);
    right = _print_t(tree->right, 0, offset + left + PRINT_WIDTH, depth + 1, s);

    for (i = 0; i < PRINT_WIDTH; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < PRINT_WIDTH + right; i++)
            s[depth - 1][offset + left + PRINT_WIDTH/2 + i] = '-';
        s[depth - 1][offset + left + PRINT_WIDTH/2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + PRINT_WIDTH; i++)
            s[depth - 1][offset - PRINT_WIDTH/2 + i] = '-';
        s[depth - 1][offset + left + PRINT_WIDTH/2] = '.';
    }

    return (left + PRINT_WIDTH + right);
}

void binary_tree_print(const binary_tree_t *tree)
{
    char s[20][255];
    int i;

    for (i = 0; i < 20; i++)
        sprintf(s[i], "%s", "");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
    {
        if (s[i][0] != '\0')
            printf("%s\n", s[i]);
    }
}
