#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

     map<pair<int,int>,string > mp;

      while(q--)
      {
          int a,b;
          string s;
          cin>>a>>b>>s;

      mp[{a,b}]=s;


      }
      int n;
      cin>>n;


      while(n--)
      {
          int a,b;
          cin>>a>>b;
       cout<<mp[{a,b}]<<endl;

      }


}
