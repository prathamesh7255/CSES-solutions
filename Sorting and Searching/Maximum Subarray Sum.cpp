#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int n;
    cin>>n;
    vector<long long >num(n);
    cin>>num[0];
    long long max_sum=num[0],min_sum=0;
    for(int i=1;i<n;i++){
      cin>>num[i];
      num[i]+=num[i-1];
      max_sum=max(max_sum,num[i]);
    }
    for(int i=0;i<n;i++){
      max_sum=max(max_sum,num[i]- min_sum);
      if(min_sum>num[i]){
         min_sum=num[i];
      }
      
    }

    cout<<max_sum<<endl;
 	return 0;
 }
