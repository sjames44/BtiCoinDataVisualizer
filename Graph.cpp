#include "Graph.h"


void Graph::insertVertex(int id) {
    Vertex* newVertex = new Vertex(id);
    newVertex->average = 0; //Default value
    vertices.push_back(newVertex);
}

void Graph::insertEdge(Vertex first, Vertex second, int weight) {
    int firstId = first.id - 1;
    int secondId = second.id - 1;

    Edge* newEdge = new Edge(weight); 

    matrix[firstId][secondId] = newEdge;
}

double Graph::calculateAverage(Vertex a) {
    int sum = 0;
    int total = 0;

    std::vector<Edge> incident = incidentEdges(a);

    for (Edge edge : incident) {
        total++;
        sum += edge.weight;
    }

    return (sum / total);
}