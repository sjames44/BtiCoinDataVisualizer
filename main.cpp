// #include <iostream>
#include "FileReader.h"
#include "Graph.h"

int main (int argc, const char * argv[]) {

    Graph graph(7604);

    std::ifstream in; 
    in.open(argv[1]);
  
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

        //graph.insertEdge(rater, ratee, rating);
        
        std::cout << "rater: " << rater << " ratee: " << ratee << " rating: " << rating << std::endl;
    }

    


}