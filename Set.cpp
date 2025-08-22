#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int>s;
    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        s.insert(a);
    }
    for(set<int> ::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;

    /*big to small*/

    set<int,greater<int> > st;
     for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        st.insert(a);
    }
    for(set<int> :: iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }
    set<int> ::iterator it;
    int n;
    cin>>n;


        it=s.find(n);
        if(it!=s.end())
        cout<<"found"<<endl;

        int c=s.count(n);

        cout<<c<<endl;

}
