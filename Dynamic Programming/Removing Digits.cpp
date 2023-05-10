#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;

int func(int n,vector<int>& dp){
   if(n==0){
      return 0;
   }
   if(dp[n]!=-1){
      return dp[n];
   }
   int ans=inf,k,copy=n;
   while(copy){
      k=copy%10;
      if(k!=0){
         ans=min(ans,func(n-k,dp)+1);
      }
      
      copy/=10;
   }
   return dp[n]=ans;

}

int main()
 {
 	int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<func(n,dp)<<endl;
 	return 0;
 }