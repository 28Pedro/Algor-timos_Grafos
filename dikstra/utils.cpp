#include "aux.h++"

int nextInt(char *&p)
{
    while (*p && (*p < '0' || *p > '9') && *p != '-')
    {
        ++p;
    }

    int sign = 1;

    if(*p == '-'){ 

        sign = -1;
        ++p; 
    }
    
    int x = 0;

    while (*p >= '0' && *p <= '9'){

        x = x * 10 + (*p++ - '0');
    }

    return x * sign;
}

int read_W_graph(const char* fname, vector<vector<pair<int,int>>>& graph)
{
    FILE* f = fopen(fname, "rb");

    if (!f)
    {
        return -1;
    } 

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);

    char* buffer = (char*)malloc(size + 1);
    fread(buffer, 1, size, f);
    
    fclose(f);

    char* p = buffer;

    int vertex = nextInt(p);
    int edje = nextInt(p);

    graph.resize(vertex);

    for (auto &adj : graph){

        adj.reserve(edje / vertex * 2);

    }
        
    for (int i = 0; i < edje; i++) {

        int v1 = nextInt(p) - 1;
        int v2 = nextInt(p) - 1;
        int w  = nextInt(p);

        graph[v1].push_back({w, v2});
        graph[v2].push_back({w,v1});
    }

    free(buffer);

    return edje;
}

void print_solution(cost_prev* solu, int size, int init_vertex)
 {
        for(int i = 0; i < size; i++)
        {
            if(solu[i].cost != __INT32_MAX__){

                printf("%d:%d ", i + 1, solu[i].cost);

            }else{

                printf("%d:-1 ", i + 1);
            }  
        }

        printf("\n");
}
  
void redirect_solution(const char *f_name, cost_prev* solu, int size, int init_vertex)
{
    FILE *file = fopen(f_name, "w");

    if(!file)
    {
       perror("ERRO AO ABRIR/CRIAR ARQUIVO");
    }

    for(int i = 0; i < size; i++)
    {
        if(solu[i].cost != __INT32_MAX__){

            fprintf(file, "%d:%d ", i + 1, solu[i].cost);

        } else{
            
            fprintf(file, "%d:-1 ", i + 1);

        }
    }

    fclose(file);
}
    
void show_help()
{
    printf( "Parâmetros:\n");
    printf( " -h     Mostra essa mensagem de ajuda\n");
    printf( " -f     Especifica o arquivo de entrada do grafo ponderado\n");
    printf( " -o     Redireciona a saída para um arquivo\n");
    printf( " -i     Especifica o vértice inicial\n");
    printf("\n");
}

// função de debug

// void show_graph(vector<vector<pair<int,int>>> gph)
// {
//     for(int i = 0; i < gph.size(); i++)
//     {
//         for(auto &p : gph[i])
//         {
//             cout << "(" << i+1 << "," << p.second + 1<< "," << p.first
//             << ")";
//         }
//     }

//     cout << endl;
// }
