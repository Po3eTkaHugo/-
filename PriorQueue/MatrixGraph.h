#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int v_count;
    vector<vector<int>> g;

public:
    Graph(int v_count);
    ~Graph();

    void insert(int v, int w, int weight = 1);
    void remove(int v, int w);
    void clear();
    vector<pair<int, int>> adjacent_vertices(int v);
    int getSize();
    int getWeight(int v, int w);
};