#include <iostream>
#include "Graph.h"
#include "cs225/PNG.h"

/*int main (int argc, const char * argv[]) {
    std::cout << "Hello World";
}*/

int main(){
    Graph G(15);
    G.insertVertex(1);
    G.insertVertex(9);
    G.insertVertex(14);
    G.insertVertex(4);
    G.insertVertex(2);
    G.insertVertex(5);
    G.insertEdge(1,9,5);
    G.insertEdge(1,14,21);
    G.insertEdge(9,4,9);
    G.insertEdge(4,2,2);
    G.insertEdge(9,5,2);
    cs225::PNG* g = G.drawGraph();
    g->writeToFile("out.png");
    // G.insertVertex(1);
    // G.insertVertex(2);
    // G.insertVertex(3);
    // G.insertVertex(4);
    // G.insertVertex(5);
    // G.insertVertex(6);

    // G.insertEdge(1, 2, 2);
    // G.insertEdge(1, 3, 4);
    // G.insertEdge(2, 3, 1);
    // G.insertEdge(2, 4, 7);
    // G.insertEdge(3, 5, 3);
    // G.insertEdge(5, 4, 2);
    // G.insertEdge(4, 6, 1);
    // G.insertEdge(5, 6, 5);

    // cs225::PNG* g = G.drawGraph();
    // g->writeToFile("out.png");

    //G.dijkstrasAlgo(0);
}