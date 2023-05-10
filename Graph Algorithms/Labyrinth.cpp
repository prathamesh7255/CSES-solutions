#include<bits/stdc++.h>
using namespace std;

bool valid(int x,int y,int n,int m){
   return x>=0 && y>=0 && x<n && y<m;
}

bool bfs(int i_s,int i_e,int j_s,int j_e,vector<vector<char>>& grid,vector<vector<int>>& ans){
   vector<vector<int>>moves={{0,1},{1,0},{-1,0},{0,-1}};
   int n=grid.size(),m=grid[0].size();
   queue<pair<int,int>> q;
   q.push({i_s,j_s});
   int X,Y,x,y;
   pair<int,int> par;
   while(!q.empty()){
      par=q.front();
      q.pop();
      X=par.first;
      Y=par.second;
      for(int i=0;i<4;i++){
         x=X+moves[i][0];
         y=Y+moves[i][1];
         if(valid(x,y,n,m) && grid[x][y]=='.'){
            ans[x][y]=i;
            q.push({x,y});
            grid[x][y]='#';
            if(x==i_e && y==j_e){
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
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>ans(n,vector<int>(m));
    int i_s,i_e,j_s,j_e;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>grid[i][j];
         if(grid[i][j]=='A'){
            i_s=i;
            j_s=j;
            grid[i][j]='#';
         }
         else if(grid[i][j]=='B'){
            i_e=i;
            j_e=j;
            grid[i][j]='.';
         }
      }
    }
    bool result=bfs(i_s,i_e,j_s,j_e,grid,ans);
    if(!result){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
      int ct=0;
      string s;
      while(i_e!=i_s || j_e!=j_s){
         if(ans[i_e][j_e]==0){
            s.push_back('R');
            j_e-=1;
         }
         else if(ans[i_e][j_e]==1){
            s.push_back('D');
            i_e-=1;
         }
         else if(ans[i_e][j_e]==2){
            s.push_back('U');
            i_e+=1;
         }
         else if(ans[i_e][j_e]==3){
            s.push_back('L');
            j_e+=1;
         }
         ct++;
      }
      cout<<ct<<endl;
      for(int j=s.size()-1;j>=0;j--){
         cout<<s[j];
      }
      cout<<endl;
    }
 	return 0;
 }
