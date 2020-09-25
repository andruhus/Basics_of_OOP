//
// Created by aaade on 14.09.2020.
//

#ifndef HOMEWORK_GRAPH_H
#define HOMEWORK_GRAPH_H
#include <vector>
using namespace std;

template <typename Data>
class Graph {
private:

    vector<vector<bool>> matrix;     // matrix representation of the graph

    vector<vector<int>> list_of_connectivity;   // list representation of the graph

    vector<Data> list_of_values;     // all the value the vertex can contain


    // additional method used in IsConnected
    void traverse(int u, bool visited[]);


    // additional method used in Dist_Between_Vertexes
    int calc_Res(int i,int j,bool* visited,int len);

public:



    // Add/Remove vertix or edge
    void AddVertex(Data value);
    void AddEdge(int i_vetrex, int j_vertex);
    void RemoveVertex(int index_vertex);
    void RemoveEdge(int i_vetrex, int j_vertex);


    // Checking if Graph is connected
    bool IsConnected();

    // Distance between two vertices
    int Dist_Between_Vertexes(int i_vertex, int j_vertex);

    // Other algorithms
    bool CheckingIfHasEulerCycle();
    bool CheckingIfHasEulerCircut();

    // Visualisation

};


#endif //HOMEWORK_GRAPH_H
