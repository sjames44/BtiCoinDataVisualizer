#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../Graph.h"

Graph createBasicGraph() {
    Graph G(6);
    G.insertVertex(1);
    G.insertVertex(2);
    G.insertVertex(3);
    G.insertVertex(4);
    G.insertVertex(5);
    G.insertVertex(6);
    G.insertEdge(1, 2, 2);
    G.insertEdge(1, 3, 4);
    G.insertEdge(2, 3, 1);
    G.insertEdge(2, 4, 7);
    G.insertEdge(3, 5, 3);
    G.insertEdge(5, 4, 2);
    G.insertEdge(4, 6, 1);
    G.insertEdge(5, 6, 5);
    return G;
}


TEST_CASE("Basic dijkstra test", "[dijkstra]") {   
    Graph G = createBasicGraph();
    //G.dijkstrasAlgo(0);
    std::vector<int> solution{0, 2, 3, 8, 6, 9};
    REQUIRE(G.dijkstrasAlgo(0) == solution);
}		