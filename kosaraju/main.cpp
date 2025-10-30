#include "utils.h++"
#include "kosaraju.h++"

int main(int qty, char* args[])
{

    adj_list graph, t_graph;
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
    
        }
    }

   if(comands[graph_file]){

    read_W_graph(Graph_file, graph, t_graph);
    adj_list solu = kosaraju(graph,t_graph);

    if(!comands[redirect])
    {
        print_solution(solu);

    }else if(comands[redirect]){

        redirect_solution(redirect_file, solu);
    }
   }

   if(comands[help])
   {
        show_help();
   }

    return 0;
}