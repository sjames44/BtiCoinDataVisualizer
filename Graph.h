#pragma once

#include <vector>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"


class Graph {
    private:
        struct Vertex {
            //Integer representing the user's ID
            int id;
            double average;
            Vertex(int id) : id(id) {}
        };

        //Class members
        std::vector<Vertex*> vertices;
        std::vector<std::vector<int>> matrix; //First dimension is parent vertex, second is child
        std::vector<int> numChildren;
        std::vector<std::vector<double>> coords; //x, y, radius, color
        int idSize;  //size

        //Helper functions:

        void setupCoords(int width, int height);

        void setUpAverages();

        int getChildren(int index);



    public:
        
         /**
        * Constructor that initializes a new graph but doesn't input anything
        * @param size - The size of the graph (largest id)
        */ 
        Graph(int size);

         /**
        * Constructor that initializes a new graph and reads in the data from file 
        * @param in, the name of the file to read from
        * @param size - The size of the graph (largest id)
        */ 
        Graph(std::ifstream &in, int size);

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
        * Method that will get a list of the incident edges of a specific vertex
        * @param v - The vertex we want to find the incident edges of 
        * @return a list of edges incident to Vertex v
        */ 
        std::vector<int> incidentEdges(Vertex* v);     

        /**
        * Method that will calculate the average rating of a specific user
        * @param a - The user we want to calculate the average for
        * @return a double representing the average rating for the user
        */
        double calculateAverage(Vertex* a);

        /**
        * Method that will do a breadth first search starting from an id
        * @param startid - The user we want to begin traversing from
        * @return a vector of integers representing the traversal
        */
        std::vector<int> BFS(int startid);

        /**
        * Method that implements Dijkstras Search Algorithm on the graph 
        * @param s - The index of the starting point in the graph (0 indexed based on the order nodes were pushed into the graph)
        * @return a vector of ints representing the shortest distance from the starting vertex to each of the vertices in the graph
        * - If a value is INT_MAX, that means the vertex does not exist in the graph or there is no path from the starting point to that vertex
        */
        std::vector<int> dijkstrasAlgo(int s);

        /**
        * Simple method that returns a vertex when given an id
        * @param idvert - The id of the vertex
        * @return a vector of integers representing the traversal
        */
        Vertex* getVertex(int idvert);

        /**
        * Method that will draw a graphical version of all of the vertices in the graph
        * Vertecies will be color coded based on their average rating (More green is good, more red is bad)
        * @return a PNG image of all of the vertices
        */
        cs225::PNG* drawGraph();
    
        /**
        * Getter used to return private member: matrix
        * Used primarily in testing suite
        * @return a 2D vector representing matrix
        */
        std::vector<std::vector<int>> getMatrix();

};
