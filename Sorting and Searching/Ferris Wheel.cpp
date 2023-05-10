#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n,x;
      cin>>n>>x;
      vector<int>a(n);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      sort(a.begin(),a.end());
      auto it1=a.begin();
      auto it2=a.end()-1;
      int ct=0;
      while(it1!=it2 && it2+1!=it1){
        if(*it1+*it2>x){
            ct++;
            it2--;
        }
        else{
            ct++;
            it1++;
            it2--;
        }
      }
      if(it1==it2){
        ct++;
      }
      cout<<ct<<endl;
 	return 0;
 }