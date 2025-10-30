#include "dijkstra.h++"

cost_prev* f_prim(vector<vector<pair<int,int>>>& graph, int v_0, int n_edges)
{
    int n = graph.size();

    vector<pair<int,int>> container_heap;
    container_heap.reserve(n_edges);

    cost_prev* cp = new cost_prev[n];
    bool *in_tree = new bool[n]();

    cp[v_0].cost = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> H(
        greater<pair<int,int>>(), move(container_heap)); 
        
    H.push({0,v_0});

    int size_tree = 0;

    while(!H.empty())
    {
        int u = H.top().second; 
        H.pop(); 
        
        if(in_tree[u]) 
        { 
            continue;
        }
        
        in_tree[u] = true;

        size_tree++;
        
        if(size_tree == n)
        {
            delete[] in_tree;
            return cp;
        }

        for(auto &adj : graph[u])
        {
            int w = adj.first;
            int v = adj.second;

            if(cp[v].cost > cp[u].cost + w && !in_tree[v] )
            {
                cp[v].cost = cp[u].cost + w;
                cp[v].prev = u;
                H.push({cp[v].cost,v});
            }
        }
    }

    delete[] in_tree;
    return cp;
}
