#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> Node_Vec[100];
int dist[100];
int parent[100];
void Djikstra(int source,int node_no)
{
    for (int i = 1; i <= node_no + 1; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < Node_Vec[u].size(); i++)
        {
            int v=Node_Vec[u][i].first;
            int weight=Node_Vec[u][i].second;

            if (dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
                q.push(v);
                parent[v]=u;
            }
        }
    }
}
void Johnson(int node_no)
{
    for(int i=1; i<=node_no+1; i++)
    {
        dist[i]=INT_MAX;
        parent[i]=-1;
    }

    dist[node_no+1]=0;

    for(int i=1; i<=node_no; i++)
    {
        Node_Vec[node_no+1].push_back({i,0});
    }

    for(int i=0; i<node_no; i++)
    {
        for(int u=1; u<=node_no+1; u++)
        {
            for(int j=0; j<Node_Vec[u].size(); j++)
            {
                int v=Node_Vec[u][j].first;
                int weight=Node_Vec[u][j].second;

                if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                {
                    dist[v]=dist[u]+weight;
                    parent[v]=u;
                }
            }
        }
    }

    for (int u = 1; u <= node_no + 1; u++)
    {
        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j].first;
            int weight = Node_Vec[u][j].second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }
    }

    for(int i=1; i<=node_no; i++)
    {
        for(int j=0; j<Node_Vec[i].size(); j++)
        {
            int v=Node_Vec[i][j].first;
            int weight=Node_Vec[i][j].second;

            Node_Vec[i][j].second=dist[i]+weight-dist[v];
        }
    }

    for(int j=1; j<=node_no; j++)
    {
         Djikstra(j,node_no);

    for(int i=1; i<=node_no; i++)
    {
        if(dist[i]==INT_MAX)
            cout<<"Node "<<i<<" not reachable from "<<j<<endl;
        else
        {
            stack<int> stck;
            cout<<"Distance from "<<j<<" to node "<<i<<": "<<dist[i]<<endl;
            for(int k=i; k!=-1; k=parent[k])
            {
                stck.push(k);
            }
            cout<<"Path: ";
            while(!stck.empty())
            {
                int x=stck.top();
                cout<<x<<" ";
                stck.pop();
            }
            cout<<endl;
        }
        cout<<endl;

    }
    }

}

int main()
{
    int node, edge;
    cout << "Enter the number of nodes: ";
    cin >> node;
    cout << "Enter the number of edges: ";
    cin >> edge;

    for (int i = 0; i < edge; i++)
    {
        int a, b,weight;
        cin >> a >> b>>weight;
        Node_Vec[a].push_back({b,weight});
    }

    //topologicalSort(node);



    Johnson(node);

    return 0;
}
/*
1 2 4
1 5 1
5 4 -5
4 2 1
3 4 -2
3 2 7
*/
