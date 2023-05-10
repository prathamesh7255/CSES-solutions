#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n;
    cin>>n;
    vector<int>vec;
    unordered_map<int,int>time;
    int ct=0,x,y,pt=1;
    for(int i=0;i<n;i++){
      cin>>x>>y;
      vec.push_back(y);
      time[y]=max(time[y],x);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
      if(time[vec[i]]>=pt){
         ct++;
         pt=vec[i];
      }
    }
    cout<<ct<<endl;
 	return 0;
 }
