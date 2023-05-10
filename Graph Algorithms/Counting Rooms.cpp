#include<bits/stdc++.h>
using namespace std;

bool valid(int i,int j,int n,int m){
   return i>=0 && j>=0 && i<n && j<m;
}

void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& moves){
   int x,y;
   grid[i][j]='#';
   for(auto move:moves){
      x=i+move[0];
      y=j+move[1];
      if(valid(x,y,grid.size(),grid[0].size()) && grid[x][y]=='.'){
         dfs(x,y,grid,moves);
      }
   }
}

int main()
 {
 	int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>grid[i][j];
      }
    }
    int ct=0;
    vector<vector<int>>moves={{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(grid[i][j]=='.'){
            ct++;
            dfs(i,j,grid,moves);
         }
      }
    }
    cout<<ct<<endl;
 	return 0;
 }
