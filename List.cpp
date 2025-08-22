#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int>l;

    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        l.push_back(a);
    }

    for(list<int>  :: iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

     cout<<l.front()<<endl;
     cout<<l.back()<<endl;

     l.pop_front();


    for(list<int>  :: iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    l.sort();
    l.unique();
    for(list<int> :: iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
}
