#include<bits/stdc++.h>
using namespace std;

int main()
{
   map<int,int>mp;

   for(int i=0 ;i<5;i++)
   {
       int a,b;
       cin>>a>>b;
       mp.insert({a,b});
   }

  for(map<int,int>:: iterator it=mp.begin();it!=mp.end();it++)
   {
       cout<<(*it).first<<" "<<(*it).second<<endl;
   }
  /* map<int,int> :: iterator it;
   it=mp.begin();
   for(auto it:: mp)
   {
       cout<<it.first<<" "<<it.second<<endl;
   }*/

}
