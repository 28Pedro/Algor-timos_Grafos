#ifndef KOSARAJU_H
#define KOSARAJU_H

    #include <vector>
    #include <string>
    #include <cstdlib>
    #include <cstdio>
    #include <cstring>
    #include <ctime>
     
    using namespace std;

    typedef vector<vector<int>> adj_list;

    class stack{

       public:
            stack(int _size);
            void push(int data);
            int pop();
            ~stack();

       private:
            int *array;
            int pos;
    };

    void dfs_rec_1(int v, adj_list& adj, bool *visited, 
	stack& stk );
    void dfs_rec_2(int v, adj_list& adj, bool *visited, 
	                vector<int>& component );
    void standart_dfs(adj_list& graph, stack& stack, bool *visited);
    adj_list kosaraju(adj_list& graph, adj_list& t_graph);

#endif