#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  //write your code here
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  if(left + 2==right){
    if(a[left]==a[left+1])return a[left];
    else return -1;
  }
  int l_major,r_major;
  int mid=(left+right)/2;
  l_major=get_majority_element(a,left,mid);
  r_major=get_majority_element(a,mid,right);  
  if(l_major==r_major)return l_major;
  //cout<<l_major<<" "<<r_major<<" "<<endl;
  int count_r_major=0,count_l_major=0;
  for( int i=left;i<right;++i){
    if(a[i]==l_major)count_l_major++;
    if(a[i]==r_major)count_r_major++;
  }
  if(count_l_major>(right-left)/2)return l_major;
  if(count_r_major>(right-left)/2)return r_major;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())!=-1) << '\n';
}
