#include <iostream>
#include "MyGraph.h"

int main()
{
    // Define an adjacency matrix for a directed graph
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1}
    };

    // Create a MyGraph object with the given adjacency matrix
    MyGraph myGraph(adjacencyMatrix);

    std::cout << "Depth-First Search (DFS) starting from node 2:" << std::endl;
    myGraph.DFS(2);
    std::cout << std::endl;

    std::cout << "Breadth-First Search (BFS) starting from node 2:" << std::endl;
    myGraph.BFS(2);
    std::cout << std::endl;


    return 0;
}
