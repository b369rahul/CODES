#include <iostream>

int gcd1(int a, int b) {
 if (a==0)return b;
    if (a>=b) return gcd1(a-b,b);
    if (b>a) return gcd1(b-a,a);
    return 1;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd1(a, b) << std::endl;
  return 0;
}
