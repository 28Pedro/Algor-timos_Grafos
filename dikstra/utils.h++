#ifndef UTILS_H
#define UTILS_H

    #include <fstream>
    #include <vector>
    #include <string>
    #include <cstdio>
    #include <cstdlib>
    
    #include "dijkstra.h++"

    using namespace std;

    enum{
        help = 0,
        redirect,
        graph_file,

        qty_comands
    };

    int read_W_graph(const char *f_name, vector<vector<pair<int,int>>>& graph);
    void print_solution(cost_prev *solu, int size, int init_vertex);
    void redirect_solution(const char *f_name, cost_prev* solu, int size, int init_vertex);
    void show_help();
    int nextInt(char *&p);
    //void show_graph(vector<vector<pair<int,int>>> gph); // debug

#endif