#include <gtest/gtest.h>
#include <climits>
#include "..//Graph.h"
#include "..//Time.h"
#include "..//Graph.cpp"
#include "..//Time.cpp"
#include <random>
Graph<int> RandomConnectedGraph()
{
    // we generate a graph witn 1-10 vertices
    int num_of_vert = rand()%10 + 1;
    Graph<int> a;
    // generating vertices
    for (int i = 0; i < num_of_vert; ++i) {
        a.AddVertex(0);

    }

    // making a graph full
    a.MakingFullGraph(num_of_vert);

    // even if we remove (num_of_vert - 2) edges it still remains connected
    for (int i = 0; i < num_of_vert-2; ++i) {
        int i_rand = rand()%num_of_vert;
        int j_rand = rand()%num_of_vert;
        a.RemoveEdge(i_rand,j_rand);
    }

    return a;
}

Graph<int> RandomUnconnectedGraph()
{
    // we generate a graph witn 1-10 vertices
    int num_of_vert = rand()%10 + 1;
    Graph<int> a;
    // generating vertices
    for (int i = 0; i < num_of_vert; ++i) {
        a.AddVertex(0);

    }


    // even if we add (num_of_vert - 2) edges it still remains unconnected
    for (int i = 0; i < num_of_vert-2; ++i) {
        int i_rand = rand()%num_of_vert;
        int j_rand = rand()%num_of_vert;
        a.AddEdge(i_rand,j_rand);
    }
    return a;
}


TEST(Graph,AddVertex) {
    Graph<int> a;
    // the value doesn't matter here
    a.AddVertex(0); // we will just test if it compiles



}

TEST(Graph,RemoveVertex) {
    Graph<int> a;
    a.AddVertex(0);
    // now we have only first vertex
    a.RemoveVertex(0); // we will just test if it compiles



}

TEST(Graph,AddEdge) {
    Graph<int> a;
    // we add two vertices
    a.AddVertex(0);
    a.AddVertex(0);
    // we will add the only one edge
    a.AddEdge(0,1);// we will just test if it compiles
    a.AddEdge(0,1);// an error can appear here
    a.AddEdge(0,0);// or here


}

TEST(Graph,RemoveEdge) {
    Graph<int> a;
    // we add two vertices
    a.AddVertex(0);
    a.AddVertex(0);
    // we will add the only one vertex
    a.AddEdge(0,1);

    //and remove it
    a.RemoveEdge(0,1);// we will just test if it compiles
    a.RemoveEdge(0,1);// an error can appear here
    a.RemoveEdge(0,0);// or here


}

TEST(Graph,IsConnected) {
    Graph<int> a;
    // 10 times will be enough for positive result
    for (int i = 0; i < 10; ++i) {
        a = RandomConnectedGraph();
        ASSERT_EQ(true,a.IsConnected());
    }



}

TEST(Graph,IsnConnected) {
    Graph<int> a;

    for (int i = 0; i < 10; ++i) {
        a = RandomUnconnectedGraph();
        ASSERT_EQ(false,a.IsConnected());
    }

}

TEST(Graph,Dist_Between_Vertexes)
{
    // we will check it on my example
    Graph<int> a;
    a.AddVertex(0);
    a.AddVertex(0);
    a.AddVertex(0);
    a.AddEdge(0,1);
    a.AddEdge(1,2);
    ASSERT_EQ(2,a.Dist_Between_Vertexes(0,2));

}

TEST(Graph,CheckingIfHasEulerCycle) {
    // my example
    Graph<int> a;
    a.AddVertex(0);
    a.AddVertex(0);
    a.AddVertex(0);
    a.AddEdge(0,1);
    a.AddEdge(1,2);
    a.AddEdge(0,2);
    ASSERT_EQ(true,a.CheckingIfHasEulerCycle());
    a.RemoveEdge(1,2);
    ASSERT_EQ(false,a.CheckingIfHasEulerCycle());







}

TEST(Graph,CheckingIfHasEulerCircuit)
{
    // my example
    Graph<int> a;
    a.AddVertex(0);
    a.AddVertex(0);
    a.AddVertex(0);
    a.AddEdge(0,1);
    a.AddEdge(1,2);
    a.AddEdge(0,2);
    ASSERT_EQ(false,a.CheckingIfHasEulerCircuit());
    a.RemoveEdge(1,2);
    ASSERT_EQ(true,a.CheckingIfHasEulerCircuit());
}

TEST(Date,SetDate){
    Date date;
    date.SetDate(1991,0,0,0,0,0,0); // we will just test if it compiles
}

TEST(Date,IsLeap){
    Date date;
    date.SetDate(1900,0,1,0,0,0,0);
    ASSERT_EQ(false,date.IsLeap());
    date.SetDate(1901,0,1,0,0,0,0);
    ASSERT_EQ(false,date.IsLeap());
    date.SetDate(1904,0,1,0,0,0,0);
    ASSERT_EQ(true,date.IsLeap());
    date.SetDate(2000,0,1,0,0,0,0);
    ASSERT_EQ(true,date.IsLeap());
}

TEST(Date,PrintDate){
    Date date;
    date.PrintDate();// we will just test if it compiles
}

TEST(Date,Increase){
    // my example
    Date d1,d2;
    d1.SetDate(2020,8,28,0,0,0,0);
    d2.SetDate(2019,7,27,0,0,0,0);
    d2.Increase(1,1,1,0,0,0);
    ASSERT_EQ(d1,d2);
}

TEST(Date,Decrease){
    // my example
    Date d1,d2;
    d1.SetDate(2020,8,28,0,0,0,0);
    d2.SetDate(2019,7,27,0,0,0,0);
    d1.Decrease(1,1,1,0,0,0);
    ASSERT_EQ(d1,d2);
}

TEST(Date,Subtract){
    Date d1,d2,d3;
    d1.SetDate(2020,8,28,0,0,0,0);
    d2.SetDate(2019,7,27,0,0,0,0);
    d3.SetDate(1,1,1,0,0,0,0);
    ASSERT_EQ(d3,d1-d2);
}

TEST(Date,Week_Day){
    // my example
    Date date;
    date.SetDate(2020,8,28,17,1,0,0);
    ASSERT_EQ("Monday",date.Week_Day());
}



int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
