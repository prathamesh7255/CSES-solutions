#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7,m;

int func(int k,int ind,vector<int>& a,vector<vector<int>>& dp){
   if(k<1 || k>m){
      return 0;
   }
   if(ind==0){
      if(a[ind]==0 || a[ind]==k){
         return 1;
      }
      return 0;
   }
   if(dp[k][ind]!=-1){
      return dp[k][ind];
   }
   int ans=0;
   if(a[ind]==0 || a[ind]==k){
      ans+=func(k+1,ind-1,a,dp);
   ans%=inf;
   ans+=func(k,ind-1,a,dp);
   ans%=inf;
   ans+=func(k-1,ind-1,a,dp);
   ans%=inf;
   
   }
   return dp[k][ind]=ans;
}

int main()
 {
 	int n;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    int sum=0;
    vector<vector<int>>dp(m+1,vector<int>(n,-1));
    for(int i=1;i<=m;i++){
      sum+=func(i,n-1,a,dp);
      sum%=inf;
    }
    cout<<sum<<endl;
 	return 0;
 }
