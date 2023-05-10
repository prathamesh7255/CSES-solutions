//Require more optimized solution for this problem

#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n;
      cin>>n;
      int k;
      unordered_set<int>st;
      for(int i=0;i<n;i++){
        cin>>k;
        st.insert(k);
      }
      cout<<st.size()<<endl;
 	return 0;
 }
