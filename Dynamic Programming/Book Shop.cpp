//Require more optimized solution for this problem

#include<bits/stdc++.h>
using namespace std;

int func(int ind,int sum,vector<int>& h,vector<int>& s,vector<vector<int>>& dp){
   if(ind<0 || sum==0){
      return 0;
   }
   if(dp[sum][ind]!=-1){
      return dp[sum][ind];
   }
   int ans=0;
   if(sum-h[ind]>=0){
      ans=max(ans,func(ind-1,sum-h[ind],h,s,dp)+s[ind]);
   }
   ans=max(ans,func(ind-1,sum,h,s,dp));
   return dp[sum][ind]=ans;
}

int main()
 {
 	int n,x;
    cin>>n>>x;
    vector<int>h(n);
    vector<int>s(n);
    for(int i=0;i<n;i++){
      cin>>h[i];
    }
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
    vector<vector<int>>dp(x+1,vector<int>(n,-1));
    cout<<func(n-1,x,h,s,dp)<<endl;
 	return 0;
 }
