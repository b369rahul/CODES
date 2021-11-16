#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here

  int na=a.size();
  int nb=b.size();
  int nc=c.size();
  int m[na][nb][nc];
  if(a[0]==b[0] && a[0]==c[0]) m[0][0][0]=1;
  else m[0][0][0]=0;
//
for(int i=1;i<na;++i){
  if(a[i]==b[0]&& b[0]==c[0])m[i][0][0]=1;
  else m[i][0][0]=m[i-1][0][0];
}

for(int i=1;i<nb;++i){
  if(b[i]==c[0]&& a[0]==c[0])m[0][i][0]=1;
  else m[0][i][0]=m[0][i-1][0];
}

for(int i=1;i<nc;++i){
  if(c[i]==b[0]&& b[0]==a[0])m[0][0][i]=1;
  else m[0][0][i]=m[0][0][i-1];
}

for(int i=1;i<na;++i){
  for(int j=1;j<nb;++j){
    if(a[i]==b[j] && a[i]==c[0])m[i][j][0]=1;
    else m[i][j][0]=max({m[i-1][j-1][0],m[i-1][j][0],m[i][j-1][0]});
  }
}
//
for(int k=1;k<nc;++k){
  for(int j=1;j<nb;++j){
    if(c[k]==b[j] && c[k]==a[0])m[0][j][k]=1;
    else m[0][j][k]=max({m[0][j-1][k-1],m[0][j][k-1],m[0][j-1][k]});
  }
}
//
for(int i=1;i<na;++i){
  for(int k=1;k<nc;++k){
    if(a[i]==c[k] && a[i]==b[0])m[i][0][k]=1;
    else m[i][0][k]=max({m[i-1][0][k-1],m[i-1][0][k],m[i][0][k-1]});
  }
}
// 
for(int i=1;i<na;++i){
  for(int j=1;j<nb;++j){
    for(int k=1;k<nc;++k){
      int l=max({m[i-1][j][k],m[i][j-1][k],m[i][j][k-1],m[i-1][j-1][k],m[i-1][j][k-1],m[i][j-1][k-1],m[i-1][j-1][k-1]});
      if(a[i]==b[j] && a[i]==c[k]  && l==m[i-1][j-1][k-1]) m[i][j][k]=1+l;
      else m[i][j][k]=l;
    }
  }
}
//
// for(int i=0;i<na;++i){
//   for(int j=0;j<nb;++j){
//     for(int k=0;k<nc;++k){
//       cout<<m[i][j][k]<<" ";
//     }cout<<endl;
//   }cout<<endl;
// }

return m[na-1][nb-1][nc-1];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
