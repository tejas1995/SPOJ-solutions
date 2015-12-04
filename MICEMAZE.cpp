#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node
{
    int id;
    int explored;
    long shortest_time;
    vector<int> edge_index;
};

struct Edge
{
    int end_node_index[2];
    long crossing_time;
};

Node *node;
Edge *edge;
vector<Edge> frontier_edge_list;

bool sort_frontier_edge_list(Edge edge1, Edge edge2)
{
    int total_length_1, total_length_2;

    total_length_1 = node[edge1.end_node_index[1]].shortest_time + edge1.crossing_time;
    total_length_2 = node[edge2.end_node_index[1]].shortest_time + edge2.crossing_time;

    return (total_length_1 < total_length_2);
}

int main()
{
    int N, E, T, M;
    cin >> N >> E >> T >> M;

    node = new Node [N];
    edge = new Edge [N*(N-1)];
    int curr_edge = 0;
    int num_mice_exit = 0;

    for(int i = 0; i < M; i++)
    {
        int node1, node2, time;
        cin >> node1 >> node2 >> time;
        edge[i].end_node_index[0] = node1 - 1;
        edge[i].end_node_index[1] = node2 - 1;
        edge[i].crossing_time = time;

        node[node1-1].edge_index.push_back(i);
        node[node2-1].edge_index.push_back(i);
    }

    for(int j = 0; j < N; j++)
        node[j].explored = false;

    int starting_node_index = E-1;
    node[starting_node_index].shortest_time = 0;
    node[starting_node_index].explored = true;

    for(int j = 0; j < node[starting_node_index].edge_index.size(); j++)
        if(edge[node[starting_node_index].edge_index[j]].end_node_index[1] == starting_node_index)
            frontier_edge_list.push_back( edge[node[starting_node_index].edge_index[j]] );

    while(frontier_edge_list.size() > 0)
    {
        int explored_index, unexplored_index;

        //Sort frontier edges and extract the one with least new shortest distance
        sort(frontier_edge_list.begin(), frontier_edge_list.end(), sort_frontier_edge_list);        
        /*
        for(int j = 0; j < frontier_edge_list.size(); j++)
            cout << frontier_edge_list[j].end_node_index[0] << " " << frontier_edge_list[j].end_node_index[1] << " " << frontier_edge_list[j].crossing_time << endl;
        */
        
        Edge required_edge = frontier_edge_list[0];
        frontier_edge_list.erase( frontier_edge_list.begin() );

        explored_index = required_edge.end_node_index[1];
        unexplored_index = required_edge.end_node_index[0];

        //Set shortest distance for unexplored node, and set explored=true
        node[unexplored_index].shortest_time = node[explored_index].shortest_time + required_edge.crossing_time;
        node[unexplored_index].explored = true;

        //Removed frontier edges which have newly explored node as unexplored node
        for(int j = 0; j < frontier_edge_list.size();)
            if(frontier_edge_list[j].end_node_index[0] == unexplored_index)
            {
                frontier_edge_list.erase(frontier_edge_list.begin()+j);
            }
            else
                j++;

        //Add all edges with one node unexplored and one explored to frontier_edge_list
        for(int j = 0; j < node[unexplored_index].edge_index.size(); j++)
        {
            int edge_index = node[unexplored_index].edge_index[j];
            if(edge[edge_index].end_node_index[1] == unexplored_index && node[edge[edge_index].end_node_index[0]].explored == false)
            {
                frontier_edge_list.push_back(edge[edge_index]);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        //cout << i << " " << node[i].shortest_time << endl;
        if(node[i].shortest_time <= T)
            num_mice_exit++;
    }

    cout << num_mice_exit << endl;
}