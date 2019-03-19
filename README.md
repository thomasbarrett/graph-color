# Graph Coloring
This repository contains code to color a graph with as few colors as possible. Since k-coloring a graph is an NP-complete problem, this repository employs a greedy algorithm to attempt to use as few colors as possible. Graph coloring is useful in many domains related to scheduling - notable the register allocation problem in compiler design.

# Usage
To use the graph_color program, simply input the number of nodes of the graph that you would like to colorize followed by pairs of integers representing edges. For example, to colorize a simple triangle, use the following input.

```shell
graph_color 3 0 1 1 2 2 0
```