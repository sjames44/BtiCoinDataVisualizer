#include "Graph.h"

 Graph::Graph(int size) {
   vertices.reserve(size);
   matrix.insert(matrix.begin(), size, std::vector<Edge*>(size, nullptr));
}

Graph::Graph(std::ifstream &in) {
    Graph graph(7604);
  
    std::string output;
    while(!in.eof()) {
        int rater, ratee, rating; 

        getline(in, output, ',');
        rater = stoi(output);

        getline(in, output, ',');
        ratee = stoi(output);

        getline(in, output, ',');
        rating = stoi(output);

        getline(in, output, '\n');

        insertEdge(rater, ratee, rating);
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

void Graph::insertEdge(int first, int second, int weight) {
    int firstId = first - 1; //Indexes are offset by 1
    int secondId = second - 1;

    Edge* newEdge = new Edge(weight); 

    matrix[firstId][secondId] = newEdge;
}

double Graph::calculateAverage(Vertex *a) {
    int sum = 0;
    int total = 0;

    std::vector<Edge*> incidents = incidentEdges(a);

    for (Edge* edge : incidents) {
        total++;
        sum += edge->rating;
    }

    return (sum / total);
}