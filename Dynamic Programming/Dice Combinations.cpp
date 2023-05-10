#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;

int func(int sum, vector<int>& dp){
    if(sum<=1) return 1;
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int ans=0;
    for(int i=6;i>0;i--){
        if(sum-i>=0){
            ans+=func(sum-i,dp);
            ans=ans%inf;
        }
    }
    return dp[sum]=ans;
}

int main()
 {
 	int n;
      cin>>n;
      vector<int>dp(n+1,-1);
      cout<<func(n,dp)<<endl;
 	return 0;
 }