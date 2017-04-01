//
// Created by Jorge on 3/31/17.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
/*
 * a representation of a graph
 */

class Graph {
public:
    class Edge {
    public:
        Edge(int x, int y, int z) : src(x), dest(y), weight(z) {}
        int src,dest, weight;
        void printE(){
            std::cout << src << " to " << dest <<  " weight: " <<weight << std::endl;
        }
    };
    Graph(int x, int y) : v(x), e(y), edges() {
        //edges = (Graph::Edge *)malloc(y * sizeof(Edge));
    }
    int v,e; //vertices, edges
    std::vector<Graph::Edge> edges;
    void printGraph(){
        for(int i = 0; i < e; i++)
            edges[i].printE();
    }
private:
};


#endif //UNTITLED_GRAPH_H
