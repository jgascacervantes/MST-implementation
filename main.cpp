#include <iostream>
#include <vector>
#include "Graph.h"
int find(int parent[], int i );
void uni(int parent[], int x, int y);
int detectCycle(Graph g);

/*
 * implementation of Kruskal's MST algorithm using union-find.
 * nodes will be represented as integers, edges as a source
 * and a destination node. MST will be a graph that adds to its
 * edge vector according to the algorithm.
 */

int main() {
    Graph g(3, 3); //create a graph with 3 vertices and 3 edges

    /*link the edges in a cyclic way*/
    g.edges.push_back(Graph::Edge(0,1, 12));
    g.edges.push_back(Graph::Edge(1,2, 2));
    g.edges.push_back(Graph::Edge(2,0, 6));

    /* MST representation*/
    Graph MST = g;

    if(detectCycle(MST))
        std::cout << "detected cycle" << std::endl;

    MST.printGraph();
    return 0;
}


//recursively find parent
int find(int parent[], int i) {
    if(parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

//unite two subsets
void uni(int *parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int detectCycle(Graph g) {
    int parent[g.v];
    std::fill_n(parent, g.v, -1);

    for(int i = 0; i < g.e; i++){
        int x = find(parent, g.edges[i].src);
        int y = find(parent, g.edges[i].dest);

        if (x == y)
            return 1;

        uni(parent, x, y);
    }
    return 0;
}


