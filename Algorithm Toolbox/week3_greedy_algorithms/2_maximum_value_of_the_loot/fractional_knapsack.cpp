#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<pair<double,int>>v;
  for(int i=0;i<weights.size();++i){
    v.push_back(make_pair((double)values[i]/(double)weights[i],weights[i]));
//    v[i].second=weights[i];
      }
  sort(v.rbegin(),v.rend());
  int i=0;
while(capacity>0){
if(capacity>=v[i].second){
  capacity-=v[i].second;
  //cout<<" "<<v[i].first;
  value+=(v[i].first*v[i].second);}
else{
  value+=(v[i].first*capacity);
  capacity=0;
}
++i;
}
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
