#include<bits/stdc++.h>
using namespace std;

void func(int ind,vector<int>& num,set<int>& st){
   if(ind==0){
      st.insert(num[0]);
      return;
   }
   func(ind-1,num,st);
   vector<int>a;
   for(auto it=st.begin();it!=st.end();it++){
      a.push_back(*it+num[ind]);
   }
   st.insert(num[ind]);
   for (int i=0;i<a.size();i++){
      st.insert(a[i]);
   }
}

int main()
 {
 	int n; 
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
      cin>>num[i];
    }
    set<int>st;
    func(n-1,num,st);
    cout<<st.size()<<endl;
    for(auto it=st.begin();it!=st.end();it++){
      cout<<*it<<" ";
    }
    cout<<endl;
 	return 0;
 }
