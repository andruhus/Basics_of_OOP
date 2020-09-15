//
// Created by aaade on 14.09.2020.
//

#ifndef HOMEWORK_GRAPH_H
#define HOMEWORK_GRAPH_H
#include <vector>
using namespace std;

template <class Data>
class Graph {
private:
    vector<vector<bool>> matrix;     // matrix representation of the graph

    vector<vector<int>> list_of_connectivity;   // list representation of the graph

    vector<Data> list_of_values;     // all the value the vertex can contain

public:



    // Add/Remove vertix or edge
    void AddVertex();
    void AddEdge(int i_vetrex,int j_vertex);
    void RemoveVertex(int vertex);
    void RemoveEdge();


    // Checking if Graph is connected
    bool IsConnected();

    // Distance between two vertices
    int Dist_Between_Vertexes(int i_vertex, int j_vertex);

    // Other algorithms


    // Visualisation

};


#endif //HOMEWORK_GRAPH_H
