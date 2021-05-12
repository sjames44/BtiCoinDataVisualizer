#include <fstream>
#include <iostream>
#include "Graph.h"
#include <vector>
#include <queue>

Graph::Graph(){

}

Graph::Graph(int size) {
    //vertices.resize(size);
    for (int row = 0; row < size; row++) {
        std::vector<int> newRow(size, 11);
        matrix.push_back(newRow);
    }
}

Graph::Graph(std::ifstream &in, int size) {
    for (int row = 0; row < size; row++) {
        std::vector<int> newRow(size, 11);
        matrix.push_back(newRow);
    }

    std::string output;
    while(!in.eof()) {
        int rater, ratee, rating; 

        getline(in, output, ',');
        rater = stoi(output);

        getline(in, output, ',');
        ratee = stoi(output);

        getline(in, output, ',');
        rating = stoi(output);
        rating += 11;
        rating = 22 - rating;

        getline(in, output, '\n');

        insertVertex(ratee);
        insertVertex(rater);
        insertEdge(ratee, rater, rating);
    }
}

void Graph::insertVertex(int id) {
    
    for (size_t index = 0; index < vertices.size(); index++) {
        if(vertices[index]->id == id)
            return;
    }

    Vertex* newVertex = new Vertex(id);
    newVertex->average = 0; //Default value
    vertices.push_back(newVertex);
    //vertices[id -1] = newVertex;
    
}

void Graph::insertEdge(Vertex first, Vertex second, int weight) {
    int firstId = first.id - 1; //Indexes are offset by 1
    int secondId = second.id - 1;

    matrix[firstId][secondId] = weight;
}

double Graph::calculateAverage(Vertex* a) {
    int sum = 0;
    int total = 0;

    std::vector<int> incidents = incidentEdges(a);

    for (int edge : incidents) {
        total++;
        sum += edge;
    }

    return (sum / total);
}

std::vector<int> Graph::incidentEdges(Vertex* a) {
    std::vector<int> result;
    for(size_t i=0; i<vertices.size(); i++){
        int temp = matrix[a->id -1][vertices[i]->id -1];
        if(temp != 11)
            result.push_back(temp);
    }
    return result;
}


int Graph::getEdge(Vertex* a, Vertex* b){
    //Edge* temp = matrix[a->id][b->id];
    return matrix[a->id -1][b->id -1];
}

bool Graph::areAdjacent(Vertex* a, Vertex* b){
    if(matrix[a->id -1][b->id -1] != 0)
        return true;
    else return false;
}

std::vector<int> Graph::BFS(int startid){
    std::vector<bool> visited(vertices.size(),0);
    std::vector<Vertex*> ids;
    std::vector<int> traversed;
    ids.push_back(getVertex(startid));
    visited[startid -1] = 1;
    while(!ids.empty()) {
        Vertex* curr = ids[0];
        //std::cout << curr->id << std::endl;
        traversed.push_back(curr->id);
        ids.erase(ids.begin());
        for(size_t i=0; i<vertices.size(); i++){
            if(matrix[curr->id - 1][vertices[i]->id - 1] != 11 && !visited[i]){
                ids.push_back(vertices[i]);
                visited[i] = 1;
            }
        }
    }
    return traversed;
}

std::vector<int> Graph::dijkstrasAlgo(int s) {
    std::vector<int> distances;
    std::vector<bool> visited;
    distances.resize(vertices.size(), INT_MAX); //Vector that stores distances for each vertex
    visited.resize(vertices.size(), false);
    
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > q; //Priority queue that is min-heap <weight, index>
    //std::priority_queue<int, std::vector<int>

    //Add start to q and add dist
    std::pair<int, int> star = std::make_pair(0, s);
    q.push(star);
    distances[s] = 0;


    while (!q.empty()) {
        //Get the vertex with the current minimum distance
        int u = q.top().second; //The second value is the index of the vertex
        q.pop(); //Remove the vertex from the queue

        visited[u] = true; //Mark vertex as visited
        
        //Iterate through all the edges vertices adjacent to u and find the best one
        for (size_t v = 0; v < matrix[u].size(); v++) {
            if (!visited[v] && matrix[u][v] != 11 && distances[u] != INT_MAX) { //Check if its a vertex we want to check
                if (distances[u] + matrix[u][v] < distances[v]) { //If we've found a better distance, update
                    distances[v] = distances[u] + matrix[u][v];
                    q.push(std::make_pair(distances[v], v));
                }
            }
        }
    }

    printSolution(distances);
    return distances;
}

int Graph::getIndex(Vertex& v) {
    for (size_t index = 0; index < vertices.size(); index++) {
        if (vertices[index]->id == v.id) {
            return index;
        }
    }
    //If vertex wasn't found in vector
    return -1;
}

Graph::Vertex* Graph::getVertex(int idvert) {
    for (size_t index = 0; index < vertices.size(); index++) {
        if (vertices[index]->id == idvert) {
            return vertices[index];
        }
    }
    //If vertex wasn't found in vector
    return NULL;
}

void Graph::printSolution(std::vector<int> dist)
{
    std::cout << dist.size() << std::endl;
    for (size_t i = 0; i < dist.size(); i++) {
        std::cout << dist[i] << " ";
    }
    std::cout << std::endl;
}
