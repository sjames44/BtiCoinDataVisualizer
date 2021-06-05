# CS 225 Staff Final Project
## Team Members: Dawid Pachura, Steven James, Anton Sebastian


### Data Visualization:
 - The goal of this project was to use the BitCoin Web of Trust dataset to answer specific questions we had. Specifically, we want to use this dataset to find          users with high ratings, which would be good trade partners.
 - Not only can we do this algorithmically and find potential users, we can also visualize this dataset and get a broad view of the entire thing
 - [Link to dataset](http://snap.stanford.edu/data/soc-sign-bitcoin-otc.html)
 
 ### Sample Visualization:
 



### Important info:
 - For the most part all of our main code resides in Graph.cpp/Graph.h. These two files contain the Graph class, which contains a struct Vertex, a vector
   of vertices, and an adjacency matrix. The Vertex struct holds an id and an average rating. A file reader, Dijkstra's Algorithm, a breadth first traversal,
   and our visualization algorithm. 
 
 
 ### Test cases:
 - There are provided test cases which can be found in tests.cpp, where test1.txt, test2.txt, and realtest.txt are inputs and realtestout.txt is an output. 


### Commands:
make - compiles all necessary files for the program to run  
make test - compiles all test cases and other files  
./finalproj - Create the visualization  
./test - runs all test cases

