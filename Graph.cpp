#include "Graph.h"


void Graph::insertVertex(int id) {
    Vertex* newVertex = new Vertex(id);
    newVertex->average = 0; //Default value
    vertices.push_back(newVertex);
}

void Graph::insertEdge(Vertex first, Vertex second, int weight) {
    int firstId = first.id - 1; //Indexes are offset by 1
    int secondId = second.id - 1;

    Edge* newEdge = new Edge(weight); 

    matrix[firstId][secondId] = newEdge;
}

double Graph::calculateAverage(Vertex* a) {
    int sum = 0;
    int total = 0;

    std::vector<Edge> incidents = incidentEdges(*a);

    for (Edge edge : incidents) {
        total++;
        sum += edge.rating;
    }

    return (sum / total);
}

std::vector<Graph::Edge> Graph::incidentEdges(Vertex a) {
    std::vector<Edge> result;
    for(int i=0; i<vertices.size(); i++){
        Edge* temp = matrix[vertices[i]->id][a->id];
        if(temp->weight != 0)
            result.push_back(temp);
    }
    return result;
}


Edge* getEdge(Vertex a, Vertex b){
    Edge* temp = matrix[a->id][b->id];
    return temp;
}

bool areAdjacent(Vertex a, Vertex b){
    if(matrix[a->id][b->id]->weight != 0)
        return true;
    else return false;
}