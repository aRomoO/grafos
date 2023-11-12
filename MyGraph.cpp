#include "MyGraph.h"
#include <queue>
#include <iostream>


MyGraph::MyGraph(std::vector<std::vector<int>>& matriz)
{
    loadGraph(matriz);
}

void MyGraph::loadGraph(std::vector<std::vector<int>>& matriz)
{
    //Checar que la matriz no esté vacía
    if (matriz.empty())
    {
        throw std::invalid_argument("No se puede cargar una matriz vacia");
    }

    //checar que la matríz sea cuadrada
    if (matriz.size() != matriz[0].size())
    {
        throw  std::invalid_argument("La matriz no es cuadrada");
    }

    this->matriz = matriz;
}

// Depth-First Search
void MyGraph::DFS(int nodo)
{
    // vector de bools para marcar los nodos visitados
    std::vector<bool> visited(matriz.size(), false);
    // Llamar DFS recursivo
    DFS(nodo, visited);
}

// Helper function para DFS recursivo
void MyGraph::DFS(int nodo, std::vector<bool>& visited)
{
    // Marcar el nodo como visitado e imprimirlo
    visited[nodo] = true;
    std::cout << nodo << ",";

    // Hacer lo mismo para todos los adyacentes
    for (int i = 0; i < matriz[nodo].size(); ++i)
    {
        if (!visited[i] && matriz[nodo][i] != 0)
        {
            DFS(i, visited);
        }
    }
}

// Breadth-First Search traversal starting from a given node
void MyGraph::BFS(int nodo)
{
    // Vector de bools para marcar nodos visitados
    std::vector<bool> visited(matriz.size(), false);
    // Crear un queue
    std::queue<int> q;

    // Marcar el nodo actual como visitado y enqueuearlo
    visited[nodo] = true;
    q.push(nodo);

    // BFS loop
    while (!q.empty()) {
        // Dequeue el vertice e imprimirlo
        nodo = q.front();
        std::cout << nodo << ",";
        q.pop();

        // Enqueue los vvertices adyacentes al vertice dequeueado que no han sido visitados
        for (int i = 0; i < matriz[nodo].size(); ++i)
        {
            if (!visited[i] && matriz[nodo][i] != 0)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
