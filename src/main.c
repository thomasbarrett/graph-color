/**
 * @file main.c
 * @author Thomas Barrett
 * @date 13 March 2019
 * @brief Entry point for graph colorizor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

const char* usage = "usage: graph_color vertex_count [v1 v2 ...]";

int main(int argc, char const *argv[]) {

    if (argc == 1) {
        printf("%s\n", usage);
    } else {
        int vertex_count = atoi(argv[1]);
        
        /* constructs a new graph of size given in arguments */
        struct graph *g = graph_create(vertex_count);

        /* iterates through argument list and adds edges as given */
        for(int i = 2; i + 1 < argc; i+=2) {
            int v1 = atoi(argv[i]);
            int v2 = atoi(argv[i + 1]);
            int max = v1 > v2 ? v1: v2;

            if (max >= vertex_count) {
                printf("error: vertex %d out of bounds for graph of size %d\n", v1, vertex_count);
                return -1;
            } else {
                graph_add_edge(g, v1, v2);
            }
        }
        
        /* creates and intializes vla to hold coloring */
        int coloring[g->size];
        memset(coloring, 0, g->size * sizeof(int));

        /* colors graph */
        graph_greedy_color(g, coloring);
        
        /* prints graph coloring to user */
        for(int i = 0; i < g->size; i++) {
            printf("%d ", coloring[i]);
        }
        printf("\n");
        
        graph_destroy(g);
    }
    return 0;
}
