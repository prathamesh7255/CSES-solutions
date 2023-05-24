#include<bits/stdc++.h>
using namespace std;

int inf=1e9+7;
int func(int ind1,int ind2,string& s1,string& s2,vector<vector<int>>& dp){
   if(ind1<0){
      if(ind2>=0){
         return ind2+1;
      }
      return 0;
   }
   else if(ind2<0){
      if(ind1>=0){
         return ind1+1;
      }
      return 0;
   }
   if(dp[ind1][ind2]!=-1){
      return dp[ind1][ind2];
   }
   int ans=inf;
   
   if(s1[ind1]==s2[ind2]){
      ans=func(ind1-1, ind2-1,s1,s2,dp);
   }
   else{
      ans=min(ans,func(ind1-1, ind2,s1,s2,dp)+1);
      ans=min(ans,func(ind1,ind2-1,s1,s2,dp)+1);
      ans=min(ans,func(ind1-1,ind2-1,s1,s2,dp)+1);
   }
   return dp[ind1][ind2]=ans;
}

int main()
 {
 	string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<func(n-1,m-1,s1,s2,dp)<<endl;
 	return 0;
 }