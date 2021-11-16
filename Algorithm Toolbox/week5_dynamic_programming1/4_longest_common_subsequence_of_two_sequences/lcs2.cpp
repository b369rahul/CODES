#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int na=a.size();
  int nb=b.size();
  int mxm[nb][na];
  if(a[0]==b[0])mxm[0][0]=1;
  else mxm[0][0]=0;
  for(int i=1;i<na;++i){if(a[i]==b[0])mxm[0][i]=1; else mxm[0][i]=mxm[0][i-1];}
  for(int i=1;i<nb;++i){if(a[0]==b[i])mxm[i][0]=1; else mxm[i][0]=mxm[i-1][0];}

  for(int i=1;i<nb;++i){
    for(int j=1;j<na;++j){
      int l=max({mxm[i-1][j-1],mxm[i][j-1],mxm[i-1][j]});
      if(b[i]==a[j] && l==mxm[i-1][j-1])mxm[i][j]=1+l;
      else mxm[i][j]=l;
    }
  }
  // for(int i=0;i<nb;++i){
  //   for(int j=0;j<na;++j){
  //     cout<<mxm[i][j]<<" ";
  //   }cout<<endl;
  // }
  return mxm[nb-1][na-1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
