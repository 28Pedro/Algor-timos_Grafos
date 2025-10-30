#ifndef AUX_H
#define AUX_H

    #include <vector>
    #include <string>
    #include <cstdio>
    #include <cstdlib>

    #include "prim.h++"

    using namespace std;

    enum{
        help = 0,
        show_solu,
        redirect,
        graph_file,

        qty_comands
    };

    int read_W_graph(const char *f_name, vector<vector<pair<int,int>>>& graph);
    void print_solution(cost_prev *solu, int size, int init_vertex, bool show_tree);
    void redirect_solution(const char *f_name, cost_prev* solu, int size, int init_vertex, bool show_tree);
    void show_help();
    int nextInt(char *&p);
    void show_graph(vector<vector<pair<int,int>>> gph); // debug

#endif