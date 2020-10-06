//!
//! Created by aaade on 14.09.2020.
//!

#include "Graph.h"
#include <iostream>


template <typename Data>
void Graph<Data>::AddVertex(Data value) {
    //! Add the values
    list_of_values.push_back(value);

    //! Modifying the matrix implementation
    for ( int i = 0; i < matrix.size(); i++ )
        matrix[i].push_back(false);

    //! the column which represents the newly added vertex
    vector<bool> last_row (matrix.size() + 1,false);

    matrix.push_back(last_row);

    //! connected list won't change




}


template <typename Data>
void Graph<Data>::AddEdge(int i_vertex, int j_vertex)
{
    //! checking if the input is correct
    int len = list_of_values.size();
    if(i_vertex >= len || j_vertex >= len)
    {
        return;
    }

    //! checking if the edge does not exist
    if(matrix[i_vertex][j_vertex])
    {
        return;
    }


    //! if everything is correct we can proseed

    //! updating list of connectivity
    vector<int> new_edge (2,0);
    new_edge[0] = i_vertex;
    new_edge[1] = j_vertex;
    list_of_connectivity.push_back(new_edge);

    //! updating the matrix
    matrix[i_vertex][j_vertex] = true;
    matrix[j_vertex][i_vertex] = true;

}


template <typename Data>
void Graph<Data>::RemoveVertex(int index_vertex) {

    int len = list_of_values.size();
    int temp_ind = index_vertex;
    //! checking if the vertex is present
    if (temp_ind >= len) {
        cout << "\nVertex not present!";
        return;
    }
    else {
        int i;

        //! removing the vertex in matrix
        while (temp_ind < len - 1) {
            //! shifting the rows to left side
            for (i = 0; i < len; ++i) {
                matrix[i][temp_ind] = matrix[i][temp_ind + 1];
            }

            //! shifting the columns upwards
            for (i = 0; i < len; ++i) {
                matrix[temp_ind][i] = matrix[temp_ind + 1][i];
            }
            temp_ind++;
        }
        //! now we have to get rid of unnecessary column and row
        for (int j = 0; j < matrix.size(); ++j) {
            matrix[j].pop_back();
        }
        matrix.pop_back();




        //! removing the vertex in connected list
        i = 0;
        while(i < list_of_connectivity.size())
        {
            if(list_of_connectivity[i][0] == index_vertex || list_of_connectivity[i][1] == index_vertex)
            {
                list_of_connectivity.erase(list_of_connectivity.begin() + i);
            }
            else
            {
                i++;
            }
        }
        //! shifting remaining vertexes
        for(int j = 0;j<list_of_connectivity.size();j++)
        {
            if(list_of_connectivity[j][0] > index_vertex)
                list_of_connectivity[j][0]--;
            if(list_of_connectivity[j][1] > index_vertex)
                list_of_connectivity[j][1]--;
        }


        //! Deleting the data of the deleting vertex
        list_of_values.erase(list_of_values.begin() + index_vertex);



    }
}


template <typename Data>
void Graph<Data>::RemoveEdge(int i_vertex, int j_vertex)
{
    //! checking if the input is correct
    int len = list_of_values.size();
    if(i_vertex >= len || j_vertex >= len)
    {
        return;
    }
    if(i_vertex == j_vertex)
    {
        return;
    }
    //! checking if the edge exists
    if(!matrix[i_vertex][j_vertex])
    {
        return;
    }


    //! now we can proseed
    matrix[i_vertex][j_vertex] = false;
    matrix[j_vertex][i_vertex] = false;


    int i = 0;
    while(i < list_of_connectivity.size())
    {
        if (list_of_connectivity[i][0] == i_vertex && list_of_connectivity[i][1] == j_vertex)
        {
            list_of_connectivity.erase(list_of_connectivity.begin() + i);
        }
        else if (list_of_connectivity[i][1] == i_vertex && list_of_connectivity[i][0] == j_vertex)
        {
            list_of_connectivity.erase(list_of_connectivity.begin() + i);
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
    int len = list_of_values.size();
    if(len == 0 || len == 1)
        return false;
    bool *vis = new bool[len];
    //!for all vertex u as start point, check whether all nodes are visible or not
    for(int u = 0; u < len; u++) {
        for(int i = 0; i<len; i++)
            vis[i] = false; //!initialize as no node is visited
        traverse(u, vis);
        for(int i = 0; i<len; i++) {
            if(!vis[i]) //!if there is a node, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}


template <typename Data>
void Graph<Data>::traverse(int u, bool *visited)
{
    int len = list_of_values.size();
    visited[u] = true; //!mark v as visited
    for(int v = 0; v<len; v++) {
        if(matrix[u][v]) {
            if(!visited[v])
                traverse(v, visited);
        }
    }
}

template <typename Data>
int Graph<Data>::Dist_Between_Vertexes(int i_vertex, int j_vertex) {
    //! The recurrent approach is used
    int len = list_of_values.size();
    bool* visited = new bool[len];
    for (int i = 0; i < len; ++i) {
        visited[i] = false;
    }
    return calc_Res(i_vertex,j_vertex,visited,len);

}

template <typename Data>
int Graph<Data>::calc_Res(int i, int j, bool *visited, int len) {
    //! We have to mark this vertex
    visited[i] = true;
    //! if we the vertices coincide the distance is zero
    if(i == j)
        return 0;
    //! Now we define the minimal distance
    int min_res = -1;
    //! Now we are interrating every edge
    for(int ind = 0;ind < list_of_connectivity.size();ind++)
    {
        //! The next vertex should be connected to the i-th vertex and not be visited
        if((list_of_connectivity[ind][0] == i && !visited[list_of_connectivity[ind][1]]) || (list_of_connectivity[ind][1] == i && !visited[list_of_connectivity[ind][0]]))
        {
            //! Now we calculate the distance between the next vertex and our destination
            int temp_res = calc_Res(list_of_connectivity[ind][1],j,visited,len);
            //! Analysing the result
            if(temp_res != -1)
            {
                //! if the result is lower than the minimal result then we redefine it
                if(min_res == -1 || temp_res < min_res)
                    min_res = temp_res;
            }
        }
    }
    //! if the minimal result doesn't exist we return None
    if (min_res == -1)
        return -1;
    else
        return min_res + 1;
}

template <typename Data>
bool Graph<Data>::CheckingIfHasEulerCycle() {
    //! I know some theorems about Euler cycle

    //! First theorem is if every vertex of the connected graph has even power,
    //! the graph has Euler's cycle

    //! the graph has to be connected
    if(!IsConnected())
        return false;


    //! then we check every power in the graph
    for (int ind = 0; ind < list_of_values.size(); ++ind) {
        int power = 0;
        for (int i = 0; i < list_of_values.size(); ++i) {
            power += matrix[ind][i];
        }

        if(power %2 == 1)
            return false;

    }

    return true;
}


template <typename Data>
bool Graph<Data>::CheckingIfHasEulerCircuit() {


    //! Second theorem is if only two vertex of the connected graph has odd power,
    //! the graph has Euler's circut

    //! the graph has to be connected
    if(!IsConnected())
        return false;


    //! then we check every power in the graph
    int count = 0; //! it counts the number of odd power verteces
    for (int ind = 0; ind < list_of_values.size(); ++ind) {
        int power = 0;
        for (int i = 0; i < list_of_values.size(); ++i) {
            power += matrix[ind][i];
        }

        if(power %2 == 1)
            count++;

    }
    if (count == 2)
        return true;
    else
        return false;
}
template <typename Data>
void Graph<Data>::CreateEmptyGraph(int num_of_vert) {
    //! we won't fill any data here
    for (int i = 0; i < num_of_vert; ++i) {
        vector<bool> temp (num_of_vert,false);
        matrix.push_back(temp);
    }
}
template <typename Data>
void Graph<Data>::MakingFullGraph(int num_of_vert) {

    for (int i = 0; i < num_of_vert; ++i) {

        for(int j = 0; j<num_of_vert;j++)
        {
            if(i<j)
            {
                vector<int> tem (2,0);
                tem[0] = i;
                tem[1] = j;
                list_of_connectivity.push_back(tem);
            }
            if(i!=j)
            {
                matrix[i][j] = true;
            }
        }

    }


}

