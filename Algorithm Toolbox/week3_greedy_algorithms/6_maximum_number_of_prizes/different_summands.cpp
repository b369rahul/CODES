#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int s=0;
  for(int i=1;i<=n;i++){
    if(s+i>n)break;s+=i;
    summands.push_back(i);
  }int t=n-s+summands.back();
  summands.pop_back();
  summands.push_back(t);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
