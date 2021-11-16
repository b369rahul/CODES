#include <iostream>
#include <string>
#include <algorithm>
#define maximum 200
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int a[str2.length()][str1.length()];

  if(str1[0]!=str2[0])a[0][0]=1;
  else a[0][0]=0;

  for(int j=1;j<str1.length();++j){ if(str1[j]==str2[0])a[0][j]=j; else a[0][j]=a[0][j-1]+1;}
  for(int j=1;j<str2.length();++j){ if(str1[0]==str2[j])a[j][0]=j; else a[j][0]=a[j-1][0]+1;}

  int i=1,j=1;
  for(int i=1;i<str2.length();++i){
    for(int j=1;j<str1.length();++j){
    if(str1[j]==str2[i]){
      a[i][j]=min({a[i-1][j-1],a[i][j-1]+1,a[i-1][j]+1});}
    else {
      a[i][j]=min({a[i-1][j-1]+1,a[i][j-1]+1,a[i-1][j]+1});}
    }
  }
  // for(int i=0;i<str2.length();++i){
  //   for(int j=0;j<str1.length();++j){
  //     cout<<a[i][j]<<" ";
  //   }cout<<endl;}

  return a[str2.length()-1][str1.length()-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
