#include <string>
#include <vector>
#include <fstream>
#include <iostream>

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

Graph createBasicGraph2() {
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
    return G;
}

TEST_CASE("Basic dijkstra test", "[dijkstra]") {   
    Graph G = createBasicGraph();
    std::vector<int> solution{0, 2, 3, 8, 6, 9};
    REQUIRE(G.dijkstrasAlgo(0) == solution);
}

TEST_CASE("Basic dijkstra test where size is not equal to number of indices", "[dijkstra]") {
    Graph G = createBasicGraph2();
    std::vector<int> solution{0, 16, INT_MAX, 14, 7, INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 21, INT_MAX};
    REQUIRE(G.dijkstrasAlgo(0) == solution);
}

TEST_CASE("Test Invalid input Dijkstra", "[dijkstra]") {
    Graph G = createBasicGraph();
    std::vector<int> solution;
    REQUIRE(G.dijkstrasAlgo(10) == solution);
}

TEST_CASE("Test Invalid Negative Input", "[dijkstra]") {
    Graph G = createBasicGraph();
    std::vector<int> solution;
    REQUIRE(G.dijkstrasAlgo(-5) == solution);
}

TEST_CASE("Basic BFS test", "[BFS1]"){
    Graph G = createBasicGraph();
    std::vector<int> solution{1, 2, 3, 4, 5, 6};
    REQUIRE(G.BFS(1) == solution);
}

TEST_CASE("Basic BFS test with more complex graph", "[BFS1]"){
    Graph G = createBasicGraph2();
    std::vector<int> solution{1, 9, 14, 4, 5, 2};
    REQUIRE(G.BFS(1) == solution);
}

TEST_CASE("Invalid input BFS", "[BFS]") {
    Graph G = createBasicGraph();
    std::vector<int> solution;
    REQUIRE(G.BFS(-1000) == solution);
}

//More complicated BFS tests implicitly tested in file reader stuff

TEST_CASE("Basic file reader", "[FileRead1]"){
    std::ifstream file;
    file.open("tests/test1.txt");
    Graph graph(file,30);
    std::vector<int> solution{1, 25}; 
    std::vector<int> result = graph.BFS(1);
    REQUIRE(result == solution);
}

TEST_CASE("Basic file reader2", "[FileRead1]"){
    std::ifstream file;
    file.open("tests/test2.txt");
    Graph graph(file, 7604);
    std::vector<int> solution{1, 7188, 430, 3134, 3026, 3010, 804, 160, 95, 377, 888};
    std::vector<int> result = graph.BFS(1);
    REQUIRE(result == solution);
}

TEST_CASE("Extreme file reader", "[FileRead1]"){
    std::ifstream file;
    file.open("tests/realtest.txt");
    Graph graph(file, 7604);
    std::vector<int> result = graph.BFS(1);
    std::ofstream output;
    output.open("tests/realtestout.txt");
    for(size_t i=0; i<result.size(); i++){
        output << result[i] << std::endl;
    }
}

TEST_CASE("Get valid edges") {
     Graph g = createBasicGraph();
     std::vector<int> ans;
     ans.push_back(2);
     ans.push_back(4);
     REQUIRE(g.incidentEdges(g.getVertex(1)) == ans); 
}

TEST_CASE("Graph Constructor Size", "[constructor]") {
    Graph graph(10);
    REQUIRE(graph.getMatrix().size() == 10); 
}

TEST_CASE("Graph Constructor File Parsing Size", "[constructor]") {
    std::ifstream file;
    file.open("tests/realtest.txt");
    Graph graph(file, 7604);
    REQUIRE(graph.getMatrix().size() == 7604); 
}

TEST_CASE("Test blank visualization", "[visiualizer]") {
    Graph g(15);
    cs225::PNG expected(5000, 5000);
    REQUIRE(*g.drawGraph() == expected);
}