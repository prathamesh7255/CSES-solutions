#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& grid,vector<int>& ans){
   queue<int>q;
   q.push(grid.size()-1);
   int x;
   while(!q.empty()){
      x=q.front();
      q.pop();
      for(int i=0;i<grid[x].size();i++){
         if(ans[grid[x][i]]==-1){
            ans[grid[x][i]]=x;
            q.push(grid[x][i]);
            if(grid[x][i]==0){
               return true;
            }
         }
      }
   }
   return false;

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
    vector<int>ans(n,-1);
    ans[n-1]=n;
    bool result=bfs(grid,ans);
    if(result){
      int k=0;
      vector<int>vec(1,0);
      while(ans[k]!=n){
         vec.push_back(ans[k]);
         k=ans[k];
      }
      cout<<vec.size()<<endl;
      for(int i=0;i<vec.size();i++){
         cout<<vec[i]+1<<" ";
      }
      cout<<endl;
    }
    else{
      cout<<"IMPOSSIBLE"<<endl;
    }
 	return 0;
 }
