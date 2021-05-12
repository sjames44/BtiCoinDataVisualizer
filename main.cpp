
#include <iostream>
#include <fstream>
#include "Graph.h"
#include "cs225/PNG.h"

/*int main (int argc, const char * argv[]) {
    std::cout << "Hello World" << std::endl;
}*/

int main(){
    std::ifstream file;
    file.open("tests/realtest.txt");
    std::cout << "Reading data set..." << std::endl;
    Graph graph(file, 7604);
    std::cout << "Drawing visualization..." << std::endl;
    cs225::PNG* g = graph.drawGraph();
    std::cout << "Saving visualization to 'out.png'" << std::endl;
    g->writeToFile("out.png");
    
   /*
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
    */

}