#include<bits/stdc++.h>
using namespace std;

long long func(int ind1,int ind2,vector<int>& num,long long sum,vector<vector<long long>>& dp){
  if(ind1==ind2){
    return sum;
  }
  if(dp[ind1][ind2]!=-1){
    return dp[ind1][ind2];
  }
  sum-=min(func(ind1+1,ind2,num,sum-num[ind1],dp),func(ind1,ind2-1,num,sum-num[ind2],dp));
  return dp[ind1][ind2]=sum;
}

int main()
 {
   int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
      cin>>num[i];
    }
    long long sum=0;
    for(int i=0;i<n;i++){
      sum+=num[i];
    }
    vector<vector<long long>>dp(n,vector<long long>(n,-1));
    cout<<max(func(0,n-1,num,sum,dp), sum-func(0,n-1,num,sum,dp))<<endl;
   return 0;
 }
