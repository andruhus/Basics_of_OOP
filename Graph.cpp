//
// Created by aaade on 14.09.2020.
//

#include "Graph.h"
#include <iostream>


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
        while(i < list_of_connectivity.length)
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
        for(int j = 0;j<list_of_connectivity.length;j++)
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


template <typename Data>
void Graph<Data>::RemoveEdge(int i_vetrex, int j_vertex)
{
    // checking if the input is correct
    int len = list_of_values.length;
    if(i_vetrex >= len || j_vertex >= len)
    {
        return;
    }

    // checking if the edge exists
    if(!matrix[i_vetrex][j_vertex])
    {
        return;
    }


    // now we can proseed
    matrix[i_vetrex][j_vertex] = false;



    int i = 0;
    while(i < list_of_connectivity.length)
    {
        if (list_of_connectivity[i][0] == i_vetrex && list_of_connectivity[i][1] == j_vertex)
        {
            list_of_connectivity.erase(i);
        }
        else
        {
            i++;
        }
    }


}

template <typename Data>
bool Graph<Data>::IsConnected()
{
    int len = list_of_values.length;
    bool *vis = new bool[len];
    //for all vertex u as start point, check whether all nodes are visible or not
    for(int u; u < len; u++) {
        for(int i = 0; i<len; i++)
            vis[i] = false; //initialize as no node is visited
        traverse(u, vis);
        for(int i = 0; i<len; i++) {
            if(!vis[i]) //if there is a node, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}


template <typename Data>
void Graph<Data>::traverse(int u, bool *visited)
{
    int len = list_of_values.length;
    visited[u] = true; //mark v as visited
    for(int v = 0; v<len; v++) {
        if(matrix[u][v]) {
            if(!visited[v])
                traverse(v, visited);
        }
    }
}

template <typename Data>
int Graph<Data>::Dist_Between_Vertexes(int i_vertex, int j_vertex) {
    // The recurrent approach is used
    int len = list_of_values.length;
    bool visited[len];
    for (int i = 0; i < len; ++i) {
        visited[i] = false;
    }
    return calc_Res(i_vertex,j_vertex,visited,len);

}

template <typename Data>
int Graph<Data>::calc_Res(int i, int j, bool *visited, int len) {
    // We have to mark this vertex
    visited[i] = true;
    // if we the vertices coincide the distance is zero
    if(i == j)
        return 0;
    // Now we define the minimal distance
    int min_res = -1;
    // Now we are interrating every edge
    for(int ind = 0;ind < list_of_connectivity.length;ind++)
    {
        // The next vertex should be connected to the i-th vertex and not be visited
        if(list_of_connectivity[ind][0] == i && !visited[list_of_connectivity[ind][1]])
        {
            // Now we calculate the distance between the next vertex and our destination
            int temp_res = calc_Res(list_of_connectivity[ind][1],j,visited,len);
            // Analysing the result
            if(temp_res != None)
            {
                // if the result is lower than the minimal result then we redefine it
                if(min_res == -1 || temp_res < min_res)
                    min_res = temp_res;
            }
        }
    }
    // if the minimal result doesn't exist we return None
    if (min_res == -1)
        return None;
    else
        return min_res + 1;
}