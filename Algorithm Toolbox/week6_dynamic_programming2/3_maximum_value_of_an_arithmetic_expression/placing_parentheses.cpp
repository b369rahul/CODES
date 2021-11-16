#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
  return 0;
}

int mxm[30][30]={0};
int mnm[30][30]={0};

int minm(string s,int p,int q);
int maxm(string s,int p,int q);

int minm(string s,int p,int q){
  if(mnm[p][q]!=0)return mnm[p][q];
  if(p==q)return s[p]-'0';
  if(q-p==2)return eval(s[p]-'0',s[q]-'0',s[p+1]);

  int i=p+1;
  if(s[i]=='+')
  mnm[p][q] =(s[p]-'0')+minm(s,i+1,q);
  else if(s[i]=='*')
  mnm[p][q]=min({(s[p]-'0')*maxm(s,p+2,q),(s[p]-'0')*minm(s,p+2,q)});
  else if(s[i]=='-')  
  mnm[p][q]=(s[p]-'0')-maxm(s,p+2,q);
  i+=2;
  while(i<q){
  if(s[i]=='+')
  mnm[p][q] =min(minm(s,p,i-1)+minm(s,i+1,q),mnm[p][q]);
  else if(s[i]=='*')
  mnm[p][q]=min({mnm[p][q],minm(s,p,i-1)*maxm(s,i+1,q),minm(s,p,i-1)*minm(s,i+1,q),maxm(s,p,i-1)*minm(s,i+1,q)});
  else if(s[i]=='-')  
  mnm[p][q]=min(mnm[p][q],minm(s,p,i-1)-maxm(s,i+1,q));
  i+=2;
  }
  return mnm[p][q];
}



int maxm(string s,int p,int q){
  if(mxm[p][q]!=0)return mxm[p][q];
  if(p==q)return s[p]-'0';
  if(q-p==2)return eval(s[p]-'0',s[q]-'0',s[p+1]);

  int i=p+1;
  if(s[i]=='+')
  mxm[p][q] =(s[p]-'0')+maxm(s,i+1,q);
  else if(s[i]=='*')
  mxm[p][q]=max({(s[p]-'0')*maxm(s,p+2,q),(s[p]-'0')*minm(s,p+2,q)});
  else if(s[i]=='-')  
  mxm[p][q]=(s[p]-'0')-minm(s,p+2,q);
  i+=2;
  while(i<q){
  if(s[i]=='+')
  mxm[p][q] =max(maxm(s,p,i-1)+maxm(s,i+1,q),mxm[p][q]);
  else if(s[i]=='*')
  mxm[p][q]=max({mxm[p][q],maxm(s,p,i-1)*maxm(s,i+1,q),minm(s,p,i-1)*minm(s,i+1,q)});
  else if(s[i]=='-')  
  mxm[p][q]=max(mxm[p][q],maxm(s,p,i-1)-minm(s,i+1,q));
  i+=2;
  }
  return mxm[p][q];
}

long long get_maximum_value(const string &s) {
  //write your code here

  return maxm(s,0,s.length()-1);
}

int32_t main() {
  
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
