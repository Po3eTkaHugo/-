#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "MatrixGraph.h"
using namespace std;

class PriorityQueue {
private:
    vector<pair<int, int>> elements; 
    void shiftUp(int pos);
    void shiftDown(int pos);
    void coutTree(int pos, int level);

public:
    PriorityQueue();
    ~PriorityQueue();

    void push(int v, int weight);
    void pop();
    int top();
    void clear();
    void printAsArray();
    void printAsTree();
    void primMST(Graph* g);
    bool isEmpty();
};