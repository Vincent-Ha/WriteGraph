/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include "assert.h"
#include "Graph.h"

Graph::Graph(int n) {
	vertices = n;
	edges = 0;
	for (int a = 0; a <= n; a++) {
		adj.push_back(List<int>());
		color.push_back('W');
		distance.push_back(-1);
		parent.push_back(-1);
	}
}

int Graph::getNumEdges() {
	return edges;
}

int Graph::getNumVertices() {
	return vertices;
}

bool Graph::isEmpty() {
	for (int count = 1; count <= vertices; count++) {
		if (!adj[count].isEmpty())
			return false;
	}

	return true;
}

void Graph::addEdge(int u, int v) {
	assert(u <= getNumVertices() && v <= getNumVertices());
	adj[u].insertLast(v);
	adj[v].insertLast(u);
	edges++;
}

void Graph::printGraph(ostream& output) {
	if (isEmpty()) {
		output << "The graph is empty." << endl;
		return;
	}

	for (int count = 1; count <= vertices; count++) {
		output << count << ": ";
		if (!adj[count].isEmpty()) {
			adj[count].startIterator();
			while (!adj[count].offEnd()) {
				output << adj[count].getIterator() << " ";
				adj[count].advanceIterator();
			}
			output << endl;
		}
	}
}

void Graph::printBFS(ostream& output) {
	output << "v	c	p	d" << endl;
	for (int a = 1; a <= vertices; a++) {
		output << a << "	" << color[a] << "	" << parent[a] << "	" << distance[a]
				<< endl;
	}
}

void Graph::BFS(int source) {
	assert(!isEmpty());
	assert(!adj[source].isEmpty());

	List<int> queue;
	for (int a = 1; a <= vertices; a++) {
		color[a] = 'W';
		distance[a] = -1;
		parent[a] = -1;
	}
	color[source] = 'G';
	distance[source] = 0;
	queue.insertLast(source);
	int x;
	while (!queue.isEmpty()) {
		x = queue.getFirst();
		queue.removeFirst();
		if (!adj[x].isEmpty()) {
			adj[x].startIterator();
			while (!adj[x].offEnd()) {
				if (color[adj[x].getIterator()] == 'W') {
					color[adj[x].getIterator()] = 'G';
					distance[adj[x].getIterator()] = distance[x] + 1;
					parent[adj[x].getIterator()] = x;
					queue.insertLast(adj[x].getIterator());
					adj[x].advanceIterator();
				} else
					adj[x].advanceIterator();
			}
		}
		color[x] = 'B';
	}
}

void Graph::printPath(int source, int destination, ostream& output) {
	if (destination == source)
		output << source << " ";
	else if (parent[destination] == -1) {
		output << "No " << source << "-" << destination << " path exists"
				<< endl;
	} else {
		printPath(source, parent[destination], output);
		output << destination << " ";
	}
}

int Graph::getDistance(int v) {
	return distance[v];
}
