#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define int long long
// # ALL MINE

struct cord{
  int x;
  int y;
};
//
bool sortcordx(cord a,cord b){
  if(a.x!=b.x)return a.x<b.x;
   return a.y<b.y;
}
//
bool sortcordy(cord a,cord b){
  if(a.y!=b.y)
  return a.y<b.y;
  return a.x<b.x;
}
//
double calc_d(cord a,cord b){
  return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
//
double merge(vector<cord>c,vector<cord>cy,int ind_xmin,int ind_xmax,int mid,double ans){    
vector<cord>cy_kamke;
cy_kamke.clear();
for(int i=0;i<cy.size();++i){
  if(abs(cy[i].x - c[mid].x )<ans){
    cy_kamke.push_back(cy[i]);
  }}

for(int i=0;i<cy_kamke.size();++i){
  for(int j=i+1;j<cy_kamke.size()&& j<i+9;++j){
    ans=min(ans,calc_d(cy_kamke[i],cy_kamke[j]));
  }}

  return ans;
}
//
double min_d(vector<cord>c,vector<cord>cy,int ind_xmin,int ind_xmax){
  double ans=calc_d(c[ind_xmax],c[ind_xmin]);
  if(ind_xmax==ind_xmin+1)return ans;
  if(c[ind_xmax].x==c[ind_xmin].x){
    for(int i=ind_xmin;i<ind_xmax;++i){
      ans=min(ans,calc_d(c[i],c[i+1]));
    }return ans;
  }
  vector<cord>cy_l;
  vector<cord>cy_r;
  int mid=(ind_xmax + ind_xmin)/2;
  for(int i=0;i<cy.size();++i){
    if(cy[i].x >= c[ind_xmin].x && c[mid].x >= cy[i].x){
    cy_l.push_back(cy[i]);}
    else if(cy[i].x >= c[ind_xmin].x && c[mid].x <= cy[i].x){
      cy_r.push_back(cy[i]);
    }
  }
  
  double ans_1=min_d(c,cy_l,ind_xmin,mid);
  double ans_2=min_d(c,cy_r,mid,ind_xmax);
  ans=min(ans_1,ans_2);
  
  if(ans<=1)return ans;
  
  return merge(c,cy,ind_xmin,ind_xmax,mid,ans);  
}

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  int n=x.size();
  vector<cord>c(n);
  vector<cord>cy(n);
  for(int i=0;i<n;++i){
    c[i].x=x[i];    
    c[i].y=y[i];
    cy[i].x=x[i];    
    cy[i].y=y[i];
  }
  sort(c.begin(),c.end(),sortcordx);
  sort(cy.begin(),cy.end(),sortcordy);
  return min_d(c,cy,0,n-1);
}

int32_t main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
  return 0;
}
