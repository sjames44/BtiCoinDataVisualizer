

CS 225 Data Structures

Project Proposal (dpachu2-asebas6-sjames34)

\1. **Leading Question:** We are looking at the Bitcoin Alpha trust weighted signed

network data set and looking to implement a general search tool to be able to

parse through all the members who were rated, who rated them, their rating, and

when it happened. We are looking to rank the members based on their

Trustworthiness, which is a combination of their rating and how many ratings they

have.

\2. **Dataset Acquisition:** We are acquiring our dataset from the Stanford Large

Network Dataset Collection, where our dataset (soc-sign-bitcoin-alpha) is listed

under Social networks. The dataset can be downloaded directly from the site,

where it is downloaded as a csv file. The Bitcoin Alpha trust weighted signed

network is a dataset containing a list of ratings, separated by the source and the

target of the rating. The data is separated into Source, Target, Rating, and Time.

Time in our case isn’t too necessary, but we are looking to sort the data with the

Target as the parent node and the Source as the children. The key or edge

weight of each child node would be the rating itself. In the case of error we

wouldn’t be able to correct them, so we would simply discard the data.

\3. **Graph Algorithms:** We will first be implementing a Breadth First Search

Traversal on the data set. We would store the data in a tree where each level

contains the ratings for the user corresponding to that level. A breadth first

search would allow us to gain insightful data on individual users. Along with that,

it would also be able to tell us if two separate nodes are connected in terms of

the data, or if we are looking at two unconnected nodes/reviewees. The first

algorithm we will implement is making a graphical output of the graph. We will

use the force-directed graph drawing algorithm in order to visually show users

along with their average rating. The nodes will represent that specific user's

average rating, where the size of the node is determined by the number of

ratings that user has received and the color, from shades of red to green, will

represent the average rating for that user. Additionally, we will implement the





PageRank algorithm. This algorithm will rank each of the users based on their

trustworthiness, allowing us to view the most trustworthy users along with visually

seeing them with the graph. The algorithm will take in a vector containing the

users, and outputs a list of those users ranked from most trustworthy to least.

**4. Timeline:**

● Data acquisition (04/09/2021)

● Data processing (04/16/2021)

● Graphic output of graph(force-directed graph drawing) (04/23/2021)

● PageRank (04/30/2021)

● BFS (05/07/2021)

● Final Project Deliverables (05/11/2021)

