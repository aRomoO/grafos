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
    MyGraph(std::vector<std::vector<int>>& matriz); //O(1)
    void loadGraph(std::vector<std::vector<int>>& matriz); //O(1)
    void DFS(int nodo);
    void DFS(int nodo, std::vector<bool>& visited); //Helper function para DFS recursivo
    void BFS(int nodo);
};


#endif //GRAFOS_MYGRAPH_H
