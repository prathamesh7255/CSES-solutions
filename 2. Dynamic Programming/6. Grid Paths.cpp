#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int func(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& dp){
   if(i==0 && j==0){
      return 1;
   }
   if(dp[i][j]!=-1){
      return dp[i][j];
   }
   int ans=0;
   if(i-1>=0 && grid[i-1][j]=='.'){
      ans+=func(i-1,j,grid,dp);
      ans%=mod;
   }
   if(j-1>=0 && grid[i][j-1]=='.'){
      ans+=func(i,j-1,grid,dp);
      ans%=mod;
   }
   return dp[i][j]=ans;

}

int main()
 {
 	int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>grid[i][j];
      }
    }
    if(grid[n-1][n-1]=='*'){
      cout<<0<<endl;
    }
    else{
      vector<vector<int>>dp(n,vector<int>(n,-1));
      cout<<func(n-1,n-1,grid,dp);
    }
    
 	return 0;
 }