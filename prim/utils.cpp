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

    for (auto &adj : graph)
        adj.reserve(edje / vertex * 2);

    for (int i = 0; i < edje; i++) {

        int v1 = nextInt(p) - 1;
        int v2 = nextInt(p) - 1;
        int w  = nextInt(p);

        graph[v1].push_back({w, v2});
        graph[v2].push_back({w, v1});
    }

    free(buffer);

    return edje;
}

void print_solution(cost_prev* solu, int size, int init_vertex, bool show_tree)
 {
    if(!show_tree){

        long cost_total = 0;
        
        for(int i = 0; i < size; i++)
        {
            cost_total += solu[i].cost; 
        }

        printf("%ld\n",cost_total);

        return;

    }else{
        
        for(int i = 0; i < size; i++)
        {
            if(i == init_vertex){
                continue;
            }

            printf("(%d,%d) ",solu[i].prev + 1,i+1);  
            
        }

        printf("\n");
    }
  
 }

void redirect_solution(const char *f_name, cost_prev* solu, int size, int init_vertex, bool show_tree)
{
    FILE *file = fopen(f_name, "w");

    if(!file)
    {
       perror("ERRO AO ABRIR/CRIAR ARQUIVO");
    }

   if(!show_tree){

    long cost_total = 0;

    for(int i = 0; i < size; i++)
    {
        cost_total += solu[i].cost; 
    }

    fprintf(file,"%ld \n",cost_total);

    }else {

        for(int i = 0; i < size; i++)
        {
            if(i == init_vertex){
                continue;
            }

            fprintf(file, "(%d,%d) ", solu[i].prev + 1, i + 1);
        }
    }

    fclose(file);
    
}

void show_help()
{
    printf("Parâmetros:\n");
    printf(" -h     Mostra essa mensagem de ajuda\n");
    printf(" -f     Especifica o arquivo de entrada do grafo ponderado\n");
    printf(" -o     Redireciona a saída para um arquivo\n");
    printf(" -s     Mostra a solução na saída padrão\n");
    printf(" -i     Especifica o vértice inicial\n");
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