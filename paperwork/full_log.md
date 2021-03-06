**Week of 04/04/2021:**
This week, we met multiple times to work on our final project proposal as well as the team contract. 
We hashed out what we wanted to do for the project, as well as what algorithms we wanted to implement. 
In the end, we chose a dataset that keeps track of the “trust level” of bitcoin traders. We want to create a 
visual representation of our graph as well as possibly implementing the page rank algorithm to find the best user for the graph.

**Week of 04/11/2021:**
04/14/2021 - We discussed what we were going to accomplish for the rest of the week, mainly the next day. Decided we would 
implement a way for reading the CSV file into our git repository. We were planning on beginning the skeleton of our data structure, 
but after some discussion with our advisor we are leaning more towards a directed graph, which is the way our data is provided.

04/15/2021 - Decided to hold off until lecture to implement the graph.

**Week of 04/18/2021:**
04/18/2021 - Began implementation of graph. Decided what functions to implement and the specifics behind the graph, including the 
vertex and edge structures. Also began working on our File Reader object, which is what we are going to use to read the data 
from the dataset into our structure. We will most likely implement the basics of our structure before completing the
file reader.

**Week of 04/25/2021:**
04/25/2021 - This week our primary focus was parsing our dataset and implementing the primary objects and method for our graph. We decided on parsing the CSV file with a fstream object and storing our data into a adjacency matrix. We implemented a struct for both a vertex and an edge with respective private data members and documented helper methods to assist data parsing process. Additionally we had our mdipoint meeting on the project on Friday, we are considering on changing primary struction of a two by two matrix to something that is more efficient as given by the instructor. Our goal for this week is to work on the make file, resolve merge conflict and write test cases for all our method implementations.

05/01/2021 - Finished work on Graph implementation and File reader. Decided to switch from implementing the PageRank algorithm to implementing Dijkstra's Algorithm due to time/complexity issues. We also began splitting up the work for the traversal and the two chosen algorithms. We have begun taking the advice that our TA gave us during the mid-point check-in and implementing it. 

**Week of 05/02/2021:**
05/04/2021 - Our main goal for this week was to begin and finish implementations of both Dijkstra's algorithm and Breadth First Search. With these implementations, it will be much easier to test our file reader and Graph objects. We also added more tests and will need to add more in order to test the other two algorithms being added. Once these two are complete we can get to work on our final tests, which are the visual representation algorithm, the presentation, and the readme file (which I hope isn't too difficult).

**Week of 05/09/2021:**
05/11/2021 - With most of our code complete, we just have to bug fix a couple things to make sure our algorithms are working properly with one another. We have no issues with our Graph object, file reader, BFS, and Dijkstra's algorithm, as these all work well together. The final thing is just touching up on our visual representation as we're having a few issues with that. We are also struggling with the Makefile as we are unable to get passed some linker errors, which is stopping us from running our test cases. Aside from this, we just have to finish up our read me and final presentation by tomorrow night and we should be good to go.
