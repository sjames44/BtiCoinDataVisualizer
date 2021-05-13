#include <fstream>
#include <iostream>
#include "Graph.h"
#include <vector>
#include <queue>
#include <stdlib.h> //Used for rand
#include <time.h>

Graph::Graph(int size) {
    idSize = size;
    for (int row = 0; row < size; row++) {
        std::vector<int> newRow(size, 11);
        matrix.push_back(newRow);
        numChildren.push_back(0);
    }
}

Graph::Graph(std::ifstream &in, int size) {
    idSize = size;
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
}

void Graph::insertEdge(Vertex first, Vertex second, int weight) {
    int firstId = first.id - 1; //Indexes are offset by 1
    int secondId = second.id - 1;

    matrix[firstId][secondId] = weight;
}

double Graph::calculateAverage(Vertex* a) {
    double sum = 0;
    double total = 0;

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

std::vector<int> Graph::BFS(int startid){
    std::vector<bool> visited(vertices.size(),0);
    std::vector<Vertex*> ids;
    std::vector<int> traversed;
    ids.push_back(getVertex(startid));
    visited[startid -1] = 1;
    while(!ids.empty()) {
        Vertex* curr = ids[0];
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
    distances.resize(idSize, INT_MAX); //Vector that stores distances for each vertex
    visited.resize(idSize, false);

    if (s < 0 || s > idSize - 1) {
        return distances;
    }
    
    //Implementing min heap priority queue to make it like lecture
    //https://www.studytonight.com/cpp-programs/cpp-implementing-min-heap-using-priority-queue-program
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > q; //Priority queue that is min-heap <weight, index>

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

    return distances;
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

cs225::PNG* Graph::drawGraph() {
    int width = 5000;
    int height = 5000;
    cs225::PNG* graphImage = new cs225::PNG(width, height);
    setupCoords(width, height);
    setUpAverages();

    for (size_t i = 0; i < coords.size(); i++) {
        
        //Set color
        double color = 130;
        if (vertices[i]->average == 0)
            color = 240;
        else{
            color = (1 - (vertices[i]->average / 21)) * color;
        }

        coords[i][3] = color; //Set the color of this vertex

        //Set radius
        double radius = (getChildren(i) + 1);
        //Bounds detection
        if (coords[i][0] - radius < 0) {
            coords[i][0] += (coords[i][0] - radius);
        } else if (coords[i][0] + radius > width) {
            coords[i][0] -= (coords[i][0] - radius);
        }
        if (coords[i][1] - radius < 0) {
            coords[i][1] += (coords[i][1] - radius); //Makes it so they don't go over the edge
        }

        coords[i][2] = radius;
    }


    //Go through and draw the 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x ++) {
            for (size_t i = 0; i < coords.size(); i++) {
                
                if ( (x - coords[i][0]) * (x - coords[i][0]) + (y - coords[i][1]) * (y - coords[i][1]) <= coords[i][2] * coords[i][2]) {
                    //Check if we're within the radius of a vertex
                    cs225::HSLAPixel& pixel = graphImage->getPixel(x, y);
                    pixel.h = coords[i][3];
                    //pixel.h = 0;
                    pixel.s = 1;
                    pixel.l = 0.5;
                }
            }
        }
    }


    return graphImage;
}

void Graph::setupCoords(int width, int height) {
    srand(time(NULL)); //Set seed for random
    
    for (size_t i = 0; i < vertices.size(); i++) {
        double x = (double) (rand() % width);
        double y = (double) (rand() % height);
        coords.push_back({x, y, 0, 0});
    }
}

void Graph::setUpAverages() {
    for (size_t vertex = 0; vertex < vertices.size(); vertex++) {
        int index = vertices[vertex]->id - 1;
        double aver = 0;
        int total = 0;
        for (size_t child = 0; child < matrix[index].size(); child++) {
            if (matrix[index][child] > 0 && matrix[index][child] != 11 && matrix[index][child] < 22) {
                aver += matrix[index][child];
                total++;
            }
        }
        if(total == 0)
            vertices[vertex]->average = 0;
        else
            vertices[vertex]->average = (aver/total);
    }
}

int Graph::getChildren(int index) {
    int result = 0;

    int in = vertices[index]->id - 1;
    for (size_t i = 0; i < matrix[in].size(); i++) {
        if (matrix[in][i] != 11) {
            result++;
        }
    }
    return result;
}
