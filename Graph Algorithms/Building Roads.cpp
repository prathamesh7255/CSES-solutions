#include<bits/stdc++.h>
using namespace std;

void dfs(int ver,vector<vector<int>>& grid,vector<int>& vis){
   vis[ver]=1;
   for(int i=0;i<grid[ver].size();i++){
      if(vis[grid[ver][i]]==0){
         dfs(grid[ver][i],grid,vis);
      }
   }
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
    vector<int>ans;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
      if(vis[i]==0){
         ans.push_back(i);
         dfs(i,grid,vis);
      }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++){
      cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
    }
 	return 0;
 }
