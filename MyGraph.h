//
// Created by fredi on 10/11/23.
//

#ifndef GRAFOS_MYGRAPH_H
#define GRAFOS_MYGRAPH_H
#include "vector"

class MyGraph {
private:
    std::vector<std::vector<int>> matriz;

public:
    MyGraph(std::vector<std::vector<int>>& matriz);
    void loadGraph(std::vector<std::vector<int>>& matriz);
    void DFS(int nodo);
    void BFS(int nodo);
};


#endif //GRAFOS_MYGRAPH_H
