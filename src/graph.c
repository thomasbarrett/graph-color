/**
 * @file graph_h
 * @author Thomas Barrett
 * @date 13 March 2019
 * @brief Implementation for graph functions
 */

#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "graph.h"

struct graph* graph_create(int size) {
    struct graph* self = malloc(sizeof(struct graph));
    self->adjacency_matrix = calloc(size * size, sizeof(int));
    self->size = size;
    return self;
}

void graph_destroy(struct graph* self) {
    free(self->adjacency_matrix);
    free(self);
}

void graph_add_edge(struct graph* self, int v1, int v2) {
   graph_add_directed_edge(self, v1, v2);
   graph_add_directed_edge(self, v2, v1);
}

void graph_add_directed_edge(struct graph* self, int v1, int v2) {
    assert(v1 < self->size && v2 < self->size && "vertex index out of bounds");
    self->adjacency_matrix[v1 * self->size + v2] = 1;
}

int graph_has_edge(const struct graph* self, int v1, int v2) {
    assert(v1 < self->size && v2 < self->size && "vertex index out of bounds");
    return self->adjacency_matrix[v1 * self->size + v2];
}

static int find_min_coloring(const int* row, const int* coloring, int size) {
    int color_set[size + 1];
    memset(color_set, 0, sizeof(int) * size + 1);

    for(int i = 0; i < size; i++) {
        if(row[i] != 0) {
            int color = coloring[i];
            color_set[color] = 1;
        }
    }
    for (int i = 1; i <= size; i++) {
        if (color_set[i] == 0) {
            return i;
        }
    }

    /* unreachable */
    return 0;
}

int graph_greedy_color(const struct graph* self, int* coloring) {
    int max_color = 0;
    if(self != NULL && self->size > 0) {
        coloring[0] = 1;
        for(int i = 1; i < self->size; i++) {
            int *row = self->adjacency_matrix + i * self->size;
            int color = find_min_coloring(row, coloring, self->size);
            coloring[i] = color;
            if(color > max_color) {
                max_color = color;
            }
        }
    }
    return max_color;
}

void graph_print(const struct graph* self) {
    for(int i = 0; i < self->size; i++) {
        for(int j = 0; j < self->size; j++) {
            printf("%d ", self->adjacency_matrix[i + self->size * j]);
        }
        printf("\n");
    }
}
