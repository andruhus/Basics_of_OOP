//
// Created by aaade on 14.09.2020.
//

#include "Graph.h"
#include <iostream>
using namespace std;

void Graph::AddVertex(Data value) {
    // Add the values
    list_of_values.push_back(value)

    // Modifying the matrix implementation
    for ( int i = 0; i < matrix.length; i++ )
        matrix[i].push_back(false);

    // the column which represents the newly added vertex
    vector<bool> last_row (matrix.length + 1,false);

    matrix.push_back(last_row);




}
