/*
* insertVertex, insertEdge
* incidentEdges, areAdjacent
* 
*/

#pragma once

#include <vector>
#include <iostream>


class Graph {
    private:
        struct Vertex {
            //Integer representing the user's ID
            int id;
            int average;
            Vertex(int id) : id(id) {}
        };

        struct Edge {

            int rating;

            Edge(int rating) rating(rating) {}
        };
        std::vector<Vertex*> vertices;
        std::vector<std::vector<Edge*>> matrix; //First dimension is parent vertex, second is child


    public:
        void insertVertex(int id);

        void insertEdge(Vertex first, Vertex second, int weight);
        
        std::vector<Edge> incidentEdges(Vertex v);

        bool areAdjacent(Vertex a, Vertex b);

        Edge getEdge(Vertex a, Vertex b);        

        double calculateAverage(Vertex* a);
};