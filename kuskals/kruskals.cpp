#include "kruskals.h++"

int find(int V, int *father)
{
    if(father[V] != V )
    {
        father[V] = find(father[V], father);
    }

    return father[V];
}

void Union(int V, int U, int *father, int *rank)
{
    if(rank[V] >= rank[U])
    {
        father[U] = V;

        if(rank[V] == rank[U])
        {
            rank[V]++;
        }

    } else{

        father[V] = U;
    }
}

edge* kruskals(vector<edge> graph, int qty_vrtx)
{
    int *father = (int*)malloc(qty_vrtx * sizeof(int));
    int *rank = (int*) malloc(qty_vrtx * sizeof(int));
    memset(rank,0,qty_vrtx * sizeof(int));
    
    for(int i = 0; i < qty_vrtx; i++)
    {
        father[i] = i;
    }

    edge *solu = (edge*)malloc((qty_vrtx - 1) * sizeof(edge));

    sort(graph.begin(),graph.end(),[](edge a, edge b)
    { 
        return a.wheight < b.wheight; 
    }  
       );

    int index = 0;

    for(auto &edg : graph)
    {
        if(find(edg.u,father) != find(edg.v,father))
        {
            solu[index++] = edg;

            if(index == qty_vrtx - 1)
            {
                 free(father);
                 free(rank);
                 return solu;
            }

            Union(find(edg.u,father), find(edg.v,father), father, rank);
        }
    }

   free(father);
   free(rank);

   return solu;
}

