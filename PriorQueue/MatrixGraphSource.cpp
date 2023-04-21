#include "MatrixGraph.h"

Graph::Graph(int v_count)
{
    g.resize(v_count);
    for (int i = 0; i < v_count; ++i)
        g[i].resize(v_count);
    this->v_count = v_count;
}
Graph::~Graph() {
    clear();
}

void Graph::insert(int v, int w, int weight)
{
    v--;
    w--;
    if (v >= v_count || w >= v_count)
    {
        v_count = (v > w ? v : w) + 1;
        g.resize(v_count);
        for (int i = 0; i < v_count; ++i)
            g[i].resize(v_count);
    }
    g[v][w] = weight;
    g[w][v] = weight;
}
void Graph::remove(int v, int w) {
    v--;
    w--;
    if (v >= v_count || w >= v_count) {
        return;
    }
    g[v][w] = 0;
    g[w][v] = 0;
}
void Graph::clear() {
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    v_count = 0;
}
vector<pair<int, int>> Graph::adjacent_vertices(int v) {
    vector<pair<int, int>> vec;
    if (v >= v_count)
        return vec;

    for (int i = 0; i < v_count; ++i) {
        if (g[v][i] != 0) {
            vec.push_back(make_pair(i, g[v][i]));
        }
    }
    return vec;
}
int Graph::getSize() {
    return v_count;
}
int Graph::getWeight(int v, int w) {
    return g[v][w];
}


