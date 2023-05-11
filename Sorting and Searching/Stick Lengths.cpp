#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
      cin>>num[i];
    }
    sort(num.begin(),num.end());
    long long cost=0;
    int ind=n/2;
    for(int i=0;i<n;i++){
      if(i<ind){
         cost+=num[ind]-num[i];
      }
      else{
         cost+=num[i]-num[ind];
      }
    }
    cout<<cost<<endl;
 	return 0;
 }
