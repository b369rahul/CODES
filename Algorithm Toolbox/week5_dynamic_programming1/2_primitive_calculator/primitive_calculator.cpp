#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  if(n==1){
    sequence.push_back(1);
    return sequence;
  }
  int a[n+1];
  a[1]=0;
  a[2]=1;
  a[3]=1;
  sequence.push_back(n);
  for(int i=4;i<n+1;++i){
    if(i%6==0){
      int b=min({a[i-1],a[i/2],a[i/3]});
      a[i]=1+b;
    }
    else if(i%2==0){
      a[i]=1+min(a[i-1],a[i/2]);
    }
    else if(i%3==0){
      a[i]=1+min(a[i-1],a[i/3]);
    }
    else{
      a[i]=1+a[i-1];
    }
  }
  int i=n;
  while(i>1){
    if(i%6==0){
      int b=a[i]-1;
      if(b==a[i-1]){sequence.push_back(i-1);i=i-1;}
      else if(b==a[i/2]){sequence.push_back(i/2);i=i/2;}
      else if(b==a[i/3]){sequence.push_back(i/3);i=i/3;}
    }
    else if(i%2==0){
      if(a[i/2]<=a[i-1]){sequence.push_back(i/2);i=i/2;}
      else if(a[i/2]>a[i-1])sequence.push_back(i-1),i=i-1;
    }
    else if(i%3==0){
      if(a[i/3]<=a[i-1])sequence.push_back(i/3),i=i/3;
      else if(a[i/3]>a[i-1])sequence.push_back(i-1),i=i-1;
    }
    else{
      sequence.push_back(i-1);i=i-1;
    }
  }
  reverse(sequence.begin(),sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
