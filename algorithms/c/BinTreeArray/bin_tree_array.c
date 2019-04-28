#ifndef BIN_TREE_ARRAY_
#define BIN_TREE_ARRAY_

#include <stdint.h>
#include <stdlib.h>

struct bin_tree_array {
        int *array;
};

struct bin_tree_array* bin_tree_array_new(size_t size)
{
        struct bin_tree_array* bin_tree = 
                (struct bin_tree_array*)malloc(sizeof(struct bin_tree_array));

        bin_tree->array = (int*)malloc(size*sizeof(int));

        return bin_tree;
}

void bin_tree_array_destory(struct bin_tree_array* bin_tree)
{
        free(bin_tree->array);
        free(bin_tree);
}

#endif // BIN_TREE_ARRAY_
