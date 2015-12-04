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
    long shortest_distance;
    vector<int> edge_index;
};

struct Edge
{
    int end_node_index[2];
    long length;
};

Node node[501];
Edge *edge;
vector<Edge> frontier_edge_list;

bool sort_frontier_edge_list(Edge edge1, Edge edge2)
{
    int total_length_1, total_length_2;

    if(node[ edge1.end_node_index[0] ].explored == true)
        total_length_1 = node[edge1.end_node_index[0]].shortest_distance + edge1.length;
    else
        total_length_1 = node[edge1.end_node_index[1]].shortest_distance + edge1.length;

    if(node[ edge2.end_node_index[0] ].explored == true)
        total_length_2 = node[edge2.end_node_index[0]].shortest_distance + edge2.length;
    else
        total_length_2 = node[edge2.end_node_index[1]].shortest_distance + edge2.length;

    return (total_length_1 < total_length_2);
}

int main()
{
    int M;
    cin >> M;

    //node = new Node [501];
    edge = new Edge [M];
    int curr_edge = 0;
    int num_mice_exit = 0;

    for(int i = 0; i < M; i++)
    {
        int node1, node2, length;
        cin >> node1 >> node2 >> length;
        edge[i].end_node_index[0] = node1;
        edge[i].end_node_index[1] = node2;
        edge[i].length = length;
        
        node[node1].edge_index.push_back(i);
        node[node2].edge_index.push_back(i);
    }


    for(int j = 0; j < 501; j++)
    {
        node[j].explored = false;
        node[j].shortest_distance = -1;
    }

    int starting_node_index;
    cin >> starting_node_index;
    node[starting_node_index].shortest_distance = 0;
    node[starting_node_index].explored = true;

    int num_destinations;
    cin >> num_destinations;
    int *destination = new int [num_destinations];
    for(int i = 0; i < num_destinations; i++)
        cin >> destination[i];

    for(int j = 0; j < node[starting_node_index].edge_index.size(); j++)
        if(edge[node[starting_node_index].edge_index[j]].end_node_index[0] == starting_node_index)
            frontier_edge_list.push_back( edge[node[starting_node_index].edge_index[j]] );

    while(frontier_edge_list.size() > 0)
    {
        int explored_index, unexplored_index;

        //Sort frontier edges and extract the one with least new shortest distance
        sort(frontier_edge_list.begin(), frontier_edge_list.end(), sort_frontier_edge_list);        
        
        Edge required_edge = frontier_edge_list[0];
        frontier_edge_list.erase( frontier_edge_list.begin() );

        if(node[required_edge.end_node_index[0]].explored == true)
        {
            explored_index = required_edge.end_node_index[0];
            unexplored_index = required_edge.end_node_index[1];
        }
        else
        {
            explored_index = required_edge.end_node_index[1];
            unexplored_index = required_edge.end_node_index[0];
        }
        //Set shortest distance for unexplored node, and set explored=true
        node[unexplored_index].shortest_distance = node[explored_index].shortest_distance + required_edge.length;
        node[unexplored_index].explored = true;

        //Removed frontier edges which have newly explored node as unexplored node
        for(int j = 0; j < frontier_edge_list.size();)
            if(frontier_edge_list[j].end_node_index[0] == unexplored_index ||
                frontier_edge_list[j].end_node_index[1] == unexplored_index)
            {
                frontier_edge_list.erase(frontier_edge_list.begin()+j);
            }
            else
                j++;

        //Add all edges with one node unexplored and one explored to frontier_edge_list
        for(int j = 0; j < node[unexplored_index].edge_index.size(); j++)
        {
            int edge_index = node[unexplored_index].edge_index[j];
            if((node[edge[edge_index].end_node_index[0]].explored == true && node[edge[edge_index].end_node_index[1]].explored == false)
                || (node[edge[edge_index].end_node_index[1]].explored == true && node[edge[edge_index].end_node_index[0]].explored == false))
            {
                frontier_edge_list.push_back(edge[edge_index]);
            }
        }
    }

    for(int i = 0; i < num_destinations; i++)
        if(node[destination[i]].shortest_distance == -1)
            cout << "NO PATH" << endl;
        else
            cout << node[destination[i]].shortest_distance << endl;
}