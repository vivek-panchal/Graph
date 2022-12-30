//Adjacent Matrix representation

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nodes, edges, u, v;
	cin >> nodes >> edges;

	// declare the adjacent matrix 
	vector<vector<int>> adj;
	adj.resize(nodes + 1);

	// take edges as input 
	for (int i = 0; i < edges; i++) {
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	return 0;
}


//Adjacent List representation

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nodes, edges, u, v;

	cin >> nodes >> edges;

	// declare the adjacent list
	vector<vector<int>> adj;
	adj.resize(nodes + 1);

	// take edges as input 
	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	return 0;
}
