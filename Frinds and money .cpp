#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q;
    cin>>p>>q;
    map<string,int>mp;
    while(p--)
    {

        string name;
        int money;
        cin>>name>>money;
        mp[name]=money;
    }
    while(q--)
    {
        int type,money;
        string name;
        cin>>type;
        if(type==1)
        {
            cin>>name>>money;
        }
        else
        {
            cin>>name;
        }

        if(type==1)
        {
            mp[name]+=money;
        }
        else if(type==2)
        {
            cout<<mp[name]<<endl;
        }
    }
}
