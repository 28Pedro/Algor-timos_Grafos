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

int read_W_graph(const char* f_name, vector<edge>& graph)
{
    FILE* f = fopen(f_name, "rb");

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
    
    graph.reserve(edje);

    for(int i = 0; i < edje; i++)
    {
        int v1 = nextInt(p) - 1; 
        int v2 = nextInt(p) - 1;  
        int w = nextInt(p);

        graph.push_back(edge(v1,v2,w));
    }

    free(buffer);

    return vertex;
}

void print_solution(edge * solu, int size, bool show_tree)
 {
    
    if(!show_tree){

        long cost_total = 0;
        
        for(int i = 0; i < size; i++)
        {
            cost_total += solu[i].wheight; 
        }

        printf("%ld\n",cost_total);

    }else{
        
        for(int i = 0; i < size; i++)
        {
            printf("(%d,%d) ", solu[i].v + 1, solu[i].u + 1);
        }

       printf("\n");
    }
  
 }

void redirect_solution(const char *f_name, edge* solu, int size, bool show_tree)
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
        cost_total += solu[i].wheight; 
    }

    fprintf(file,"%ld \n",cost_total);

    }else {

        for(int i = 0; i < size; i++)
        {
            fprintf(file, "(%d,%d) ", solu[i].v + 1, solu[i].u + 1);
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
    printf(" -s     Mostra os vertices da árvore na saída padrão\n");
    printf("\n");
}

// funções de classes e structs
edge::edge() = default;
edge::edge(int _u, int _v, int _wheight) : u(_u), v(_v), wheight(_wheight) {}
edge& edge::operator=(const edge& other) {

    if (this != &other) { 
        u = other.u;
        v = other.v;
        wheight = other.wheight;
    }

    return *this;
    }

// função de debug

// void show_graph(vector<edge>& gph)
// {
//     for(int i = 0; i < gph.size(); i++)
//     {
//         cout << "(" << gph[i].u << "," << gph[i].v << "," << gph[i].wheight << 
//         ")" << endl;
//     }

//     cout << endl;
// }