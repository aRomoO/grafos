//
// Created by fredi on 10/11/23.
//

#ifndef GRAFOS_MYGRAPH_H
#define GRAFOS_MYGRAPH_H
#include "vector"

class MyGraph {
public:
    std::vector<std::vector<int>> matriz;

public:
    MyGraph(std::vector<std::vector<int>>& matriz); //O(1)
    void loadGraph(std::vector<std::vector<int>>& matriz); //O(1)
    void DFS(int nodo);
    void DFS(int nodo, std::vector<bool>& visited); //O(n) | O(V+E) V: Vertices , E: Nodos
                                                    // Helper function para DFS recursivo
    void BFS(int nodo); //O(n)  | O(V+E) V: Vertices , E: Nodos

    bool isTree(); //O(n)  | O(V+E) V: Vertices , E: Nodos
    void topologicalSort(); //O(n)  | O(V+E) V: Vertices , E: Nodos
    bool bipartiteGraph(); //O(n)  | O(V+E) V: Vertices , E: Nodos

};


#endif //GRAFOS_MYGRAPH_H
