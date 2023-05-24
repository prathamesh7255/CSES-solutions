#include<bits/stdc++.h>
using namespace std;

bool valid(int x,int y,int& n,int& m){
   return x>=0 && y>=0 && x<n && y<m;
}

void bfs(queue<pair<int,int>>& q,vector<vector<char>>& grid,vector<vector<int>>& dist){
   vector<vector<int>>moves={{0,1},{0,-1},{1,0},{-1,0}};
   int n,m;
   n=grid.size(),m=grid[0].size();
   pair<int,int>node;
   int X,x,Y,y;
   int inf=1e9+7;
   while(!q.empty()){
      node=q.front();
      q.pop();
      X=node.first;
      Y=node.second;
      for(int i=0;i<4;i++){
         x=X+moves[i][0];
         y=Y+moves[i][1];
         if(valid(x,y,n,m) && dist[x][y]==inf && grid[x][y]=='.'){
            if(dist[X][Y]==-1){
               q.push({x,y});
               dist[x][y]=-1;
            }
            else{
               q.push({x,y});
               dist[x][y]=i+1;
            }
         }
      }
   }
}

int main()
 {
 	int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    queue<pair<int,int>>q;
    int inf=1e9+7;
    vector<vector<int>>dist(n,vector<int>(m,inf));
    int s_i,s_j;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>grid[i][j];
         if(grid[i][j]=='A'){
            s_i=i;
            s_j=j;
         }
         else if(grid[i][j]=='M'){
            q.push({i,j});
            dist[i][j]=-1;
         }
      }
    }
    q.push({s_i,s_j});
    dist[s_i][s_j]=0;
    bfs(q, grid, dist);
    int e_i=-1,e_j=-1;
    for(int i=0;i<n;i++){
      if(dist[i][0]>=0 && dist[i][0]!=inf){
         e_i=i;
         e_j=0;
         break;
      }
      if(dist[i][m-1]>=0 && dist[i][m-1]!=inf){
         e_i=i;
         e_j=m-1;
         break;
      }
    }
    for(int i=0;i<m;i++){
      if(dist[0][i]>=0 && dist[0][i]!=inf){
         e_i=0;
         e_j=i;
         break;
      }
      if(dist[n-1][i]>=0 && dist[n-1][i]!=inf){
         e_i=n-1;
         e_j=i;
         break;
      }
    }
    if(e_i==-1){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
      vector<char>path;
       while(dist[e_i][e_j]!=0){
         if(dist[e_i][e_j]==1){
            path.push_back('R');
            e_j--;
         }
         else if(dist[e_i][e_j]==2){
            path.push_back('L');
            e_j++;
         }
         else if(dist[e_i][e_j]==3){
            path.push_back('D');
            e_i--;
         }
         else{
            path.push_back('U');
            e_i++;
         }
         
       }
       cout<<path.size()<<endl;
       for(int i=path.size()-1;i>=0;i--){
         cout<<path[i];
       }
    }

 	return 0;
 }
