#include<bits/stdc++.h>
using namespace std;

vector<int> optimal_points(pair<int,int> mp[],int n) {
  vector<int> points;
  
  //write your code here
  sort(mp,mp+n);
  for(int i=0;i<n;i++){
    if(mp[i].first==-1)continue;
    int k=0;
    for(int j=i;j<n;j++){
    if(mp[j].first==-1)continue;
    if(mp[i].first>=mp[j].second){
      k=1;
      if(i!=j){mp[j].first=-1;mp[j].second=-1;}
      }
    }if(k==0)break;
   points.push_back(mp[i].first);mp[i].first=-1;mp[i].second=-1;
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  pair<int,int> mp[n];
  int x,y;
  for (size_t i = 0; i < n; ++i) {
    cin>>x>>y;
    mp[i].first=y;mp[i].second=x;
  }
  vector<int> points = optimal_points(mp,n);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
