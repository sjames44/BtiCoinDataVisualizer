#include <iostream>
#include "Graph.h"

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
    G.BFS(1);
}