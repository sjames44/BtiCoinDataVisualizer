/*
* insertVertex, insertEdge
* incidentEdges, areAdjacent
* 
*/

#pragma once

#include <vector>
#include <iostream>
#include <fstream>


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

            Edge(int rating): rating(rating) {}
        };
        std::vector<Vertex*> vertices;
        std::vector<std::vector<Edge*> > matrix; //First dimension is parent vertex, second is child

    public:

        Graph(std::ifstream &in); 

        Graph(int size);

        /**
        * Method that inserts a new vertex (User) into the graph
        * @param id - The id of the new user
        */ 
        void insertVertex(int id);

        /**
        * Method that inserts a new edge that connects two vertices
        * @param first - The first vertex to connect, this will be the parent
        * @param second - The second vertex to connect, this will be the child
        * @param weight - The weight associated with the edge
        */
        void insertEdge(Vertex first, Vertex second, int weight);

         /**
        * Method that inserts a new edge that connects two vertices
        * @param first - The first vertex to connect, this will be the parent
        * @param second - The second vertex to connect, this will be the child
        * @param weight - The weight associated with the edge
        */
        void insertEdge(int first, int second, int weight);

        /**
        * Method that will get a list of the incident edges of a specific vertex
        * @param v - The vertex we want to find the incident edges of 
        * @return a list of edges incident to Vertex v
        */ 
        std::vector<Edge> incidentEdges(Vertex v);

        /**
        * Method that will determine if two edges are connected or not
        * @param a - The first vertex
        * @param b - The second vertex
        * @return true if the two edges are adjacent, false otherwise
        */
        bool areAdjacent(Vertex a, Vertex b);

        /**
        * A simple method that will return the edge that connects two vertices
        * @param a - The first vertex
        * @param b - The second vertex
        * @return a pointer to the edge that connects the two vertices
        */
        Edge* getEdge(Vertex a, Vertex b);        

        /**
        * Method that will calculate the average rating of a specific user
        * @param a - The user we want to calculate the average for
        * @return a double representing the average rating for the user
        */
        double calculateAverage(Vertex *a);
};