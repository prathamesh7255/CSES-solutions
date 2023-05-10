//Require more optimized solution for this problem

#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;

int func(int sum,vector<int>& coins,int ind,vector<vector<int>>& dp){
    if(sum==0){
        return 1;
    }
    if(dp[sum][ind]!=-1){
        return dp[sum][ind];
    }
    int ans=0;
    for(int i=ind;i>=0;i--){
        if(sum- coins[i]>=0){
            ans+=func(sum- coins[i],coins,i,dp);
            ans%=inf;
        }
    }
    return dp[sum][ind]=ans;
}

int main()
 {
 	int n,x;
      cin>>n>>x;
      vector<int>coins(n);
      for(int i=0;i<n;i++){
        cin>>coins[i];
      }
      sort(coins.begin(),coins.end());
      vector<vector<int>>dp(x+1,vector<int>(n,-1));
      cout<<func(x,coins,n-1,dp)<<endl;
 	return 0;
 }
