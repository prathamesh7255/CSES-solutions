#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;
int func(int num,int sum,vector<vector<int>>& dp){
  if(num==0){
    return 0;
  }
  if(sum==0){
    return 1;
  }
  if(dp[num][sum]!=-1){
    return dp[num][sum];
  }
  int ans=0;
  if(sum-num>=0){
    ans=func(num-1,sum-num,dp)+func(num-1,sum,dp);
    ans%=inf;
  }
  else{
    ans=func(num-1,sum,dp);
  }
  return dp[num][sum]=ans;

}

int main()
 {
   int n;
    cin>>n;
    long long sum=0;
    sum=n*(n+1);
    sum/=2;
    if(sum%2==1){
      cout<<0<<endl;
    }
    else{
      vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
      cout<<func(n,sum/2,dp)<<endl;
    }
    
   return 0;
 }
