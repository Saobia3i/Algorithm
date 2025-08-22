#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> D;
vector<vector<int>> PI;

void Floyd_W(vector<vector<int>> &Node_vec, vector<vector<int>> &Parent, int nodes)
{
    D=Node_vec;
    PI=Parent;

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            for(int k=0; k<nodes; k++)
            {
                if((D[j][k]>D[j][i]+D[i][k])&&(D[j][i]!=INT_MAX)&&(D[i][k]!=INT_MAX))
                {
                    D[j][k]=D[j][i]+D[i][k];
                    PI[j][k]=PI[i][k];
                }
            }
        }

    }
}
void printPath(vector<vector<int>> &PI,int src,int dest)
{
    if (src == dest)
    {
        cout << src << " ";
    }
    else if (PI[src-1][dest-1] == -1)
    {
        cout << "No path from " << src + 1 << " to " << dest << endl;
        return;
    }
    else
    {
        stack<int> st;
        int x=dest;
        while(x!=src)
        {
            if(x==-1)
                return;
            else
            {
                st.push(x);
                x=PI[src-1][x-1];
            }
        }
        st.push(src);
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}

int main()
{
    int node_no, edge_no;
    cout << "Enter the number of nodes: ";
    cin >> node_no;
    cout << "Enter the number of edges: ";
    cin >> edge_no;


    vector<vector<int>> Node_vec(node_no, vector<int>(node_no, INT_MAX));
    vector<vector<int>> Parent(node_no, vector<int>(node_no, -1));

    for (int i = 0; i < node_no; i++)
    {
        Node_vec[i][i] = 0; // Distance to itself is 0
    }

    cout << "Enter edges (nodeA nodeB weight):" << endl;
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        Node_vec[nodeA-1][nodeB-1] = weight;
        Parent[nodeA-1][nodeB-1] = nodeA;
    }

    Floyd_W(Node_vec, Parent, node_no);

    for (int i = 0; i < node_no; i++)
    {
        cout<<"For "<<(i+1)<<":"<<endl;
        for (int j = 0; j < node_no; j++)
        {
            if(i!=j)
            {
                if (D[i][j] == INT_MAX)
                {
                    cout << "No path from " << i + 1 << " to " << j + 1 << endl;
                }
                else
                {
                    cout << "Path from " << i + 1 << " to " << j + 1 << ": ";
                    printPath(PI, i+1, j+1);
                    cout << " (Cost: " << D[i][j] << ")"<<endl;
                }
            }

        }
        cout<<endl;
    }
    return 0;
}
/*
1 2 3
1 3 8
3 2 4
4 1 2
2 4 1
2 5 7
4 3 -5
1 5 -4
5 4 6
*/

