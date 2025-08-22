#include<bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int>pq;

    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        pq.push(a);
    }

    /*top()=auto big to small*/

    cout<<pq.top()<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    /*small values first*/

    priority_queue<int,vector<int>,greater<int> >pql;
     for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        pql.push(a);
    }

     while(!pql.empty())
    {
        cout<<pql.top()<<" ";
        pql.pop();
    }



}
