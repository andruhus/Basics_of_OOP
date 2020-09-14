//
// Created by aaade on 14.09.2020.
//

#ifndef HOMEWORK_GRAPH_H
#define HOMEWORK_GRAPH_H
#include <vector>

class Graph {
private:
    vector<vector<bool>> matrix;
    vector<vector<int>> list_of_connectivity;
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
