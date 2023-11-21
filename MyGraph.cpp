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

// Breadth-First Search
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

        // Enqueue los vertices adyacentes al vertice dequeueado que no han sido visitados
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


// Función para verificar si el grafo es un árbol
bool MyGraph::isTree() {
    //Para ser un árbol:
    // No debe de tener ciclos
    // para cualquier par de nodos existe una trayectoria simple que los conecta,

    // numero de nodos del grafo
    int numOfnodes = matriz.size();

    // Vector de bools para marcar nodos visitados
    std::vector<bool> visited(numOfnodes, false);

    // Contador de nodos visitados
    int visited_nodes = 0;

    // iterar sobre cada nodo en el grafo
    for (int i = 0; i < numOfnodes; ++i)
    {
        // Si el nodo no ha sido visitado
        if (!visited[i])
        {
            // Marcar el nodo como visitado
            visited[i] = true;
            // Incrementar el contador de nodos visitados
            ++visited_nodes;

            // Iterar sobre las conexiones del nodo
            for (int j = 0; j < numOfnodes; ++j)
            {
                // Si hay una conexión desde el nodo i al nodo j
                if (matriz[i][j] == 1)
                {
                    // Si el nodo j ya ha sido visitado, hay un ciclo: no es un árbol
                    if (visited[j])
                    {
                        return false;
                    }
                }
            }
        }
    }

    // Cumple con las propiedades de un árbol
    return visited_nodes == numOfnodes;
}


//topological sort
void MyGraph::topologicalSort()
{
    int numNodos = matriz.size();

    // Calcular el grado de entrada para cada nodo
    std::vector<int> inDegree(numNodos, 0);

    for (int i = 0; i < numNodos; ++i)
    {
        for (int j = 0; j < numNodos; ++j)
        {
            if (matriz[i][j] == 1)
            {
                inDegree[j]++;
            }
        }
    }

    //  Inicializar queue y agregar nodos con grado de entrada cero
    std::queue<int> q;

    for (int i = 0; i < numNodos; ++i)
    {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Paso 3: Realizar el ordenamiento topológico
    std::vector<int> topOrder;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topOrder.push_back(u);

        // Reducir el grado de entrada de los nodos adyacentes
        for (int v = 0; v < numNodos; ++v)
        {
            if (matriz[u][v] == 1)
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    // Verificar si hay un ciclo (grafo no dirigido acíclico)
    if (topOrder.size() != numNodos)
    {
        std::cout << "El grafo contiene un ciclo, no se puede realizar un orden topológico." << std::endl;
    }
    else
    {
        // Imprimir el orden topológico
        for (int node : topOrder)
        {
            std::cout << node << ",";
        }
        std::cout << std::endl;
    }
}

//bipartite graph
bool MyGraph::bipartiteGraph()
{
    int numNodos = matriz.size();
    std::vector<int> coloredVector(numNodos, 0);  // Vector que almacena los colores de los nodos (0: sin colorear, 1 y 2: dos colores posibles)
    std::queue<int> ColoredQ;

    for (int i = 0; i < numNodos; ++i)
    {
        if (coloredVector[i] == 0)
        {
            coloredVector[i] = 1;  // Asignar 1 al nodo actual si aún no ha sido coloreado
            ColoredQ.push(i);  // Agregar el nodo a Q de nodos coloreados
        }

        //Mientras el Q no esté vacio
        while (!ColoredQ.empty())
        {
            // Hacer BFS usando el Q
            int front = ColoredQ.front();
            ColoredQ.pop();

            // Obtener color de nodo actual (front of Queue)
            int colorActual = coloredVector[front];

            // Se define el color contrario al actual para asignar a los nodos adyacentes.
            int colorContrario = (colorActual == 1) ? 2 : 1;

            //Iterar nodos adyacentes a front
            for (int j = 0; j < matriz[front].size(); ++j)
            {
                if (matriz[front][j] == 1)
                {
                    if (coloredVector[j] == 0)
                    {
                        // Si el nodo adyacente no ha sido coloreado, se le asigna el color contrario al nodo actual y se agrega a la cola.
                        coloredVector[j] = colorContrario;  // Asignar el coloredVector opuesto al nodo adyacente
                        ColoredQ.push(j);  // Agregar el nodo adyacente al conjunto de nodos ColoredQ y pendientes de procesar
                    } else if (coloredVector[j] == colorActual)
                    {
                        //Si el nodo adyacente ya tiene color y es igual al color del nodo actual, hay un conflicto, y la función devuelve false.

                        return false;
                    }
                }
            }
        }
    }
    return true;  // Si no hay conflictos de color, el grafo es bipartito
}








