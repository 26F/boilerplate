/*
Using depth first search to search for number of connected components.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> depth_first_search(vector<vector<int>> graph, vector<char>& visited, int start_vertex)
{
	stack<int> stck;
	stck.push(start_vertex);

	vector<int> component;

	while (!stck.empty()) {
		int u = stck.top();
		stck.pop();

		if (visited[u] == 'U') {
		
			component.push_back(u);

			visited[u] = 'D';
			
			for (int v : graph[u]) {
				if (visited[v] == 'U') {
					stck.push(v);
				}
			}
			visited[u] = 'P';
		}
	}
	return component;
}

vector<vector<int>> all_components(vector<vector<int>> graph, vector<char>& visited) 
{
	int nnodes = graph.size();
	int count = 0;

	vector<vector<int>> components;

	for (int n = 0; n < nnodes; n++) {
		if (visited[n] == 'U') {
			count++;
			components.push_back(depth_first_search(graph, visited, n)); 
		}
	}

	return components;
}

int main(void)
{

	vector<vector<int>> graph = {{4, 8, 13, 14}, {5}, {9, 15}, {9},
                                 {0, 8}, {1, 16, 17}, {7, 11}, {6, 11},
                                 {0, 4, 14}, {2, 3, 15}, {15}, {6, 7},
                                 {}, {0, 14}, {0, 8, 13}, {2, 9, 10},
                                 {5}, {5}};
	vector<char> visited(graph.size(), 'U');

	vector<vector<int>> components = all_components(graph, visited);
	cout << components.size();

	cout << endl << endl;

	for (vector<int> component: components) {
		for (int node : component) {
			cout << node << " ";
		}
		
		cout << endl;
	}

	return 0;
}


