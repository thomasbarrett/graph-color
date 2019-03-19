/**
 * @file graph.h
 * @author Thomas Barrett
 * @date 13 March 2019
 * @brief Declarations for graph struct and functions
 */
#ifndef GRAPH_H
#define GRAPH_H

/**
 * @brief A graph data structure. 
 */
struct graph {
    int* adjacency_matrix;
    int size;
};

/**
 * @brief Constructs a graph with the specified number of nodes.
 * @param size the number of nodes
 * @return an intitialized graph
 */
struct graph* graph_create(int size);

/**
 * @brief Destructor
 * @param self the graph to destroy
 */
void graph_destroy(struct graph* self);

/**
 * @brief Adds an undirected edge between vertices 'v1' and 'v2'.
 * @param self the graph
 * @param v1 the first vertex
 * @param v2 the second vertex
 */
void graph_add_edge(struct graph* self, int v1, int v2);

/**
 * @brief Adds a directed edge from vertex 'v1' to 'v2'.
 * @param self the graph
 * @param v1 the first vertex
 * @param v2 the second vertex
 */
void graph_add_directed_edge(struct graph* self, int v1, int v2);

/**
 * @brief Checks if an edge exists between vertices 'v1' and 'v2'.
 * @param self the graph
 * @param v1 the first vertex
 * @param v2 the second vertex
 */
int graph_has_edge(const struct graph* self, int v1, int v2);

/**
 * @brief Colorizes the graph with as few colors as possible.  
 * @param self the graph
 * @param coloring the graph coloring result
 * @return the number of colors used
 */
int graph_greedy_color(const struct graph* self, int* coloring);

/**
 * @brief Prints the adjacency matrix to stdout
 * @param self the graph
 */
void graph_print(const struct graph* self);

#endif /* GRAPH_H */
