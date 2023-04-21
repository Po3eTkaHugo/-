#include "PriorQueue.h"

PriorityQueue::PriorityQueue() = default;
PriorityQueue::~PriorityQueue() {
    clear();
}
void PriorityQueue::clear() {
    elements.clear();
}

void PriorityQueue::shiftUp(int pos) {
    if (elements.size() > 1) {
        int i = pos;
        int parent = (i - 1) / 2;

        while (elements[i].second < elements[parent].second) {
            swap(elements[i], elements[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}
void PriorityQueue::push(int v, int weight) {
    elements.push_back(make_pair(v, weight));
    shiftUp(elements.size() - 1);
}
void PriorityQueue::shiftDown(int pos) {
    if (elements.size() > 1) {
        int i = pos;
        int child1 = i * 2 + 1;
        int child2 = i * 2 + 2;
        int minChild;
        if (child1 < elements.size() && child2 < elements.size())
            minChild = elements[child1].second <= elements[child2].second ? child1 : child2;
        else {
            if (child1 >= elements.size() && child2 >= elements.size())
                minChild = elements.size() - 1;
            else {
                if (child1 >= elements.size())
                    minChild = child2;
                else
                    minChild = child1;
            }
        }

        while (elements[i].second > elements[minChild].second) {
            swap(elements[i], elements[minChild]);
            i = minChild;
            int child1 = i * 2 + 1;
            int child2 = i * 2 + 2;
            if (child1 < elements.size() && child2 < elements.size())
                minChild = elements[child1].second <= elements[child2].second ? child1 : child2;
            else {
                if (child1 >= elements.size() && child2 >= elements.size())
                    minChild = elements.size() - 1;
                else {
                    if (child1 >= elements.size())
                        minChild = child2;
                    else
                        minChild = child1;
                }
            }
        }
    }
}
void PriorityQueue::pop() {
    elements[0] = elements[elements.size() - 1];
    elements.erase(elements.end() - 1);
    shiftDown(0);
}
int PriorityQueue::top() {
    return elements[0].first;
}
void PriorityQueue::printAsArray() {
    for (pair<int, int> i : elements)
        cout << i.first << ' ';
    cout << endl;
}
void PriorityQueue::coutTree(int pos, int level) {
    if (pos < elements.size()) {
        int child1 = pos * 2 + 1;
        int child2 = pos * 2 + 2;
        coutTree(child2, level + 1);
        for (int i = 0; i < level; i++) cout << '\t';
        cout << elements[pos].first << endl;
        coutTree(child1, level + 1);
    }
}
void PriorityQueue::printAsTree() {
    coutTree(0, 0);
}
bool PriorityQueue::isEmpty() {
    return elements.size() == 0 ? true : false;
}

void PriorityQueue::primMST(Graph* g) {
    int V = g->getSize();
    vector<int> weights(V, 1000); //веса
    vector<int> MST(V, -1); //вершины мин остовного дерева
    vector<bool> inMST(V, false); //для отслеживания вершин включенных в MST

    int startVert = 0;
    push(startVert, 0);
    weights[startVert] = 0;

    while (!isEmpty()) {
        int u = top();
        pop();

        if (inMST[u] == true) {
            continue;
        }
        inMST[u] = true;  

        vector<pair<int, int>> next = g->adjacent_vertices(u);
        for (pair<int, int> i : next) {
            int v = i.first;
            int weight = i.second;

            if (inMST[v] == false && weights[v] > weight) {
                weights[v] = weight;
                push(v, weights[v]);
                MST[v] = u;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < V; ++i) {
        sum += weights[i];
        if (MST[i] != -1) cout << MST[i] + 1 << '-' << i + 1 << endl;
    }
    cout << "Weight of MST: " << sum;
}