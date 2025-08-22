#include<bits/stdc++.h>
using namespace std;

int node_no, edge_no;
vector<pair<int, pair<int, int>>> edges;
int parent[100];
int ranks[100];
int degree[100]; // To track the number of connections per village

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (ranks[rootX] > ranks[rootY])
            parent[rootY] = rootX;
        else if (ranks[rootX] < ranks[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            ranks[rootX]++;
        }
    }
}

void kruskal() {
    sort(edges.begin(), edges.end());
    vector<pair<int, pair<int, int>>> mst;
    int total_cost = 0;

    for (auto edge : edges) {
        int weight = edge.first;
        int nodeA = edge.second.first;
        int nodeB = edge.second.second;

        if (find(nodeA) != find(nodeB) && degree[nodeA] < 2 && degree[nodeB] < 2) {
            mst.push_back({nodeA, {nodeB, weight}});
            union_sets(nodeA, nodeB);
            degree[nodeA]++;
            degree[nodeB]++;
            total_cost += weight;
        }
    }

    cout << "Minimum Spanning Tree edges:\n";
    for (auto edge : mst) {
        int nodeA = edge.first;
        int nodeB = edge.second.first;
        int weight = edge.second.second;
        cout << nodeA << " - " << nodeB << "  Weight: " << weight << endl;
    }
    cout << "Total Cost: " << total_cost << endl;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &node_no);
    printf("Enter the number of edges: ");
    scanf("%d", &edge_no);

    for (int i = 1; i <= node_no; i++) {
        parent[i] = i;
        ranks[i] = 0;
        degree[i] = 0;
    }

    for (int i = 1; i <= edge_no; i++) {
        int nodeA, nodeB, weight;
        scanf("%d %d %d", &nodeA, &nodeB, &weight);
        edges.push_back({weight, {nodeA, nodeB}});
    }

    kruskal();
    return 0;
}

