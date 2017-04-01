#include <iostream>
#include <vector>
#include "Graph.h"
int find(int parent[], int i );
void uni(int parent[], int x, int y);
int detectCycle(const Graph& g);
bool compareWeight(const Graph::Edge e1, const Graph::Edge e2);


/*
 * implementation of Kruskal's MST algorithm using union-find.
 * nodes will be represented as integers, edges as a source
 * and a destination node. MST will be a graph that adds to its
 * edge vector according to the algorithm.
 */

int main() {
    Graph g(3, 3); //create a graph with 3 vertices and 3 edges

    g.edges.push_back(Graph::Edge(0,1, 12));
    g.edges.push_back(Graph::Edge(1,2, 2));
    g.edges.push_back(Graph::Edge(2,0, 6));
    //sort edges by weight so we check the lightest ones first
    std::sort(g.edges.begin(), g.edges.end(), compareWeight);
    /* MST representation*/
    Graph MST(3,1);
    int i = 1;
    MST.edges.push_back(g.edges[0]);


    /*a full MST has V-1 edges
     *push an edge to our MST, check for cycle, pop if cycle detected
     */
    while(MST.e < g.v - 1){
        MST.edges.push_back(g.edges[i]);
        MST.e++;
        if(detectCycle(MST)){
            MST.edges.pop_back();
            MST.e--;
        }
        i++;
    }

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
void uni(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int detectCycle(const Graph& g) {
    Graph gr = g;
    int parent[gr.v];
    std::fill(parent, parent + sizeof(parent), -1);

    for(int i = 0; i < gr.e; i++){
        int x = find(parent, gr.edges[i].src);
        int y = find(parent, gr.edges[i].dest);

        if (x == y)
            return 1;

        uni(parent, x, y);
    }
    return 0;
}

bool compareWeight(const Graph::Edge e1, const Graph::Edge e2) {
    return e1.weight < e2.weight;
}

