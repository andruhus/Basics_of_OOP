//
// Created by aaade on 14.09.2020.
//

#include "Graph.h"
#include <iostream>
using namespace std;

template <typename Data>
void Graph<Data>::AddVertex(Data value) {
    // Add the values
    list_of_values.push_back(value);

    // Modifying the matrix implementation
    for ( int i = 0; i < matrix.length; i++ )
        matrix[i].push_back(false);

    // the column which represents the newly added vertex
    vector<bool> last_row (matrix.length + 1,false);

    matrix.push_back(last_row);

    // connected list won't change




}


template <typename Data>
void Graph<Data>::AddEdge(int i_vetrex, int j_vertex)
{
    // checking if the input is correct
    int len = list_of_values.length;
    if(i_vetrex >= len || j_vertex >= len)
        return;

    // checking if the edge does not exist
    if(matrix[i_vetrex][j_vertex])
        return;

    // if everything is correct we can proseed

    // updating list of connectivity
    vector<int> new_edge (2,0);
    new_edge[0] = i_vetrex;
    new_edge[1] = j_vetrex;
    list_of_connectivity.push_back(new_edge);

    // updating the matrix
    matrix[i_vetrex][j_vertex] = true;

}


