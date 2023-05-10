//Require more optimized solution for this problem

#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&a,int b,int start,int end){
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2,ans,k;
    if(a[mid]>b){
        ans=func(a,b,start,mid-1);
        return ans;
    }
    if(a[mid]==b){
        ans=a[mid];
        a.erase(a.begin()+mid);
        return ans;
    }
    ans=a[mid];
    k=func(a,b,mid+1,end);
    if(k==-1){
        a.erase(a.begin()+mid);
        return ans;
    }
    return k;
}

int main()
 {
 	int n,m,k;
      cin>>n>>m;
      vector<int>a(n),b(m);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      for(int i=0;i<m;i++){
        cin>>b[i];
      }
      sort(a.begin(),a.end());
      vector<int>ans;
      for(int i=0;i<m;i++){
        k=-1;
        if(a.size()>0 && a[0]<=b[i]){
            k=func(a,b[i],0,a.size()-1);
        }
        ans.push_back(k);
      }
      for(int i=0;i<m;i++){
            cout<<ans[i]<<endl;
      }
 	return 0;
 }