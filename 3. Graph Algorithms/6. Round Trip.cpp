#include<bits/stdc++.h>
using namespace std;
 
int dfs(int node,vector<vector<int>>& grid,vector<int>& vis,vector<int>& par,int & val){
   vis[node]=1;
   int k=-1;
   for(auto child:grid[node]){
      if(child!=par[node] && vis[child]==0){
         par[child]=node;
         k=dfs(child,grid,vis,par,val);
         if(k!=-1){
            return k;
         }
      }
      else if(child!=par[node] && vis[child]==1){
         val=child;
         return node;
      }
   }
   return -1;
}
 
int main()
 {
   int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n);
    int x,y;
    for(int i=0;i<m;i++){
      cin>>x>>y;
      x--;
      y--;
      grid[x].push_back(y);
      grid[y].push_back(x);
    }
    int result,val;
    vector<int>vis(n,0);
    vector<int>par(n,-1);
    for(int i=0;i<n;i++){
      if(vis[i]==0){
         result=dfs(i,grid,vis,par,val);
         if(result!=-1){
            break;
         }
      }
 
    }
    if(result==-1){
      cout<<"IMPOSSIBLE"<<endl;
    }
    else{
      vector<int>path;
      int node=result;
      while(node!=val){
         path.push_back(node);
         node=par[node];
      }
      cout<<path.size()+2<<endl;
      cout<<val+1<<" ";
      for(int i=0;i<path.size();i++){
         cout<<path[i]+1<<" ";
      }
      cout<<val+1<<endl;
    }
   return 0;
 }