#ifndef DIJKSTRA_H
#define DIJKSTRA_H

    #include <vector>
    #include <queue>
    #include <string>
    #include <functional>
   
    using namespace std;

    struct cost_prev
    {
        int cost,prev;
        cost_prev(int _cost = __INT32_MAX__, int _prev = -1) : cost(_cost), prev(_prev)
        {} 
    };
    
    cost_prev* f_prim(vector<vector<pair<int,int>>>& graph, int v_0, int n_edges);
    
#endif