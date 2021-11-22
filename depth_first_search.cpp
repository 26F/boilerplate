/*
Depth first search
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> depth_first_search(vector<vector<int>> graph, int start_vertex)
{
	stack<int> stck;
	vector<char> visited(graph.size(), 'U');
	vector<int> parent(graph.size(), -1);

	stck.push(start_vertex);

	while (!stck.empty()) {
		int u = stck.top();
		stck.pop();

		if (visited[u] == 'U') {
			//cout << u << " ";
			visited[u] = 'D';
			
			for (int v : graph[u]) {
				if (visited[v] == 'U') {
					parent[v] = u;
					stck.push(v);
				}
			}
			visited[u] = 'P';
		}
	}
	return parent;
}

int main(void)
{
	vector<vector<int>> graph = {{2,4,5}, {4,5}, {0,3,4}, {2}, {0,1,2,5}, {0,1,4}};

	vector<int> result = depth_first_search(graph, 0);
	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}


