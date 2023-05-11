#include<bits/stdc++.h>
using namespace std;

bool bfs(int k,vector<vector<int>>& grid,vector<int>& ans){
   queue<int>q;
   q.push(k);
   int x;
   while(!q.empty()){
      x=q.front();
      q.pop();
      for(int i=0;i<grid[x].size();i++){
         if(ans[x]==ans[grid[x][i]]){
            return false;
         }
         else if((ans[grid[x][i]]==0)){
            if(ans[x]==1){
               ans[grid[x][i]]=2;
            }
            else{
               ans[grid[x][i]]=1;
            }
            q.push(grid[x][i]);
         }
      }
   }
   return true;
}

int main()
 {
 	int n,m;
    cin>>n>>m;
    int x,y;
    vector<vector<int>>grid(n);
    for(int i=0;i<m;i++){
      cin>>x>>y;
      x--;
      y--;
      grid[x].push_back(y);
      grid[y].push_back(x);
    }
    vector<int>ans(n,0);
    ans[0]=1;
    bool result=bfs(0,grid,ans);
    for(int i=1;i<n;i++){
      if(ans[i]==0){
         ans[i]=1;
         result&=bfs(i,grid,ans);
      }
    }
    if(result){
      for(int i=0;i<n;i++){
         cout<<ans[i]<<" ";
      }
      cout<<endl;
    }
    else{
      cout<<"IMPOSSIBLE"<<endl;
    }
    
 	return 0;
 }
