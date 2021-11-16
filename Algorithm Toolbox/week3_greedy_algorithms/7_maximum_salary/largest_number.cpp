#include <bits/stdc++.h>
using namespace std;

string largest_number(vector<string> a) {
  //write your code here
  if(a.size()==1)return a[0];
  stringstream ret;
  string result;
  for(int i=0;i<a.size();++i){
    for(int j=i;j<a.size();++j){
      int p=a[i].length(),q=a[j].length();
      int l=0,f=0;
      while(l<p && l<q){
        if(a[i][l]<a[j][l]){f=1;break;}
        if(a[i][l]>a[j][l]){f=2;break;}
        else {l++;}
      }
      if(f!=1 && f!=2){
        if(p>q){int t=0;
          while(1){
            if(a[i][(t+q)%p]>a[j][t%q]){f=0;break;}
            if(a[i][(t+q)%p]<a[j][t%q]){f=1;break;}
            else {t++;
            if(t==p)break; continue;}
          }
        }
      if(p<q){int t=0;
          while(1){
            if(a[i][t%p]>a[j][(t+p)%q]){f=0;break;}
            if(a[i][t%p]<a[j][(t+p)%q]){f=1;break;}
            else {
            t++;
            if(t==q)break;
            continue;}
          }
      }      
      }
      if(f==1) {
        string temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
    ret<<a[i];
  }
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
