#include <bits/stdc++.h>
using namespace std;
int node_no, edge_no;
vector<pair<int, int>> adj[100];
int weight[100], parent[100];
bool visited[100];
void prims(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= node_no; i++) {
        weight[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    weight[source] = 0;
    pq.push({ weight[source], source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v] && w < weight[v]) {
                weight[v] = w;
                parent[v] = u;
                pq.push({weight[v], v});
            }
        }
    }

    for (int i = 1; i <= node_no; i++) {
        if (parent[i] != -1)
            cout << parent[i] << "-" << i << " Weight:" << weight[i] << endl;
    }
}

int main() {
    printf("Enter the number of nodes:");
    scanf("%d", &node_no);
    printf("Enter the number of edges:");
    scanf("%d", &edge_no);

    for (int i = 1; i <= edge_no; i++) {
        int nodeA, nodeB, w;
        scanf("%d %d %d", &nodeA, &nodeB, &w);
        adj[nodeA].push_back({nodeB, w});
        adj[nodeB].push_back({nodeA, w});
    }

    int s;
    cout << "Enter source:";
    cin >> s;

    prims(s);
}
/*
1 2 14
1 3 3
2 3 10
2 4 6
2 5 5
4 5 4
3 6 8
5 6 2
5 7 9
6 8 15
*/

