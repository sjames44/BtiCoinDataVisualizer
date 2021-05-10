#include "Graph.h"

Graph::Graph(){

}

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

    std::vector<Edge> incidents = incidentEdges(a);

    for (Edge edge : incidents) {
        total++;
        sum += edge.rating;
    }

    return (sum / total);
}

std::vector<Graph::Edge> Graph::incidentEdges(Vertex* a) {
    std::vector<Edge> result;
    for(size_t i=0; i<vertices.size(); i++){
        Edge temp = *matrix[a->id -1][vertices[i]->id -1];
        if(temp.rating != 11)
            result.push_back(temp);
    }
    return result;
}


Graph::Edge* Graph::getEdge(Vertex* a, Vertex* b){
    //Edge* temp = matrix[a->id][b->id];
    return matrix[a->id][b->id];
}

bool Graph::areAdjacent(Vertex* a, Vertex* b){
    if(matrix[a->id][b->id]->rating != 0)
        return true;
    else return false;
}

void Graph::BFS(int startid){
    std::vector<bool> visited(vertices.size(),0);
    std::vector<int> ids;
    ids.push_back(startid);
    visited[startid] = 1;
    int cur;
    while(!ids.empty()) {
        cur = ids[0];
        std::cout << cur << std::endl;
        ids.erase(ids.begin());

        for(size_t i=0; i<vertices.size(); i++){
            if(matrix[cur][i]->rating != 11 && !visited[i]){
                ids.push_back(i);
                visited[i] = 1;
            }
        }
    }
}