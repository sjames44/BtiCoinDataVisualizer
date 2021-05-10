#include "Graph.h"
#include <vector>
#include <queue>

Graph::Graph(){

}

Graph::Graph(int size) {
    for (int row = 0; row < size; row++) {
        std::vector<Edge*> newRow(size, NULL);
        matrix.push_back(newRow);
    }
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
    return matrix[a->id -1][b->id -1];
}

bool Graph::areAdjacent(Vertex* a, Vertex* b){
    if(matrix[a->id -1][b->id -1]->rating != 0)
        return true;
    else return false;
}

void Graph::BFS(int startid){
    std::vector<bool> visited(vertices.size(),0);
    std::vector<int> ids;
    ids.push_back(startid);
    visited[startid -1] = 1;
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

void Graph::dijkstrasAlgo(Vertex* start) {
    int s = getIndex(*start); //Get index of start

    std::vector<int> distances;
    std::vector<int> visited;
    distances.resize(vertices.size(), INT_MAX); //Vector that stores distances for each vertex
    
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > q; //Priority queue that is min-heap <weight, predecessor>

    //Add start to q and add dist
    std::pair<int, int> star = std::make_pair(0, s);
    distances[s] = 0;

    while (!q.empty()) {
        //Get the vertex with the current minimum distance
        int u = q.top().second; //The second value is the vertex
        
    }
}

int Graph::getIndex(Vertex& v) {
    for (int index = 0; index < vertices.size(); index++) {
        if (vertices[index]->id == v.id) {
            return index;
        }
    }
    //If vertex wasn't found in vector
    return -1;
}