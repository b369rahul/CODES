#include <iostream>
#include <vector>

using namespace std;
long long inversion =0;

long long get_number_of_inversions(vector<int> &a,vector<int> &b, size_t left, size_t right) {
  //write your code here
  if(left>=right-1)return inversion;
  if(left==right-2){
    if(a[left]>a[left+1]){
    inversion++;swap(a[left],a[left+1]);
    return inversion;}
    }

  int mid=(left+right)/2;

  get_number_of_inversions(a,b,left,mid);
  get_number_of_inversions(a,b,mid,right);

  int i=left,j=mid;
  int t=left;
  // cout<<i<<" ind "<<j<<endl;
  // for(int i=left;i<right;++i){
  //   cout<<a[i]<<" ";
  // }cout<<endl;
  while(1){
  if(i>=mid && j>=right)break;

  while(a[i]<=a[j] && i<mid && j<right){b[t]=a[i];i++;t++;}

  while(a[i]>a[j] && i<mid && j<right){
    b[t]=a[j];j++;t++;
    inversion+=(mid-i); }

  while(i>=mid && j<right){
    b[t]=a[j];j++;t++;
  }

  while(j>=right && i<mid){
    b[t]=a[i];++i;++t;
    //inversion+=mid-i;
  }
  }
  for(int i=left;i<right;++i){
    a[i]=b[i];
   // cout<<a[i]<<" ";
  }//cout<<endl;

  return inversion;  
  }

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a,b,0, a.size()) << '\n';
}
