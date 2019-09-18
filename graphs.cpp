/*
	author of this code is rohit sharma
*/
// working with graphs using adj list

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
private:
	int V;
	list<T>*adj;
public:
	Graph(int v) {
		V = v;
		adj = new list<T>[v];
	}
	void insert(T u, T v, bool bidire = true) {
		adj[u].push_back(v);
		if (bidire) {
			adj[v].push_back(u);
		}
	}
	void print() {
		for (int i = 0; i < V; ++i)
		{	cout << i << "->";
			for (auto node : adj[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}
	void bfs(int src) {
		queue<int>q;
		bool * visited = new bool[V + 1] {0};

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			auto node = q.front();
			cout << node << ", ";
			q.pop();
			for (auto neig : adj[node]) {
				if (!visited[neig]) {
					q.push(neig);
					visited[neig] = true;
				}
			}
		}
	}
	void dfsUtil(T node, map<T, bool>&visited) {
		visited[node] = true;

		cout << node << " ";
		for (auto i : adj[node]) {
			if (!visited[i]) {
				dfsUtil(i, visited);
			}
		}
	}
	void dfs(T src) {
		map<T, bool>visited;

		dfsUtil(src, visited);
	}

	void dfsHelper(T node, map<T, bool> &visited, stack<T>&ordering) {

		visited[node] = true;

		for (auto neig : adj[node]) {
			if (!visited[neig]) {
				dfsHelper(neig,visited,ordering);
			}
		}
		//after all neig are visited push it into the stack
		ordering.push(node);
	}

	void topologicalSortDfs(T node) {
		map<T, bool>visited;
		stack<T> ordering;

		for (auto i : adj[node]) {
			if (!visited[i]) {
				dfsHelper(i, visited, ordering);
			}
		}
		while(!ordering.empty()){
			cout<<ordering.top()<<" -> ";
			ordering.pop();
		}
	}
};

int main() {
	Graph<int> g(6);
	g.insert(0, 1);
	g.insert(1, 2);
	g.insert(0, 4);
	g.insert(2, 4);
	g.insert(3, 2);
	g.insert(2, 3);
	g.insert(3, 5);
	// g.print();
	// g.bfs(0);
	// g.dfs(0);
	g.topologicalSortDfs(0);
	return 0;
}