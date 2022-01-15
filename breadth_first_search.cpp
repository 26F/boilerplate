
#include <bits/stdc++.h>

/*
Breadth first search
*/

using namespace std;

void breadth_first_search(vector<vector<int>> graph, int root_node)
{
	queue<int> que;
	vector<bool> visited(graph.size(), false);

	que.push(root_node);

	visited[root_node] = true;

	while (!que.empty()) {
		int x = que.front();

		std::cout << x << " ";

		que.pop();

		for (int adj : graph[x]) {
			if (!visited[adj]) {

				que.push(adj);
				visited[adj] = true;
			}
		}
	}
}

int main(void)
{
	vector<vector<int>> graph = {{2, 5}, {4,5}, {0,3,4}, {2}, {0,1,2,5}, {0,1,4}};
	
	for (int v = 0; v < 6; v++) {
		breadth_first_search(graph, v);
		std::cout << std::endl;	
	}

	return 0;
}