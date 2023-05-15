//Require more optimized solution for this problem

#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;

int func(int sum,vector<int>& coins,vector<int>& dp){
    if(sum==0) {
        return 1;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int ans=0;
    for(int i=coins.size()-1;i>=0;i--){
        if(sum- coins[i]>=0){
            ans+=func(sum- coins[i],coins,dp);
            ans%=inf;
        }
    }
    return dp[sum]=ans;
}

int main()
 {
      int n,x;
      cin>>n>>x;
      vector<int>coins(n);
      for(int i=0;i<n;i++){
        cin>>coins[i];
      }
      vector<int>dp(x+1,-1);
      cout<<func(x,coins,dp)<<endl;
 	return 0;
 }
