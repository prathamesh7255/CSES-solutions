#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;
int func(int sum,vector<int>& money,vector<int>& dp){
    if(sum==0){
        return 0;
    }
    if(dp[sum]!=-2) {
        return dp[sum];
    }
    int ans=inf,k;
    for(int i=money.size()-1;i>=0;i--){
        if(sum- money[i]>=0){
            k=func(sum- money[i],money,dp);
            if(k!=-1){
                ans=min(ans,k+1);
            }
            
        }
    }
    if(ans==inf){
        ans=-1;
    }
    return dp[sum]=ans;
}

int main()
 {
 	int n,x;
      cin>>n>>x;
      vector<int>money(n);
      for(int i=0;i<n;i++){
        cin>>money[i];
      }
      vector<int>dp(x+1,-2);
      cout<<func(x,money,dp)<<endl;
 	return 0;
 }