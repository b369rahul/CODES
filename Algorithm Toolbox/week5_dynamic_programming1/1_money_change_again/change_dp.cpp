#include <iostream>
#include <algorithm>
using namespace std;
int get_change(int m) {
  //write your code here
  int a[m+1];
  a[1]=1;a[0]=0;a[2]=2;a[3]=1;a[4]=1;
  for(int i=5;i<m+1;++i){
    a[i]=1+min(a[i-1],min(a[i-3],a[i-4]));
  }
  return a[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
