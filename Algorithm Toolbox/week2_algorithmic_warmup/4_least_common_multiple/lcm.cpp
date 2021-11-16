#include <iostream>
#define ll long long
long long lcm_naive(int a, int b) {
 ll l=a;
  if(a>b){
    ll l=a;
    ll i=1;
    while((l*i)%b!=0){
      i++;
    }return (l*i);
  }
else if(b>a){
    ll l=b;
    ll i=1;
    while((l*i)%a!=0){
      i++;
    }return l*i;
  }
  return l;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
