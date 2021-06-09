#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   int h;
   int x;
   cin>>n>>h>>x;
   vector<int> hotspot;
   for(int i=0;i<h;i++)
   {

        int t;
        cin>>t;
        hotspot.push_back(t);
   }

   vector<vector<int>> v;
   vector<int> temp;
   for(int i=0;i<n+1;i++)
   {
       v.push_back(temp);
   }
   for(int i=0;i<n-1;i++)
   {
       int x,y;
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);

   }
   vector<int> check(n+1,0);
   for(int i=0;i<h;i++)
   {
       queue<int> q;
       if(check[hotspot[i]]==i)
       {
           check[hotspot[i]]++;
       }
        q.push(hotspot[i]);
        q.push(0);
       int dep=x;
       int s;
       while(!q.empty()&&dep>0)
        {
            if(q.front()==0)
            {

                q.pop();
                q.push(0);dep--;continue;
            }


        s = q.front();

        q.pop();


        for (auto lo = v[s].begin(); lo != v[s].end(); ++lo)
        {
            if (check[*lo]==i)
            {
                check[*lo]++;
                q.push(*lo);
            }
        }

        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {

       // cout<<check[i]<<endl;
        if(check[i]==h){ans++;}
    }
    cout<<"ans : "<<ans<<endl;
    return 0;
}
