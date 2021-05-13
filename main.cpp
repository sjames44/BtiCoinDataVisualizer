#include <iostream>
#include <fstream>
#include "Graph.h"
#include "cs225/PNG.h"


int main(){
    std::ifstream file;
    file.open("tests/realtest.txt");
    std::cout << "Reading data set..." << std::endl;
    Graph graph(file, 7604);
    graph.BFS(1);
    graph.dijkstrasAlgo(0);
    std::cout << "Drawing visualization..." << std::endl;
    cs225::PNG* g = graph.drawGraph();
    std::cout << "Saving visualization to 'out.png'" << std::endl;
    g->writeToFile("out.png");
}