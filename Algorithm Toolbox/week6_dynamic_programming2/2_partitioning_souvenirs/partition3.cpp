#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[201][201][201]={0};

int dp_rec(vector<int> &a,int last,int p,int q,int r){
  if(arr[p][q][r]!=0)return arr[p][q][r];
  if(p==0 && q==0 && r==0 && last<0) { arr[p][q][r]=1; return 1;}
  if(last<0){ arr[p][q][r]=-1; return -1;}
  if(a[last]<=p){ 
    arr[p][q][r]=dp_rec(a,last-1,p-a[last],q,r);
    if(arr[p][q][r]==1)return 1;
  }
  if(a[last]<=q){ 
    arr[p][q][r]=dp_rec(a,last-1,p,q-a[last],r);
    if(arr[p][q][r]==1)return 1;
  }
  if(a[last]<=r){ 
    arr[p][q][r]=dp_rec(a,last-1,p,q,r-a[last]);
    if(arr[p][q][r]==1)return 1;
  }
  return -1;
}

int partition3(vector<int> &a,int sum) {
  //write your code here
  sum=sum/3;
  for(int i=0;i<a.size();++i){
    if(a[i]>sum)return 0;
  }
  //return dp_rec(a,a.size()-1,sum,sum,sum);
  if(dp_rec(a,a.size()-1,sum,sum,sum)==1)
    return 1;
  else
    return 0;
}

int32_t main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  int sum=0;
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
    sum+=a[i];
  }
  if(sum%3!=0 || a.size()<3)cout<<0<<endl;
  else
    std::cout << partition3(a,sum) << '\n';
  return 0;
}
