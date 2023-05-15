#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n;
      cin>>n;
      vector<pair<int,int>>time;
      int x,y;
      for(int i=0;i<n;i++){
        cin>>x>>y;
        time.push_back({x,1});
        time.push_back({y,-1});
      }
      sort(time.begin(),time.end());
      int ct=0,max_ct=0;
      for(int i=0;i<2*n;i++){
        if(time[i].second==-1){
          max_ct=max(ct,max_ct);
          ct--;
        }
        else{
          ct++;
        }
      }
      cout<<max_ct<<endl;
      
 	return 0;
 }