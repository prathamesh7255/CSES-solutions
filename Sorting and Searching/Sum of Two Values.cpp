#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n,x;
    cin>>n>>x;
    multimap<int,int>st;
    int a;
    for(int i=0;i<n;i++){
      cin>>a;
      st.insert({a,i+1});
    }
    auto it1=st.begin();
    auto it2=st.end();
    it2--;
    while(it1->first<=it2->first && it1->second!=it2->second){
      if(it1->first+it2->first==x){
         cout<<it1->second<<" "<<it2->second<<endl;
         return 0;
      }
      else if(it1->first+it2->first>x){
         it2--;
      }
      else{
         it1++;
      }
    }
    cout<<"IMPOSSIBLE"<<endl;
 	return 0;
 }
