#include "MyGraph.h"
#include <iostream>

int main() {
    // Crear una matriz de adyacencia para probar la clase MyGraph
    std::vector<std::vector<int>> matriz = {
            {0, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 1, 0},
            {0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0}
    };


    try {
        // Crear una instancia de MyGraph
        MyGraph grafo(matriz);

        // Probar funciones de la clase
        std::cout << "DFS traversal starting from node 0: ";
        grafo.DFS(0);
        std::cout << std::endl;

        std::cout << "BFS traversal starting from node 0: ";
        grafo.BFS(0);
        std::cout << std::endl;

        std::cout << "Is the graph a tree? " << (grafo.isTree() ? "Yes" : "No") << std::endl;

        std::cout << "Topological sort: ";
        grafo.topologicalSort();

        std::cout << "Is the graph bipartite? " << (grafo.bipartiteGraph() ? "Yes" : "No") << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
