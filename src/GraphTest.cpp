/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include "Graph.h"

int main(){
	cout << "Graph Testing" << endl;
		cout << "-------------" << endl;
		cout << endl;

		Graph gTest(6);
		cout << "Testing isEmpty() on empty Graph (Should return true): ";
		cout << boolalpha << gTest.isEmpty() << endl;
		cout << "Testing getNumEdges() on empty Graph (Should return 0): ";
		cout << gTest.getNumEdges() << endl;
		cout << "Testing getNumVertices() (Should return 6): ";
		cout << gTest.getNumVertices() << endl;
		cout << "Using printGraph() on an empty graph (Should return The graph is empty.): ";
		gTest.printGraph(cout);
		cout << "Testing BFS() on empty graph (Would throw an assertion):" << endl;
		//gTest.BFS(1);
		gTest.addEdge(1,2);
		cout << "Testing BFS() on a non-empty graph but on an empty vertex (Would throw an assertion):" << endl;
		//gTest.BFS(3);
		gTest.addEdge(2,6);
		gTest.addEdge(3,4);
		gTest.addEdge(5,1);
		cout << "Adding edge connecting 8 and 1 (Would throw an assertion): " << endl;
		//gTest.addEdge(8,1);
		cout << "Removing same edge (Would throw an assertion): " << endl;
		//gTest.removeEdge(1,8);
		cout << "Added edges. Testing isEmpty() (Should return false): ";
		cout << boolalpha << gTest.isEmpty() << endl;
		cout << "Testing getNumEdges() (Should return 4): ";
		cout << gTest.getNumEdges() << endl;
		cout << "Testing Print Graph: " << endl;
		gTest.printGraph(cout);
		cout << endl;

		cout << "Testing BFS() with 1 as source. Printing results:" << endl;
		gTest.BFS(1);
		gTest.printBFS(cout);
		cout << endl;
		cout << "Testing print path from 1 to 6 (Should print 1 2 6): ";
		gTest.printPath(1,6,cout);
		cout << endl;
		cout << "Testing getDistance() for 3 (Should return -1): ";
		cout << gTest.getDistance(3) << endl;
		cout << "Testing BFS() with 3 as source. print results:" << endl;
		gTest.BFS(3);
		gTest.printBFS(cout);
}

/*
Graph Testing
-------------

Testing isEmpty() on empty Graph (Should return true): true
Testing getNumEdges() on empty Graph (Should return 0): 0
Testing getNumVertices() (Should return 6): 6
Using printGraph() on an empty graph (Should return The graph is empty.): The graph is empty.
Testing BFS() on empty graph (Would throw an assertion):
Testing BFS() on a non-empty graph but on an empty vertex (Whould throw an assertion):
Adding edge connecting 8 and 1 (Would throw an assertion):
Removing same edge (Would throw an assertion):
Added edges. Testing isEmpty() (Should return false): false
Testing getNumEdges() (Should return 4): 4
Testing Print Graph:
1: 2 5
2: 1 6
3: 4
4: 3
5: 1
6: 2

Testing BFS() with 1 as source. Printing results:
v	c	p	d
1	B	-1	0
2	B	1	1
3	W	-1	-1
4	W	-1	-1
5	B	1	1
6	B	2	2

Testing print path from 1 to 6 (Should print 1 2 6): 1 2 6
Testing getDistance() for 3 (Should return -1): -1
Testing BFS() with 3 as source. print results:
v	c	p	d
1	W	-1	-1
2	W	-1	-1
3	B	-1	0
4	B	3	1
5	W	-1	-1
6	W	-1	-1
 */



