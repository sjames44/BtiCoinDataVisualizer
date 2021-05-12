<<<<<<< HEAD
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

    


=======
#include <iostream>
#include "Graph.h"

/*int main (int argc, const char * argv[]) {
    std::cout << "Hello World";
}*/

int main(){
    Graph G(15);
    G.insertVertex(1);
    G.insertVertex(9);
    G.insertVertex(14);
    G.insertVertex(4);
    G.insertVertex(2);
    G.insertVertex(5);
    G.insertEdge(1,9,5);
    G.insertEdge(1,14,21);
    G.insertEdge(9,4,9);
    G.insertEdge(4,2,2);
    G.insertEdge(9,5,2);
    G.BFS(1);
>>>>>>> 60d3e7667a9b414284364448e33dfff9ab063bb7
}