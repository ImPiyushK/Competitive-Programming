#include<bits/stdc++.h>
using namespace std;

void dfs_helper(vector<vector<int> > g, int V, int *parent, int *visited, int src)
{
	visited[src] = 1;
	int l = g[src].size();
	for (int i = 0 ; i < l ; ++i)
	{
		int d = g[src][i];
		if (visited[d] == 0)
		{
			parent[d] = src;
			dfs_helper(g, V, parent, visited, d);
		}
	}
}

void dfs(vector<vector<int> > g, int V)
{
	int parent[V], visited[V];

	for (int i = 0 ; i < V ; ++i)
	{
		parent[i] = -1;
		visited[i] = 0;
	}

	for (int i = 0 ; i < V ; ++i)
	{
		if (visited[i] == 0)
			dfs_helper(g, V, parent, visited, i);
	}
	for (int  i = 0 ; i < V ; ++i)
		cout << i << " -> " << parent[i] << endl;

}

int main()
{
	int V, E;
	cin >> V >> E;
	vector<vector<int> > g(V);

	int s, d;
	for (int i = 0 ; i < E ; ++i)
	{
		cin >> s >> d;

		g[s].push_back(d);
		g[d].push_back(s);
	}
	dfs(g, V);
}