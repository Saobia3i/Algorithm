#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    map<string,int>mp;

    while(q--)
    {
        int type,y;
        string x;
        cin>>type;
        if(type==1)
        {
            cin>>x>>y;
        }
        else
        {
            cin>>x;
        }

        if(type==1)
        {
            mp[x]+=y;
        }
        else if(type==2)
        {
            mp.erase(x);
        }
        else if(type==3)
        {
            cout<<mp[x]<<endl;
        }

    }

}
