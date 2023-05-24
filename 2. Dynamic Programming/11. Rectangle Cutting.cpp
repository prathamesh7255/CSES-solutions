#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;
int func(int a,int b,vector<vector<int>>& dp){
   if(a==1){
      return b-1;
   }
   if(b==1){
      return a-1;
   }
   if(a==b){
      return 0;
   }
   if(dp[a][b]!=-1){
      return dp[a][b];
   }
   int ans=inf,k=inf;
   for(int i=1;i<max(a,b)/2+1;i++){
      if(i<a){
         ans=min(ans,func(a-i,b,dp)+1+func(i,b,dp));
      }
      if(i<b){
         ans=min(ans,func(a,b-i,dp)+1+func(a,i,dp));
      }
   }
   return dp[a][b]=ans;
}

int main()
 {
   int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
    cout<<func(a,b,dp)<<endl;
   return 0;
 }