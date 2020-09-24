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
    {
        return;
    }

    // checking if the edge does not exist
    if(matrix[i_vetrex][j_vertex])
    {
        return;
    }


    // if everything is correct we can proseed

    // updating list of connectivity
    vector<int> new_edge (2,0);
    new_edge[0] = i_vetrex;
    new_edge[1] = j_vetrex;
    list_of_connectivity.push_back(new_edge);

    // updating the matrix
    matrix[i_vetrex][j_vertex] = true;

}


template <typename Data>
void Graph<Data>::RemoveVertex(int index_vertex) {

    int len = list_of_values.length;
    int temp_ind = index_vertex;
    // checking if the vertex is present 
    if (temp_ind >= len) {
        cout << "\nVertex not present!";
        return;
    }
    else {
        int i;

        // removing the vertex in matrix
        while (temp_ind < len) {
            // shifting the rows to left side 
            for (i = 0; i < len; ++i) {
                matrix[i][temp_ind] = matrix[i][temp_ind + 1];
            }

            // shifting the columns upwards 
            for (i = 0; i < len; ++i) {
                matrix[temp_ind][i] = matrix[temp_ind + 1][i];
            }
            temp_ind++;
        }




        // removing the vertex in connected list
        i = 0;
        while(i < len)
        {
            if(list_of_connectivity[i][0] == index_vertex || list_of_connectivity[i][1] == index_vertex)
            {
                list_of_connectivity.erase(i);
            }
            else
            {
                i++;
            }
        }
        // shifting remaining vertexes
        for(int j = 0;j<len;j++)
        {
            if(list_of_connectivity[j][0] > index_vertex)
                list_of_connectivity[j][0]--;
            if(list_of_connectivity[j][1] > index_vertex)
                list_of_connectivity[j][1]--;
        }


        // Deleting the data of the deleting vertex
        list_of_values.erase(index_vertex);



    }
}
