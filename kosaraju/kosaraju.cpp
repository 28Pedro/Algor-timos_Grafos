#include "kosaraju.h++"

void dfs_rec_1(int v, adj_list& adj, bool *visited, 
	stack& stk )
{
	visited[v] = true;

	for(int w : adj[v])
	{
		if(!visited[w])
		{
			dfs_rec_1(w, adj, visited, stk);
		}
	}

	stk.push(v);
}

void dfs_rec_2(int v, adj_list& adj, bool *visited, 
	vector<int>& component )
{
	visited[v] = true;
	component.push_back(v);

	for(int w : adj[v])
	{
		if(!visited[w])
		{
			dfs_rec_2(w, adj, visited, component);
		}
	}

}

void standart_dfs(adj_list& graph, stack& stack, bool *visited)
{
	int qty_vertex = graph.size();
	int cnt = 0;

	for(int v = 0; v < qty_vertex; v++)
	{
		if(!visited[v])
		{	
			dfs_rec_1(v, graph, visited, stack);
		}
	}
}

adj_list kosaraju(adj_list& graph, adj_list& t_graph)
{
	int qty_vertex = graph.size();

	stack stk(qty_vertex);

	bool *visited = (bool*)malloc(qty_vertex * sizeof(bool));
	memset(visited,0,qty_vertex * sizeof(bool));

	standart_dfs(graph,stk,visited);

	memset(visited,0,qty_vertex * sizeof(bool));

	adj_list solu;

	for(int i = 0; i < qty_vertex; i++)
	{
		vector<int> componet;
		int v = stk.pop();
		
		if(!visited[v]){
			dfs_rec_2(v,t_graph,visited,componet);
			solu.push_back(move(componet));
		}
	}

	free(visited);
	return solu;
}

// implemntação da classe stack

stack::stack(int _size) : pos(-1)
{
	array = (int*)malloc(_size * sizeof(int));
}
void stack::push(int data)
{
	array[++pos] = data;
}

int stack::pop()
{
	return array[pos--];
}

stack::~stack()
{
	free(array);
}