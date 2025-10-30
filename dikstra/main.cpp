#include "utils.h++"
#include "dijkstra.h++"

using namespace std;

int main(int qty, char* args[])
{
    vector<vector<pair<int,int>>> graph;
    int init_vertex = -1;
    char *redirect_file;
    char *Graph_file;

    bool comands[qty_comands] = {false};

    for(int i = 1; i < qty; i++)
    {
        string comand = args[i];

        if(comand == "-h"){

            comands[help] = true;

        } else if(comand == "-o" && (i+1 < qty)){
            
           comands[redirect] = true;
           redirect_file = args[++i];

        } else if(comand == "-f" && (i+1 < qty)){

            comands[graph_file] = true;
            Graph_file = args[++i];
    
        }else if(comand == "-i"){

            init_vertex = atoi(args[++i]) - 1;
        }
    }

    if(comands[graph_file]){

        int n_edges = read_W_graph(Graph_file,graph);
    
    if(init_vertex == -1){
        
        init_vertex = 0;
    }
    
    cost_prev *solu = f_prim(graph, init_vertex, n_edges);
    
    if(!comands[redirect])
    {
        print_solution(solu, graph.size(), init_vertex);

    }else if(comands[redirect]){

            redirect_solution(redirect_file, solu, graph.size(), init_vertex);
    }

        delete[] solu;

   }

   if(comands[help])
   {
        show_help();
   }

   //show_graph(graph);

    return 0;
}