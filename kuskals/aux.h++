#ifndef AUX_H
#define AUX_H

    #include <vector>
    #include <string>
    #include <cstdio>
    #include <cstdlib>

    using namespace std;

    enum{
        help = 0,
        show_solu,
        redirect,
        graph_file,

        qty_comands
    };

     struct edge {
        public:
        int u,v,wheight;
        
        edge();
        edge(int _u, int _v, int _wheight);
        edge& operator= (const edge& other);

    };

    int read_W_graph(const char* f_name, vector<edge>& graph);
    void print_solution(edge *solu, int size, bool show_tree);
    void redirect_solution(const char *f_name, edge* solu, int size, bool show_tree);
    void show_help();
    //void show_graph(vector<edge>& gph); // debug

#endif