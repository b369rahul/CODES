#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int optimal_weight(int w, vector<int> &weights) {

  //write your code here
  
  int **ov= new int*[w+1];
  for(int i=0;i<w+1;++i) ov[i]=new int [weights.size()+1];
  for(int i=0;i<=w;++i)ov[i][0]=0;
  for(int j=0;j<=weights.size();++j)ov[0][j]=0;
  
  for(int i=1;i<=w;++i){
    for(int j=1;j<=weights.size();++j){
      if(weights[j-1]>i){ov[i][j]=ov[i][j-1];continue;}
      ov[i][j]=max(ov[i-weights[j-1]][j-1]+weights[j-1],ov[i][j-1]);
    }
  }

  return ov[w][weights.size()];
}

int32_t main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
