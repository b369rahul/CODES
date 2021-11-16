#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using std::swap;
struct ind{
  int first;
  int second;
};

ind partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int e=l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      //if(a[i]==x)e++;
      swap(a[i], a[j]);
    }
    else if(a[i]==x){
      j++;e++;
      swap(a[j],a[i]);
      swap(a[j],a[e]);
    }
    // else if(a[i]==x && e>=j){
    //   e++;j++;
    //   swap(a[e],a[i]);
    // }
  }
  int t=0;
  while(t<=e-l && t<=j-e){
  swap(a[l+t], a[j-t]);t++;}
  ind s;
  s.first=l+j-e;
  s.second=j;
  //cout<<s->first<<" "<<s->second;
  return s;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  ind s=partition2(a,l,r);
  int first=s.first;
  int second=s.second;

  randomized_quick_sort(a, l, first);
  randomized_quick_sort(a, second+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
