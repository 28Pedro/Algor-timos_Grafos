#include "utils.h++"
#include "kruskal.h++"

using namespace std;

int main(int qty, char* args[])
{
    vector<edge> graph;
    char* redirect_file;
    char* Graph_file;

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
    
        }else if(comand == "-s"){

            comands[show_solu] = true;

        }
    }

   if(comands[graph_file]){

    int qty_vrtx = read_W_graph(Graph_file,graph);
    edge* solu = kruskals(graph, qty_vrtx);
    
    if(!comands[redirect])
    {
        print_solution(solu,qty_vrtx - 1, comands[show_solu]);

    }else if(comands[redirect]){

        redirect_solution(redirect_file, solu, qty_vrtx -1, comands[show_solu]);
    }

        free(solu);

   }

   if(comands[help])
   {
        show_help();
   }

   // show_graph(graph);

    return 0;
}