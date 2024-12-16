// nadim [ict,mbstu]
#include <bits/stdc++.h>
using namespace std;
#define tc int t;cin>>t;while(t--)
#define ll long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define take(x) int x;cin>>x;
#define all(v) v.begin(),v.end()
#define stp(x) setprecision(x)
int lev[100];
void dfs(int s,vector<int>& vis,vector<vector<int>>& v)
{
    
    
    vis[s]=1;
    
    for(auto q:v[s])
    {
        if(!vis[q])
        {
            lev[q]=lev[s]+1;
            dfs(q,vis,v);
            
        }
    }

    cout<<s<<" ";



}
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   std::vector<vector<int>> v;
    

   v.resize(n+1);
   for (int i = 1; i <= n; ++i)
   {
       int x,y;
       cin>>x>>y;

       v[x].pb(y);
       v[y].pb(x);
   }
   // for (int i = 1; i <= n; ++i)
   // {
   //     for (auto q: v[i])
   //     {
   //         cout<<q<<" ";
   //     }
   //     cout<<"\n";
   // }

    vector<int>vis(n+1);
    dfs(1,vis,v);
cout<<"\n";
int nextN=-1,maxx=0;
for (int i = 1; i <= n; ++i)
{
    if(maxx<lev[i])
    {
        maxx=lev[i];
        nextN=i;
    }
    cout<<lev[i]<<" ";
}
cout<<"\n";
  
    
    memset(lev,0,sizeof(lev));

   
cout<<nextN<<"\n";

 vector<int>vis2(n+1);
dfs(nextN,vis2,v);
cout<<"\n";
int ii=-1,mm=0;
   for (int i = 1; i <= n; ++i)
{
    if(mm<lev[i])
    {
        mm=lev[i];
        ii=i;
    }
    cout<<lev[i]<<" ";
}
cout<<"\n";
cout<<"\n";
cout<<"Diameter : "<<lev[ii]<<"\n";

   
   return 0;
}
