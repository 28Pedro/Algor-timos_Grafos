#ifndef UTILS_H
#define UTILS_H

    #include <vector>
    #include <string>
    #include <stdio.h>
    #include <stdlib.h>
    
    #include "kosaraju.h++"

    using namespace std;

    enum{
        help = 0,
        redirect,
        graph_file,

        qty_comands
    };

    void read_W_graph(const char* fname, adj_list& graph, adj_list& t_graph);
    void print_solution(adj_list& solu);
    void redirect_solution(const char *f_name, adj_list& solu);
    void show_help();
    void show_graph(adj_list& gph); // debug

#endif
