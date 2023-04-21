#include <iostream>
#include "PriorQueue.h"
#include "MatrixGraph.h"
using namespace std;

int main() {
	Graph gr(6);
	gr.insert(1, 2, 6);
	gr.insert(1, 3, 1);
	gr.insert(1, 4, 5);
	gr.insert(2, 3, 5);
	gr.insert(3, 4, 5);
	gr.insert(2, 5, 3);
	gr.insert(3, 5, 6);
	gr.insert(3, 6, 4);
	gr.insert(4, 6, 2);
	gr.insert(5, 6, 6);

	PriorityQueue pq;
	pq.primMST(&gr);


	return 0;
}