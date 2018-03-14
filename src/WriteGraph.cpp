/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <fstream>
#include "Graph.h"

/*int main() {
	string name;
	ifstream fin;
	ofstream fout;
	cout << "Welcome to WriteGraph!" << endl;
	cout << endl;

	cout << "Enter the name of the file containing the graph information: ";
	getline(cin, name);

	fin.open(name);
	while (!fin.good()) {
		cout << "Invalid file name!" << endl;
		cout << endl;
		cout << "Please enter the name of the file: ";
		getline(cin, name);
		fin.open(name);
	}
	cout << endl;

	cout << "***Reading from " << name << "***" << endl;

	int size, u, v;
	fin >> size;
	Graph g(size);
	while (fin >> u >> v) {
		g.addEdge(u, v);
		if(u == 0 && v == 0)
			break;
	}
	cout << endl;

	cout << "Please enter the name of the output file: ";
	getline(cin, name);
	fout.open(name);
	g.printGraph(fout);
	while(fin >> u >> v){
		if(u == 0 && v == 0)
			break;
		g.BFS(u);
		fout << "The distance from " << u << " to " << v << " is ";
		if(g.getDistance(v) == -1)
			fout << "infinity" << endl;
		else
			fout << g.getDistance(v) << endl;
		if(g.getDistance(v) != -1)
			fout << "A shortest " << u << "-" << v << " path is: ";
		g.printPath(u,v,fout);
		fout << endl;
	}
	fin.close();
	fout.close();
	cout << endl;

	cout << "Thank you! Your Graph is now written to output.txt!" << endl;
}*/
