#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	    int n,m,k;
      cin>>n>>m>>k;
      vector<int>a(n),b(m);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      for(int i=0;i<m;i++){
        cin>>b[i];
      }
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      auto it1=a.begin();
      auto it2=b.begin();
      int ct=0;
      while(it1!=a.end() && it2!=b.end()){
        if(*it1>*it2){
            if(*it1-*it2<=k){
            ct++;
            it1++;
            it2++;
            }
            else{
                it2++;
            }
        }
        else{
            if(*it2-*it1<=k){
            ct++;
            it1++;
            it2++;
            }
            else{
                it1++;
            }
        }
        
      }
      cout<<ct<<endl;
 	return 0;
 }
