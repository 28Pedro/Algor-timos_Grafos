#include "utils.h++"

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

void read_W_graph(const char* fname, adj_list& graph, adj_list& t_graph)
{
    FILE* f = fopen(fname, "rb");

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
    t_graph.resize(vertex);

    for (int i = 0; i < vertex; i++) 
    {
        graph[i].reserve(edje / vertex * 2);
        t_graph[i].reserve(edje / vertex * 2);
    }

    for (int i = 0; i < edje; i++) {

        int v1 = nextInt(p) - 1;
        int v2 = nextInt(p) - 1;

        graph[v1].push_back(v2);
        t_graph[v2].push_back(v1);
    }

    free(buffer);

}

void print_solution( adj_list& solu)
 {
        for(auto &vec : solu)
        {
            for(auto i : vec)
            {
                printf("%d ", i + 1);
            }

            printf("\n");
        }

}
  
void redirect_solution(const char *f_name, adj_list& solu)
{
    FILE *file = fopen(f_name, "w");

    if(!file)
    {
       perror("ERRO AO ABRIR/CRIAR ARQUIVO");
    }

    for(auto &vec : solu)
    {
        for(auto i : vec)
        {
            fprintf(file,"%d ", i + 1);
        }

        fprintf(file,"\n");
    }

    fclose(file);
}
    

void show_help()
{
    printf("Parâmetros:\n");
    printf(" -h     Mostra essa mensagem de ajuda\n" );
    printf(" -f     Especifica o arquivo de entrada do grafo ponderado\n");
    printf(" -o     Redireciona a saída para um arquivo \n");
}

// função de debug

void show_graph(adj_list& gph)
{
    for(int i = 0; i < gph.size(); i++)
    {
        for(auto &p : gph[i])
        {
           printf("(%d,%d)", i+1,p+1);
        }
    }

    printf("\n");
}